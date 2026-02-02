#include<iostream>
#include<vector>

using namespace std;

vector<int> quick_sort(vector<int>& v){
    // int n = v.size()
    if(v.size()<2){
        return v;
    }

    int pivot = v[int(v.size()/2)];
    
    vector<int> less_arr;
    vector<int> equal_arr = {pivot};
    vector<int> greater_arr;

    for (int i=0; i<v.size(); i++){
        if (i==int(v.size()/2)){
            continue;
        }

        if (v[i]<=pivot){
            less_arr.push_back(v[i]);
        }
        else if (v[i]>pivot){
            greater_arr.push_back(v[i]);
        }
    }

    vector<int> left  = quick_sort(less_arr);
    vector<int> right = quick_sort(greater_arr);

    left.insert(left.end(), equal_arr.begin(), equal_arr.end());
    left.insert(left.end(), right.begin(), right.end());

    return left;
}




int main(){
    vector<int> v = {6, 8, 1, 15, 2};
    vector<int> A = quick_sort(v);
    for (int i=0; i<A.size(); i++){
       cout<< A[i] << " ";
    }
    cout<<endl;



}
