/*
-------------------- 1D Optimization using Newton's Method --------------------

Minimize a function by solving f'(x) = 0 with Newton iteration:
    x_{n+1} = x_n - f'(x_n) / f''(x_n)

Derivatives are computed numerically:
- First derivative: forward difference
- Second derivative: central difference

Test function: 1D Beale function
Expected minimum near x = 3
*/

#include<iostream>

using namespace std;

// expected min; x = 3
inline double beale1D(double x){
    return (1.5   - 0.5*x)*(1.5   - 0.5*x)
         + (2.25  - 0.75*x)*(2.25  - 0.75*x)
         + (2.625 - 0.875*x)*(2.625 - 0.875*x);
}

// Function definition: use Beale 1D as the target function f(x)
inline double func(double x){
    return beale1D(x);
}

// 1st derivative (numerical, forward difference)
inline double f1x(double x, double delx){    
    return (func(x + delx) -func(x))/delx;
}

// 2nd derivative (numerical, central difference) — not used
inline double f2x(double x, double delx){ 
    return (func(x + delx) -2*func(x) + func(x - delx))/(delx*delx);
}

inline double optimizefx(double& initial_guess, double& tol, double& delx){
    double x = initial_guess;
    int count = 0;
    const int max_iter = 100; // for safety

    while(abs(f1x(x, delx))>tol && count < max_iter){
        count++;
        if (std::abs(f2x(x, delx)) < 1e-12) {
            std::cerr << "Zero curvature — Newton step undefined\n";
            break;
        }
        x += -f1x(x, delx)/f2x(x, delx);

        // cout << x << "  " << f1x(x,delx) << "\n";
    }
    cout << "Steps to optimization = " << count << "\n";
    return x;
}


int main(){
    double guess = 1;   // starting value
    double tol = .0001;   // tolerance
    double delx = .001;  // step for derivative

    double xmin = optimizefx(guess, tol, delx);

    cout << " f_min: x_min = " << xmin << endl;
}