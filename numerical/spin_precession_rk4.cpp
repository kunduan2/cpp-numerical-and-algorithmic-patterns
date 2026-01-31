/*
Problem Statement
-----------------
Solve the classical spin precession equation

    d m / dt = γ ( m × H )

where m(t) ∈ ℝ³ is the magnetization (spin) vector, γ is the gyromagnetic
ratio, and H is a prescribed effective magnetic field.

The task is to numerically integrate this ordinary differential equation
using the explicit fourth-order Runge–Kutta (RK4) method in C++.

Assumptions:
- The magnetic field H is time-independent.
- The magnetic field H is oriented along the z-axis.
- The magnetization is treated as a classical vector.
- |m| = 1, i.e., m is a unit vector.
- The initial magnetization m(0) is given.
- No damping term is included (this is NOT the Landau–Lifshitz–Gilbert equation).
- Time integration is performed over a fixed interval with uniform time step Δt.

Objectives:
- Implement a self-contained RK4 solver for the spin precession equation.
- Evolve the magnetization vector in time.
- Output m(t) for post-processing or visualization.
- Demonstrate numerical solution of pure Larmor precession.

Additional:
- Set coeff > 0 to introduce an external random magnetic field and study its
  effect on the dynamics.
- This stochastic field is not physically motivated in the absence of damping
  and is used only for numerical experimentation.

This file is intended as a minimal, standalone numerical example suitable
for educational use and for showcasing numerical ODE integration in C++.
*/



#include <iostream>
#include <fstream>
#include <cmath>
#include <random>   // For Gaussian noise
using namespace std;

// Physical parameters for LLG
const double gamma_gyro = 1.0;
// const double alpha = 0.1;
// const double prefactor = -gamma_gyro / (1.0 + alpha*alpha);

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
    double coeff = 1.0;
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

    // Combine precession and damping
    dmx = gamma_gyro * cross_x;
    dmy = gamma_gyro * cross_y;
    dmz = gamma_gyro * cross_z;
}



int main() {
    // start time 
    double t = 0.0; 

    // initial condition: magnatization component at t=0.0
    double mx = 1.0, my = 0.0, mz = 0.0;
    normalize(mx, my, mz);

    // --- compute K's at stage times (exact RK4 bookkeeping) ---
    double k1x,k1y,k1z, k2x,k2y,k2z, k3x,k3y,k3z, k4x,k4y,k4z;    

    ofstream fout("numerical/spin_precession.dat");
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

        // normalize(mx, my, mz);
        t += dt;
        fout << t << " " << mx << " " << my << " " << mz << "\n";
    }

    fout.close();

    printf("Successfully complied.\n");
    printf("Analyze data from: 'analysis/plot.py'.\n");
    printf("Make the value of coeff>0 and see the effects of random field. \n");
    return 0;
}
