#include <iostream>
using namespace std;

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

int main(){
    long long n = 10;
    printf("factorial(%lld) = %lld\n", n, factorial(n));
}