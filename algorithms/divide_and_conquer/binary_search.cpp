#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

// Loop
int binary_search_loop(vector<int> A, int item){
    if (A.empty()) {
        cerr << "Error: binary_search called with an empty vector." << endl;
        return -1;
    }


    int n = A.size();
    int highIdx = n-1;
    int lowIdx = 0; 
    int midIdx = 0;
    int guess = A[midIdx];
    int count=0;

    while (lowIdx<=highIdx){
        // printf("--- count = %d ---\n", count++);
        midIdx = (highIdx+lowIdx)/2;
        guess = A[midIdx];
        // printf("mid = %d,  guess = %d\n", midIdx, guess);

        if (guess==item){
            // printf("The item found and \n");
            return guess;         
        }
        
        else if (guess>item){
            highIdx = midIdx -1; 
            printf("high = %d\n", highIdx);         
        }

        else {  // if (guess<item)
            lowIdx = midIdx +1;     
            // printf("low = %d\n", lowIdx);
     
        }  
    }

    // Item not found
    cerr << "[binary_search] Warning: item " << item
         << " not found in array." << endl;
    return -1;
}

// Recursive
int binary_search_recursive(const vector<int>& v, int item, int low, int high) {
    // Base case: search space exhausted
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (v[mid] == item)
        return mid;
    else if (item < v[mid])
        return binary_search_recursive(v, item, low, mid - 1);
    else
        return binary_search_recursive(v, item, mid + 1, high);
}




int main(){
    vector<int> v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }

    // for (int i=0; i<v.size(); i++){
    //     cout<< v[i] << " ";
    // }
    // cout << endl;


cout << "Iterative binary search (7): "
     << binary_search_loop(v, 7) << endl;

int idx = binary_search_recursive(v, 7, 0, v.size() - 1);
cout << "Recursive binary search (7): "
     << idx << endl;



}