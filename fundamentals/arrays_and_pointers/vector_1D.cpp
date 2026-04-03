/*
1D-vectors

Regular array          vector
──────────────         ──────────────────────────────
fixed size             grows automatically
stack or heap          heap (managed for you)
no bounds check        .at(i) checks bounds
size lost on pass      always knows its size
manual delete[]        automatic cleanup
*/

#include <iostream>
#include <vector>

using namespace std;

// read-only — const reference (no copy, no modify)
void print(const vector<int>& v) {
    // cout << "Printing vector/array:\n";
    for (int x : v)
        cout << x << " ";
    cout << "\n";
}

// modify in place — reference
void doubleAll(vector<int>& v) {
    cout << "Making double:\n";
    for (int& x : v)    // int& — reference to each element
        x *= 2;
}

// return a new vector
vector<int> makeSquares(int n) {
    cout << "return a new vector:\n";
    vector<int> result;
    for (int i = 1; i <= n; i++)
        result.push_back(i * i);
    return result;    // no pointer, no new, no delete
}

// cout << " " <<   << "\n"; 
int main(){
    // --------------------------------------------------------------------------------
    // Creating and accessing
    // --------------------------------------------------------------------------------
    cout << "Creating and accessing:\n";
    vector<int> v1;                      // empty
    vector<int> v2(5);                   // 5 zeros
    vector<int> v3(5, 42);               // {42,42,42,42,42}
    vector<int> v4 = {10, 20, 30, 40};   // initializer list

    // access — two ways (uncomment and try)
    // cout << " " << v4[4]  << "\n";        // fast, no bounds check (undefined if out of range). Need to use it!
    // cout << " " << v4.at(4)  << "\n";  // 20 — safe, throws exception if out of range

    // size
    cout << "size of v4: " << v4.size() << "\n";        // number of elements in the vector
    cout << "empty of v4: " << v4.empty() << "\n";      // 1 (true) if empty, 0 (false) otherwise
    cout << "front of v4: " << v4.front() << "\n";      // first element of the vector
    cout << "back of v4: " << v4.back() << "\n";        // last element of the vector

    // --------------------------------------------------------------------------------
    // Iterating
    // --------------------------------------------------------------------------------
    cout << "\nIterating:\n";
    vector<int> v = {10, 20, 30, 40};

    // range-based for (cleanest)
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    // index-based (when you need i)
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n"; 

    // iterator (good to know exists)
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << "\n";
    
    // --------------------------------------------------------------------------------
    // Modifying
    // --------------------------------------------------------------------------------
    cout << "\nModifying:\n";
    cout << "Array:\n";
    
    vector<int> v5 = {10, 20, 30};
    for (int x:v5) cout << x << " ";
    cout << "\n";

    // add / remove at end — O(1) fast
    v5.push_back(40);           // {10,20,30,40}
    v5.pop_back();              // {10,20,30}

    // insert at position — O(n) slow (shifts elements)
    v5.insert(v.begin()+1, 99);   // {10,99,20,30}  insert at index 1

    // erase at position — O(n) slow
    v5.erase(v.begin()+1);        // {10,20,30}  remove index 1

    // resize
    v5.resize(5);            // {10,20,30,0,0}   grows with zeros
    v5.resize(2);            // {10,20}          shrinks

    // clear everything
    v5.clear();              // {}  size = 0
    
    cout << "Check code for more info.\n";
    
    // --------------------------------------------------------------------------------
    //  Passing to functions
    // --------------------------------------------------------------------------------
     cout << "\nPassing to functions:\n";
     cout << "Array:\n";
    vector<int> v6 = {1, 2, 3, 4, 5};
    print(v6);                    // 1 2 3 4 5
    doubleAll(v6);
    print(v6);                    // 2 4 6 8 10

    vector<int> sq = makeSquares(5);
    print(sq);                   // 1 4 9 16 25
}