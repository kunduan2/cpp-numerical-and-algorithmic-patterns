
/*
sum of an integers
Input: positive integer n
Use a while (n > 0) loop.
Repeatedly take n % 10, add to sum, do n /= 10.
Output sum of digits.
*/

#include<iostream>

using namespace std;

int sum_of_digits(int n){
    if (n<0){
        cout<< "Enter positive integer\n" ;
        return -1;
    }

    else{
        int s = 0;
        int count = 0;

        while(true && count<50){
            s += n%10;
            n /= 10; 
            // std::cout << s << " " << n <<std:: endl;        
            // std::cout << count<<std:: endl;
            if (n==0) break;
            count++;

        }
        return s;
    }
}

int main(){
    double n = 54761;
    int s = sum_of_digits(n);

    if (s!=-1)
    cout << "Number = " << n << ", Sum of digits =" << s << endl;
}
