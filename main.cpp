#include <iostream>
#include <math.h>
#include "complex.h"
#include "complex.cpp"
#include <sstream>
#include <string>
int main()
{
    complex z1;
    z1.read();
    complex z2;
    z2.read();
   // std::string numar;
   // numar=ToString(z2);
   // std::cout<<numar<<"\n";
    //std::cout<<ToString(z1)<<"\n";
    std::string numar1;
    std::cin>>numar1;
    //std::cout<<numar1<<"\n|";
    try
    {
    complex z15=complex(numar1);
    //std::cout<<z15<<"\n";
    }
     catch(const std::runtime_error&e)
    {
        std::cout<<e.what();
    }
    std::cout<<"\n";
    /*complex z3;
    z3=+(z1);
    z3.print();
    complex z4;
    z4=-(z1);
    z4.print();
    complex z5;
    z5=z1+z2;
    z5.print();
    complex z6;
    z6=z1-z2;
    z6.print();
    complex z7;
    double v1;
    std::cout<<"double1=";
    std::cin>>v1;
    z7=z1+v1;
    z7.print();
    complex z8;
    double v2;
    std::cout<<"double2=";
    std::cin>>v2;
    z8=v2+z1;
    z8.print();
    complex z9;
    z9=z1-v1;
    z9.print();
    complex z10;
    z10=v2-z1;
    z10.print();
    complex z11;
    z11=z1*z2;
    z11.print();
    complex z12;
    z12=z1*v1;
    z12.print();
    complex z13;
    z13=v2*z1;
    z13.print();
    complex z14;
    z14=z1/z2;
    z14.print();
    complex z15;
    z15=z1/v1;
    z15.print();
    complex z16;
    z16=v2/z1;
    z16.print();
    complex z17;
    int n;
    std::cout<<"Puterea este:";
    std::cin>>n;
    z17=z1^n;
    z17.print();
    z2.print();
    complex z18;
    std::cout<<"operator=";
    z18=z1;
    z18.print();
    z1+=z2;
    z1.print();
    double v1;
    std::cin>>v1;
    z1+=v1;
    z1.print();
    z1-=z2;
    z1.print();
    z1-=v1;
    z1.print();
    z1*=z2;
    z1.print();
    z1*=v1;
    z1.print();
    z1/=z2;
    z1.print();*/
    /*double v1;
    std::cin>>v1;
    z1/=v1;
    z1.print();*/
    complex z3;
    z3.Conjugate(z1);
    z3.print();
    std::cout<<"\n Modulul unui numar complex:";
    double m;
    m=abs(z1);
    std::cout<<m<<"\n";
    /*try
    {
    complex z20=z1/z2;
    }
    catch(const std::runtime_error&e)
    {
        std::cout<<e.what();
    }*/
    std::cout<<"\n";
    try
    {
        z1/=z2;
    }
    catch(const std::runtime_error&e)
    {
        std::cout<<e.what();
    }
    return 0;
}
