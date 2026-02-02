/*
Problem: Largest Square Plot (Euclid’s Algorithm)

Description:
------------
You are given a rectangular farm of dimensions L × W. The goal is to divide the
farm into the largest possible number of identical square plots such that the
entire farm is covered without overlap or leftover area.

This problem can be solved using a divide-and-conquer approach based on
Euclid’s algorithm for computing the greatest common divisor (GCD).

Input:
------
Two positive integers L and W representing the length and width of the farm.

Output:
-------
An integer representing the side length of the largest possible square plot.

Example:
--------
Input:
L = 168, W = 64

Output:
8

Explanation:
------------
The largest square that can evenly tile a 168 × 64 rectangle has side length
gcd(168, 64) = 8.
*/

#include <iostream>
#include <cstdio>
// #include<vector>
// #include <stdexcept>
#include <cmath>

using namespace std;

// Recursive function implementing Euclid's algorithm
int largest_square(int L, int W){
    if (L%W==0){
        return W;
    }
    // cout<< c << " ";
    return largest_square(W, L%W);
}


// // Loop implementation Euclid's algorithm
// int largest_square(int L, int W){
//     int count = 0;
//     int c = 0;
//     while(L%W !=0 && count<30){
//         c = L%W;
//         cout<< c << " loop";
//         L = W;
//         W = c;

//         count++;
//     }
    
//     return c;
// }

int main(){
    
    printf("Side of largest square = %d\n", largest_square(168, 64));

    
    return 0;
}