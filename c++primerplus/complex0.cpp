#include "complex0.h"
#include <iostream>

using std::cout;
using std::endl;

namespace COMPLEX{
    Complex::Complex(double real, double imag) {
        real_ = real;
        imag_ = imag;
    }

    Complex::~Complex(){}

    Complex Complex::operator+(const Complex & a) const {
        return Complex(real_ + a.real_, imag_ + a.imag_);
    }

    Complex Complex::operator-(const Complex & a) const {
        return Complex(real_ - a.real_, imag_ - a.imag_);
    }

    Complex Complex::operator*(const Complex & a) const {
        return Complex(real_ * a.real_ - imag_ * a.imag_, real_ * a.imag_ + a.real_ * imag_);
    }

    Complex Complex::operator*(const double & x) const {
        return Complex(x * real_, x * imag_);
    }

    Complex Complex::operator~() const {
        return Complex(real_, -imag_);
    }

    Complex operator*(const double & x, const Complex & a) {
        return a * x;
    }

    ostream & operator<<(ostream & os, const Complex & a) {
        return os << "(" << a.real_ << ", " << a.imag_ << ")";
    }

    istream & operator>>(istream & is,  Complex & a) {
        cout << "real: ";
        is >> a.real_;
        cout << "imaginary: ";
        is >> a.imag_;
        return is;
    }
}