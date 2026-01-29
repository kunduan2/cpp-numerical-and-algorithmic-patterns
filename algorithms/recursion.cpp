/*
 * recursion.cpp
 *
 * Purpose:
 *   Collection of simple recursive functions implemented for learning
 *   and experimentation. Current implementations include:
 *     - Recursive sum of the emements of a vector
 *     - Factorial
       - Power of an integer
 
 * Status:
 *   Actively evolving. New recursive examples and refinements will be added
 *   as concepts are studied.
 */




#include <iostream>
#include <cstdio>
#include<vector>
#include <stdexcept>
using namespace std;

#include <cmath>




// Recursive-Sum of the elemetns of a vector 
int sum(vector<int> p, int n){
    if (n==0){return 0;}
    else{
        return p[n-1] + sum(p, n-1);
    }
}

// Factorial (!)
long long factorial(int n){
    if (n<0){  // Input validation
        throw invalid_argument("n must be non-negative");
    }

    else if (n<=1) return 1;

    else if(n>20){ // Overthrow error
        throw overflow_error("Factorial too large for long long");
    }

    else {
        // printf("n = %d \n", n);
        return n*factorial(n-1);
    }
}

// Fibonacci sequence
long long fibonacci (int n){
    if (n<0) throw invalid_argument("n must be non-negative");
    else if (n<=1) return 1;
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// Calculate Power of an integer
int pow(int a, int n){
    if(n==0){
        return 1;
    }
    else{
        return a*pow(a, n-1);
    }
}
