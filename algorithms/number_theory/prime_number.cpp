#include<iostream>

using namespace std;

bool prime_num_check (int n){
    if (n <=1) return false;
    if (n==2) return true;
    if (n%2 == 0) return false;

    for (int i=3; i*i<=n; i+=2){
        if (n%i == 0) {
            return false;
        }        
    }

    return true;                  
}

void print_prime_numbers (int n){
    // Flag large number
    if (n>1000) {
        cout << "Provide nuber smaller than 1000" << endl;
    }
    else if (n<0) {
        cout << "Enter Natural numbers: 1, 2, .." << endl;
    }
    else {
        for (int i=0; i<n; i++){
            if (prime_num_check(i)){
                std::cout<< i << std::endl;
            }        
        }
    }
}
 

int main(){
    int n = 100;
    print_prime_numbers(n);

}