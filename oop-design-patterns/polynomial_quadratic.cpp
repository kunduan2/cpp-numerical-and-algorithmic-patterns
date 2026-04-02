
/*
Designing a Demo-Class:

Function  (base)
│   evaluate()         pure virtual
│   derivative()       pure virtual
│   print()            pure virtual
└── Polynomial  (derived)
│       evaluate()          override
│       derivative()        override
│       print()             override
│
    └── Quadratic  (most derived)
            evaluate()          inherited from Polynomial
            derivative()        inherited from Polynomial
            print()             override
            areaUnderCurve()    own — Simpson's rule numerical integration

*/

#include <iostream>
#include <string>
using namespace std;

class Function{
private:

public:
    virtual ~Function() = default;
    virtual double evaluate(double x) const = 0; 
    virtual double derivative(double x) const = 0; 
    virtual void print() const = 0;
};

// Derived: Polynomial 
// f(x) = c0 + c1*x + c2*x^2 + ... + cn*x^n
// coeffs_[i] = coefficient of x^i

class Polynomial : public Function {
private:
    double coeffs_[10];
    int degree_;
public:
    Polynomial(const double coeffs[], int degree) : degree_(degree){
        for (int i=0; i<=degree_; i++){
            coeffs_[i] = coeffs[i];
        }
    }
    // f(x) = sum of coeffs_[i] * x^i
    double evaluate(double x) const override{
        double result = 0.0, power = 1.0;
        for (int i=0; i<=degree_; i++){
            result += coeffs_[i]*power;
            power *= x;
        }
        return result;
    }

    // f'(x) = sum of i * coeffs_[i] * x^(i-1)
   double derivative(double x) const override{
        double result = 0.0, power = 1.0;
        for (int i=1; i<=degree_; i++){  // Trick: i starts from 1
            result += i*coeffs_[i]*power;
            power *= x;
        }
        return result;
    }

void print() const override {
    cout << "f(x) = ";
    bool first = true;

    for (int i = degree_; i >= 0; i--) {
        if (coeffs_[i] == 0) continue;

        if (first) {
            if (coeffs_[i] < 0) cout << "-";
        } else {
            cout << (coeffs_[i] > 0 ? " + " : " - ");
        }

        double c = std::abs(coeffs_[i]);

        if (c != 1 || i == 0) cout << c;

        if (i > 0) {
            cout << "x";
            if (i > 1) cout << "^" << i;
        }

        first = false;
    }

    if (first) cout << "0";  // all coefficients were zero

    cout << "\n";
}
};


// Most Derived: Quadratic 
// f(x) = ax^2 + bx + c  — degree is always exactly 2.

class Quadratic : public Polynomial{
public:
    Quadratic(double a, double b, double c) : Polynomial(new double[3]{c, b, a}, 2){
        // write code if required.
    }
    
    // Simpson's rule: ∫f(x)dx ≈ (h/3)[f(x0)+4f(x1)+2f(x2)+4f(x3)+...+f(xn)]
    // n must be even — more steps = more accurate
    double areaUnderCurve(double t1, double t2, int steps = 1000) const{
        if (steps % 2 != 0) steps++;        // Simpson's needs even steps
        double h = (t2-t1)/steps;
        double result = evaluate(t1) + evaluate(t2);
        for (int i=1; i<steps; i++){
            double x = t1 + i*h;
            result += (i%2==0? 2:4)*evaluate(x);
        }

        return result*h/3.0;
    }


};

int main(){

    //Polynomial: f(x) = 1 + 24x + 2x^2 + 45x^3
   double cof[4] = {1.0, 24, 2.0, 45};

   cout << "Calling Polynomial class: " << "\n";
   Polynomial p(cof, 3);
   p.print();
   
   double x = 2.0;
   cout << "For x = " << x  << ":\n";
   cout << "f(x) =" <<  p.evaluate(x) << "\n"; 
   cout << "f'(x) = " << p.derivative(x)  << "\n";

    //Quadratic: f(x) = 2x^2 + 4x + 6 
    cout << "\nCalling Quadratic class: " << "\n";
    Quadratic q(2, 4, 6);
    q.print();
    
    // Simpson's rule (area under curve): a = 1, b=3
    cout << "Area under curve from " << 1 << " to " << 3 << " = "
     << q.areaUnderCurve(1, 3, 1000) << "\n";



    return 0;
}