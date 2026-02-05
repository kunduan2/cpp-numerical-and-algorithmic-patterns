#include<iostream>
#include<random>

using namespace std;

const int N = 100;
int count = 0;

int main(){
    std::random_device rd; // Instantiate the class
    unsigned int seed = rd(); // seed: Use the () operator to get one truly random number. Rtype: unsigned int

    std::mt19937 engine(seed); // Seed initializes ("kickstarts") the mt19937 random number engine;
    //  using a new seed each run produces a different random sequence

    /* 
    std::mt19937; It is an object of the Mersenne Twister class (a random number engine), not a number.
    engine();   // produces a pseudo-random number 
    */

    std::uniform_real_distribution<double> dist(0.0, 1.0);
    /*
    - std::uniform_int_distribution<int> :    A C++ standard library class that generates integers.
    - “uniform” means every value has equal probability.
    - <int> means the output type will be int.
    - other dists:     std::uniform_int_distribution<int> dist(1, 10);
    */

    for (int i=0; i<N; i++){
        // std::cout<< dist(engine) << " "; 
        
        double x = dist(engine); 
        double y = dist(engine);
        if (x*x+y*y<1.0){
            count++;
        } 
    }   
    double pi = 4.0*count/N;
    cout<< "\n\nPi = " << pi << " \n"; 
}


