/*
Problem Statement:
------------------
Write a recursive function to count the number of items in a list (vector).

Example Usage:
vector<int> v = {3, 7, 1, 9};
cout << count_elements(v) << endl;  
*/

#include <iostream>
#include <vector>
using namespace std;

int count_elements(vector<int>& vec, int i=0){
    // printf(" f(%d)\n", i); // check how recursion is working
    if (i==vec.size()){return 0;}
    return 1 + count_elements(vec, i+1);
}

int main() {
    vector<int> v = {1, 2, 3, 4};
    cout << count_elements(v) << endl;
    return 0;
}
