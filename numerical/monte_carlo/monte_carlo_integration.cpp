#include <iostream>
#include <cstdio>
#include <random>

using namespace std;

double func(double x){
    return x + 2*x*x;
}

double MonteCarlo(double a, double b){
    int n = 1000;

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



int main(){

    printf("The integration is = %f\n", MonteCarlo(0, 2.0));

    return 0;
}
