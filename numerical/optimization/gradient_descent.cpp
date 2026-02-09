
/*
------------- GD vs GDM vs Nesterov (NAG): Conceptual Comparison -------------

1) Plain Gradient Descent (GD)
   x_{t+1} = x_t − η ∇f(x_t)

- Uses only the current gradient.
- No memory of past steps.
- Can be slow in narrow valleys and noisy with stochastic gradients.
- Step direction changes abruptly from iteration to iteration.

2) Gradient Descent with Momentum (GDM)
   v_t = γ v_{t−1} + η ∇f(x_t)
   x_{t+1} = x_t − v_t

- Adds a velocity term (running average of past gradients).
- Builds speed in consistent directions.
- Reduces oscillations.
- Gradient is still evaluated at the current position x_t.
- May overshoot since it reacts after moving.
- campare with particle velocity in viscous medium

3) Nesterov Accelerated Gradient (NAG)
   v_t = γ v_{t−1} + η ∇f(x_t − γ v_{t−1})
   x_{t+1} = x_t − v_t

- Computes gradient at a look-ahead point.
- Anticipates where momentum will take the parameters.
- Corrects direction earlier than standard momentum.
- Usually more stable and converges faster near minima.

Intuition:
- GD:        no memory, follows local slope only.
- Momentum:  remembers past gradients, moves like a heavy ball.
- NAG:       looks ahead before updating, then corrects the step.
*/

#include<iostream>

using namespace std;

const int max_iter = 2000; // for safety

// Control parameters (check that effectiveness of GDM and NAG depends on the choice of eta!)
const double eta = .002; // learning rate
const double gamma = 0.8; // momentum tuning parameter

// expected min; x = 3
inline double beale1D(double x){
    return (1.5   - 0.5*x)*(1.5   - 0.5*x)
         + (2.25  - 0.75*x)*(2.25  - 0.75*x)
         + (2.625 - 0.875*x)*(2.625 - 0.875*x);
}

// expected min; x = 1
inline double func2(double x){
    return x*x-2*x+1;
}

// Function definition: use Beale 1D as the target function f(x)
inline double func(double x){
    return beale1D(x);
}

// 1st derivative (numerical, forward difference)
inline double f1x(double x, double delx){    
    return (func(x + delx) -func(x))/delx;
}

// ---------------- Standard Gradient Descent ----------------
inline double gd(double& initial_guess, double& tol, double& delx, const double& eta){
    double x = initial_guess;
    int count = 0;

    while(abs(f1x(x, delx))>tol && count < max_iter){
        count++;
        // if (std::abs(f2x(x, delx)) < 1e-12) {
        //     std::cerr << "Zero curvature — Newton step undefined\n";
        //     break;
        // }
        x += -eta*f1x(x, delx);

        // cout << x << "  " << f1x(x,delx) << "\n";
    }
    cout << "Steps to optimization (GD) = " << count << "\n";
    return x;
}

// ---------------- Gradient Descent with Momentum ----------------
double gdm(double& initial_guess, double& tol, double& delx, const double& eta, const double& gamma){
    double x = initial_guess;
    double v = 0.0;          // momentum (velocity)
    double grad = f1x(x, delx);

    int count = 0;

    while(abs(f1x(x, delx))>tol && count < max_iter){
        // if (std::abs(f2x(x, delx)) < 1e-12) {
        //     std::cerr << "Zero curvature — Newton step undefined\n";
        //     break;
        // }

        v = gamma*v + eta*grad;
        x -= v;

        grad = f1x(x, delx);

        count++;
        // cout << x << "  " << f1x(x,delx) << "\n";
    }
    cout << "Steps to optimization (GDM) = " << count << "\n";
    return x;
}

// ---------------- NAG ----------------
double nag(double& initial_guess, double& tol, double& delx, const double& eta, const double& gamma){
    double x = initial_guess;
    double v = 0.0;          // momentum (velocity)
    double grad = f1x(x, delx);

    int count = 0;

    while(abs(f1x(x, delx))>tol && count < max_iter){
        // if (std::abs(f2x(x, delx)) < 1e-12) {
        //     std::cerr << "Zero curvature — Newton step undefined\n";
        //     break;
        // }

        // gradient at look-ahead position
        grad = f1x(x - gamma*v, delx);

        // velocity update
        v = gamma*v + eta*grad;

        // parameter update
        x -= v;

        

        count++;
        // cout << x << "  " << f1x(x,delx) << "\n";
    }
    cout << "\nSteps to optimization (NAG) = " << count << "\n";
    return x;
}

int main(){
    double guess = 2;   // starting value
    double tol = .0001;   // tolerance
    double delx = .01;  // step for derivative

    double xmin = gd(guess, tol, delx, eta);
    cout << " f_min: x_min = " << xmin << "\n" << endl;

    xmin = gdm(guess, tol, delx, eta, gamma);
    cout << " f_min: x_min = " << xmin << endl;

    xmin = nag(guess, tol, delx, eta, gamma);
    cout << " f_min: x_min = " << xmin << endl;
}