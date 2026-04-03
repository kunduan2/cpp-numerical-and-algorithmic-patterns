/*
Key rules demonstrated:
  1. An array name decays to a pointer to its first element
  2. p[i] and *(p+i) are identical — pointer arithmetic
  3. &A[0], A, and p all hold the same address
  4. Functions receive a pointer, not a copy of the array
*/

#include <iostream>
#include <string>
using namespace std;

int sum (int* p){
    int sum = 0;
    for (int i=0; i!=3; i++){
        sum += p[i]; // or equivalently *(p+i);
    }
    return sum;
}

int main(){
    int A[] = {1, 2, 3};
    
    cout << " A = {";
    for(int i=0; i<3; i++){
        cout << " " << A[i] ;
    }
    cout <<  "}\n";
    
    int* p = A; // p holds the address of A[0] — no copy made

    // ── 1. Array vs pointer element access 
    // p[i] and A[i] are same although p is a ptr!
    cout << " Important syntax.  Check p[i] = A[i] (Note:  p is a ptr!):"   << "\n";
    cout << " p[1] = " << p[1]  << "\n";
    cout << " A[1] = " << A[1]  << " (same — p is just a pointer to A[0]) \n";  
    
    // ── 2. Addresses: p, A, &A[0] all equal 
    // &A and &A[0] print the same value but have different types:
    //   &A[0]  →  int*      (pointer to one int)
    //   &A     →  int(*)[3] (pointer to the whole array of 3 ints)
    cout << "\n Check p = A (so A can be taken as agument of the function ):" << "\n";
    cout << " p = " << p << "\n";
    cout << " A = " << A  << "\n";  

    // using & operator directly
    cout << "\nCheck p = A = &A[0] = &A: "    << "\n";  
    cout << " " << &A[0]  << "\n";
    cout << " " << &A  << "\n";

    // ── 3. Pointer arithmetic
    // p+1 advances by sizeof(int) bytes, not by 1 byte
    cout << "\n── Pointer arithmetic ──────────────────────────\n";
    for (int i = 0; i < 3; i++)
        cout << "  *(p+" << i << ") = " << *(p + i)
             << "  ==  p[" << i << "] = " << p[i] << "\n";

    // ── 4. Passing array to function
    // A decays to int* at the call site — only the address is passed
    cout << "\n── Function call ───────────────────────────────\n";
    cout << "\nSummation of All elemetns of A = " << sum(A) << "\n";

    return 0; 
}