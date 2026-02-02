#include <iostream>
#include <cstdio>

using namespace std;

// Calculate Power of an integer
int  power_recursive(int a, int n){
    if(n==0){
        return 1;
    }
    else{
        return a*power_recursive(a, n-1);
    }
}

int main(){
    int a = 10;
    int n = 3;
    printf("a^n = %d\n", power_recursive(a, n));
}