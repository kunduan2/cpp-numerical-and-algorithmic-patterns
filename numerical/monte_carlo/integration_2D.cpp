/*
Example target: f(x,y) = x² + y² over [0,1] × [0,1], exact answer = 2/3 ≈ 0.6667

Error: decays as O(1/√n) regardless of dimension — this is Monte Carlo's key advantage over
 Simpson's rule in high dimensions
 (Simpson's error grows with dimension, Monte Carlo's doesn't).
*/


#include <iostream>
#include <random>
#include <cstdio>

using namespace std;

double func(double x, double y){
    return (x*x + y*y);
}

double monte_carlo_2D(double a, double b, double c, double d, int n){
    random_device rd;
    unsigned int seed = rd();
    mt19937 engine(seed);
    uniform_real_distribution<double> distx(a, b);
    uniform_real_distribution<double> disty(c, d);

    double sum = 0;

    for (int i=0; i<n; i++){
        double x = distx(engine);
        double y = disty(engine);
        sum += func(x, y);
    }
    
    return sum*(b-a)*(d-c)/n ;

}

int main(){

     printf("The integration is = %f\n", monte_carlo_2D(0, 1.0, 0, 1.0, 1000));


    return 0;
}