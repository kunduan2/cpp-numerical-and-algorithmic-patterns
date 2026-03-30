

#include <iostream>
#include <string>
using namespace std;

// 2D array: stack = flat block, heap = pointer-of-pointers

// For STACK arrays — cols must be known at compile time
void print_stack(const int A[][2], int rows) {
    cout << "  Stack 2D array (int A[][2]):\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 2; j++)
            cout << "    A[" << i << "][" << j << "] = "
                 << A[i][j]
                 << "  ==  *(*(A+" << i << ")+" << j << ") = "
                 << *(*(A + i) + j) << "\n";
}

// For HEAP arrays — receives int**, size passed explicitly
void print_2dArray(int** A, int rows, int cols){
    for (int i=0; i!=rows; i++){
        for (int j=0; j!=cols; j++){
            cout << " " << A[i][j] << " ";               
        }
        printf("\n");
    }
}

int sum(int** A, int rows, int cols){
    int s = 0;
    for (int i=0; i!=rows; i++){
        for (int j=0; j!=cols; j++){
            s += A[i][j];
        }
    }
    return s;
}


int main(){
    
    // int* arrp_stack[3] = {&a, &b, &c}; // arr of ptrs

    // int** dp = arrp_stack;

    // // cout << " " << dp  << "\n";   
    // // cout << " " <<  &arrp[0] << "\n";


    // // separate way
    // int** dp2 = new int*[3];
    // dp2[0] = &a;
    // cout << " " << dp2[0]  << "\n"; 

    // delete[] dp2;

    // ----------------- 2D-pointers ------------------------------------
    int rows = 3, cols = 2;
    int A[rows][2] = {{21,12},
                         {42,3}, 
                         {3, 94}};

    // Addresses in a stack 2D array
    cout << " Addresses in a stack 2D array" << "\n";
    cout << " A = " <<  A << "\n";
    cout << " &A = " <<  &A << "\n";
    cout << " A[0] = " <<  A[0] << "\n";
    cout << " &A[0] = " <<  &A[0] << "\n";
    cout << " A[0][0] = " << A[0][0]  << "\n";
    cout << " &A[0][0] = " <<  &A[0][0] << "\n\n";

    // Instead of writing 2D array of integeres write ptr to ptr and acces each element
    
    
    int** B = new int*[rows];

    for (int i=0; i!=rows; i++){
        B[i] = new int[cols]; // note: p[i] is ptr to int although p is ptr to ptr!
        for (int j=0; j!=cols; j++){
            B[i][j] = i+j;
        }
    }

    // stack
    cout << "Printing elements from stack" << "\n";
    print_stack(A, rows);

    // heap
    cout << "\nprinting elements (heap) of B" << "\n";
    print_2dArray(B, rows, cols);
    cout << " "  << "\n";

    cout << "\nSum of elements (heap) of B" << "\n";
    cout << "Sum = "  << sum(B, rows, cols) << "\n";


    // delete heap-memory
    for (int i=0; i<rows; i++){
        delete[] B[i];
    }
    delete[] B;

}