#include<iostream>
#include<vector>
#include<random>

using namespace std;

void bubblesort(vector<int>& A){
    int n = A.size();
    int tmp=0;
    for (int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if (A[j] > A[j+1]){
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp; 
            }
        }
    }
}

int main(){
    //generate a vector using RNG
    std::random_device my_rd;
    unsigned int my_seed = my_rd();

    // RNG engine and distribution
    std::mt19937 my_rng_engine(my_seed);
    std::uniform_int_distribution<int> my_dist(1, 20);

    //define an empty vector
    vector<int> V;
    int n = 10;
    
    // Add elements using RNG engine
    for (int i=0; i<n; i++){
        V.push_back(my_dist(my_rng_engine));
        cout<< V[i] << " ";
    }
    cout<< endl;

    // Sort the array
    bubblesort(V);
    
    // Print the array
    for (int i=0; i<n; i++){
        cout<< V[i] << " ";
    }
    cout<< endl;
   

}