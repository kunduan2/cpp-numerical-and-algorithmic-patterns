#include <iostream>
using namespace std;

// Fibonacci sequence
long long fibonacci (int n){
    if (n<0) throw invalid_argument("n must be non-negative");

    else if (n<=1) return 1;

    else if(n>40){
        throw overflow_error("n too large for long long");
    }

    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}


int main(){
    long long n = 45;
    printf("fibonacci(%lld) = %lld\n", n, fibonacci(n));
}