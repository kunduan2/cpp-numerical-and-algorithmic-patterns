/*
Problem Statement:
------------------
Simulate the time evolution of a single classical magnetization vector m(t)
subject to an effective magnetic field using the Landau–Lifshitz–Gilbert
(LLG) equation.

The LLG equation is given by:
dm/dt = -γ / (1 + α²) [ m × H_eff + α m × ( m × H_eff ) ]

where:
  - m(t) is the normalized magnetization vector with |m| = 1
  - γ is the gyromagnetic ratio
  - H_eff is the effective magnetic field
  - α is the Gilbert damping parameter

The dynamics includes:
  1) Precessional motion of the magnetization around the effective field
  2) Gilbert damping, which relaxes the magnetization toward the field direction

The LLG equation is integrated numerically using the fourth-order
Runge–Kutta (RK4) method to ensure stability and accuracy of the time
evolution.

This implementation serves as a minimal numerical example for magnetization
dynamics and spin precession in micromagnetics and spintronics.

Method:
  - Classical magnetization vector m(t) with |m| = 1
  - Time integration via RK4
  - Output of the magnetization trajectory for post-processing and visualization
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <random>   // For Gaussian noise
using namespace std;

// Physical parameters for LLG
const double gamma_gyro = 1.0;
const double alpha = 0.1;
const double prefactor = -gamma_gyro / (1.0 + alpha*alpha);

// Time-loop parameters
const double dt = 0.01;
const int N = 10000;

// External field (unitless)
const double Hx = 0.0;   
const double Hy = 0.0;   
const double Hz = 0.7;   

// Random number generator for Gaussian noise
std::mt19937 gen(42); // Fixed seed for reproducibility
std::normal_distribution<double> gauss(0.0, 1.0); // Standard normal

// normalize
void normalize(double &mx, double &my, double &mz)
{
    double n = sqrt(mx*mx + my*my + mz*mz);
    mx /= n; my /= n; mz /= n;
}

// Function to compute time derivatives of magnetization 
void dmdt(double mx, double my, double mz,
          double Hx, double Hy, double Hz,
          double &dmx, double &dmy, double &dmz) {
    
    // To check the role of noise change coeff from 0 to 1 or other vals
    double coeff = 0;
    double eta_x = coeff*gauss(gen);
    double eta_y = coeff*gauss(gen);
    double eta_z = coeff*gauss(gen);

    // Total field including stochastic term
    double Htot_x = Hx + eta_x;
    double Htot_y = Hy + eta_y;
    double Htot_z = Hz + eta_z;

    // Compute m × Htot (precession term)
    double cross_x = my*Htot_z - mz*Htot_y;  
    double cross_y = mz*Htot_x - mx*Htot_z;  
    double cross_z = mx*Htot_y - my*Htot_x;  

    // Compute m × (m × Htot) = m(m.Htot)-Htot(using  m^2=1) (damping term)
    double m_dot_H = mx*Htot_x + my*Htot_y + mz*Htot_z;
    double double_cross_x = Htot_x - m_dot_H * mx;
    double double_cross_y = Htot_y - m_dot_H * my;
    double double_cross_z = Htot_z - m_dot_H * mz;

    // Combine precession and damping
    dmx = prefactor * (cross_x + alpha * double_cross_x);
    dmy = prefactor * (cross_y + alpha * double_cross_y);
    dmz = prefactor * (cross_z + alpha * double_cross_z);
}

int main() {
    // start time 
    double t = 0.0; 

    // initial condition: magnatization component at t=0.0
    double mx = 1.0, my = 0.0, mz = 0.0;
    normalize(mx, my, mz);

    // --- compute K's at stage times (exact RK4 bookkeeping) ---
    double k1x,k1y,k1z, k2x,k2y,k2z, k3x,k3y,k3z, k4x,k4y,k4z;    

    ofstream fout("numerical/llg_spin_dynamics_rk4.dat");
    fout << t << " " << mx << " " << my << " " << mz << "\n";

    for (int i = 0; i < N; i++) {
        
        // RK4 stages (pass stage H into dmdt)
        dmdt(mx, my, mz, 
            Hx, Hy, Hz, k1x,k1y,k1z);

        dmdt(mx + 0.5*dt*k1x, my + 0.5*dt*k1y, mz + 0.5*dt*k1z,
             Hx, Hy, Hz, k2x, k2y, k2z);

        dmdt(mx + 0.5*dt*k2x, my + 0.5*dt*k2y, mz + 0.5*dt*k2z,
             Hx, Hy, Hz, k3x,k3y,k3z);

        dmdt(mx + dt*k3x, my + dt*k3y, mz + dt*k3z,
             Hx, Hy, Hz, k4x,k4y,k4z);

        mx += dt/6.0*(k1x + 2*k2x + 2*k3x + k4x);
        my += dt/6.0*(k1y + 2*k2y + 2*k3y + k4y);
        mz += dt/6.0*(k1z + 2*k2z + 2*k3z + k4z);
        
        // Normalize the updated magnetization
        normalize(mx, my, mz);

        t += dt;
        fout << t << " " << mx << " " << my << " " << mz << "\n";
    }

    fout.close();

    printf("Successfully compiled.\n");
    printf("Analyze data from: 'analysis/plot.py'. Change data = .../llg_spin_dynamics_rk4.dat \n");
    printf("To see the effects of random field: make the value of coeff>0 \n");

    return 0;
}
