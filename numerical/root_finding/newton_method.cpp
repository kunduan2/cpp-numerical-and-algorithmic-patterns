/*
-------------------- Solve equation: f(x) = 0 ---------------------------------------
Newton's Method

Goal:
Find a root of the nonlinear equation f(x) = 0 using Newton's iteration:
    x_{n+1} = x_n - f(x_n)/f'(x_n)

The first derivative is approximated numerically using a forward difference.
A second derivative function is also provided (central difference), though
it is not used in the solver.
*/

#include<iostream>

using namespace std;

// Function definition: f(x) = x^3 - 2x + 1
inline double func(double x){
    return x*x*x -2*x + 1;
}

// 1st derivative (numerical, forward difference)
inline double f1x(double x, double delx){    
    return (func(x + delx) -func(x))/delx;
}

// 2nd derivative (numerical, central difference) — not used
inline double f2x(double x, double delx){ 
    return (func(x + delx) -2*func(x) + func(x - delx))/(delx*delx);
}

// Newton iteration to find the root
double solvefx(double& initial_guess, double& tol, double delx){
    double x = initial_guess;
    int count = 0;

    // Iterate until f(x) is within tolerance
    while(func(x)>tol && count<20){
        count++;
        x += -func(x)/f1x(x, delx); // Newton update step
        // cout << count << " " << x << "\n";
    }
    return x;
}

int main(){
    double guess = 3;   // starting value
    double tol = .01;   // tolerance
    double delx = .01;  // step for derivative

    cout << "Solution: x = " << solvefx(guess, tol, delx) << endl;
}