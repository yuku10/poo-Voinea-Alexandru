#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
class complex

{

public:
    double getRe(); //metode de setat si furnizat
    double getIm() ;
    void setRe(double Re);
    void setIm(double Im);
    complex(const complex& c);
    complex(double r=0, double i=0): a(r),b(i) {}
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
      friend double abs(complex&z_complex);
      friend std::istream& operator>>(std::istream& stream,complex& z_complex);
      friend std::ostream& operator<<(std::ostream& stream,const complex& z_complex);
private:

    double a, b;
    //complex* This(){return this;}
};


#endif // COMPLEX_H_INCLUDED