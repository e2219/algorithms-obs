#ifndef COMPLEX0_H
#define COMPLEX0_H
#include <iostream>
using std::ostream;
using std::istream;
namespace COMPLEX{
    class Complex{
    private:
        double real_;
        double imag_;
    public:
        Complex() {real_ = imag_ = 0.0;};
        Complex(double real, double imag);
        ~Complex();
        Complex operator+(const Complex & a) const;
        Complex operator-(const Complex & a) const;
        Complex operator*(const Complex & a) const;
        Complex  operator*(const double & x) const;
        Complex operator~() const;
        friend Complex operator*(const double & x, const Complex & a);
        friend ostream & operator<<(ostream & os, const Complex & a);
        friend istream & operator>>(istream & is, Complex & a);
    };
}

#endif