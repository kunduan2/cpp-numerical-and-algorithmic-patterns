#include <iostream>
#include <cstdio>
#include <random>

using namespace std;

double func(double x){
    return x + 2*x*x;
}

double MonteCarlo(double a, double b){
    int n = 10000;

    random_device rd;
    unsigned int seed = rd();
    mt19937 engine(seed);
    uniform_real_distribution<double> dist(a, b);

    double sum = 0;

    for (int i=0; i<n; i++){
        double x = dist(engine);
        sum += func(x);
    }
     
    return sum*(b-a)/n ;
}



// n must be even; uses composite Simpson's 1/3 rule
double Simpson(double a, double b, int n = 1000){
    if (n % 2 != 0) n++;
    double h = (b - a) / n;
    double sum = func(a) + func(b);

    for (int i = 1; i < n; i++){
        double x = a + i * h;
        sum += (i % 2 == 0 ? 2 : 4) * func(x);
    }

    return sum * h / 3.0;
}

int main(){

    printf("Monte Carlo   = %f\n", MonteCarlo(0, 2.0));
    printf("Simpson rule  = %f\n", Simpson(0, 2.0));

    return 0;
}
