#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
#include <sstream>
#include <string>
#include <cmath>
#include <math.h>
class complex

{

public:
    double getRe()const; //metode de setat si furnizat
    double getIm()const;
    void setRe(double Re);
    void setIm(double Im);
    complex(const complex& c);
    complex(double r=0, double i=0): a(r),b(i) {}
    complex(std::string &stream);
    void read();
    void print();
    complex &operator=(const complex& z_complex);
    friend complex operator+(const complex& z_complex);
    friend complex operator-(const complex& z_complex);
    friend complex operator+(const complex& z1_complex,const complex& z2_complex);
    friend complex operator-(const complex& z1_complex,const complex& z2_complex);
    friend complex operator+(const complex& z1_complex,const double d_number);
    friend complex operator+(const double d_number,const complex& z2_complex);
    friend complex operator-(const complex& z1_complex,const double d_number);
    friend complex operator-(const double d_number,const complex& z2_complex);
    friend complex operator*(const complex& z1_complex,const complex& z2_complex);
    friend complex operator*(const complex& z1_complex,const double d_number);
    friend complex operator*(const double d_number,const complex&z2_complex);
    friend complex operator/(const complex&z1_complex,const complex&z2_complex);
    friend complex operator/(const complex& z1_complex,const double d_number);
    friend complex operator/(const double d_number,const complex&z2_complex);
    friend complex operator^(complex&z1_complex, int n);
    friend complex operator==(const complex& z1_complex,const complex& z_complex);
    friend complex operator==(const complex& z1_complex,const double d2_number);
    friend complex operator==(const double d_number,const complex& z2_complex);
    friend complex operator!=(const complex&z1_complex, const complex& z2_complex);
    friend complex operator!=(const complex&z1_complex,const double d_number);
    friend complex operator!=(const double d_number,const complex& z2_complex);
    complex& operator+=(const complex& z_complex);
    complex& operator+=(const double d_number);
    complex& operator-=(const complex& z_complex);
    complex& operator-=(const double d_number);
    complex &operator*=(const complex& c);
    complex &operator*=(const double d_number);
    complex &operator/=(const complex&c);
    complex &operator/=(const double d_number);
    complex Conjugate(const complex& z_complex);
    friend std::string ToString(const complex&z_complex);
    operator std::string() const;
    friend double abs(const complex&);
    friend complex sqrt(const complex&z_complex);
    friend complex root_square(const complex&,int);
    friend std::istream& operator>>(std::istream& stream,complex& z_complex);
    friend std::ostream& operator<<(std::ostream& stream,const complex& z_complex);

private:

    double a, b;
    //complex* This(){return this;}
};


#endif // COMPLEX_H_INCLUDED
