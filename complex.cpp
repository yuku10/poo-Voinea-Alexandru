
double complex::getRe()
{
    return a;
}
double complex::getIm()
{
    return b;
}
void complex::setRe(double Re)
{
    a = Re;
}
void complex::setIm(double Im)
{
    b = Im;
}
complex::complex(const complex&z_complex)
{
    a=z_complex.a;
    b=z_complex.b;
}
complex::complex(std::string &stream)
{
    double p_r,p_i;
    int pos_i=stream.find("i");
    if(pos_i==-1 && p_r==0) throw std::runtime_error("Nu este un numar complex");
    else if(pos_i==-1 )
    {
        std::stringstream r_stream(stream);
        r_stream>>p_r;
        p_i=0;
    }
    else if(pos_i==0 || pos_i==1)
            p_r=0;
        else
        {
            std::string s_re=stream.substr(0,pos_i-1);
            std::stringstream r_stream(s_re);
            r_stream>>p_r;
        }
        std::string s_im=stream.substr(pos_i+2);
        std::stringstream i_stream(s_im);
        i_stream>>p_i;
        std::string s_i_sign=stream.substr(pos_i-1,1);
        if(s_i_sign=="-")
            p_i*=-1;


}
std::string ToString(const complex&z_complex)
{
    std::string stream;
    std::stringstream convert;
    if(z_complex.a>0)
    {
        if(z_complex.b==0)
        {
            convert<<z_complex.a;
        }
        else if(z_complex.b>0)
        {
            convert<<z_complex.a<<"+i*"<<z_complex.b;
        }
        else if(z_complex.b<0)
        {
            convert<<z_complex.a<<"-i*"<<-z_complex.b;
        }
    }
    else if(z_complex.a==0)
    {
        if(z_complex.b==0)
        {
            convert<<"Ambele valori sunt 0";
        }
        else if(z_complex.b>0)
        {
            convert<<z_complex.b;
        }
        else if(z_complex.b<0)
        {
            convert<<"i*"<<-z_complex.b;
        }

    }
    else if(z_complex.a<0)
    {
        if(z_complex.b==0)
        {
            convert<<z_complex.a;
        }
        else if(z_complex.b>0)
        {
            convert<<z_complex.a<<"-i*"<<-z_complex.b;
        }
        else if(z_complex.b<0)
        {
            convert<<z_complex.a<<"-i*"<<-z_complex.b;
        }
    }
    stream=convert.str();
    return stream;
}
complex::operator std::string() const
{
    return ToString(*this);
}
void complex::read()
{
    std::cout<<"Real: ";
    std::cin>>a;
    std::cout<<"Imaginar: ";
    std::cin>>b;

}

void complex::print()
{
    std::cout<<a<<" +(i*"<<b<<")";
}
complex& complex::operator=(const complex& z_complex)
{
    a=z_complex.a;
    b=z_complex.b;
    return *this;
}

complex operator+(const complex& z_complex)
{
    std::cout<<"+Complex\n";
    return complex(z_complex.a,z_complex.b);
}
complex operator-(const complex& z_complex)
{
    std::cout<<"-Complex\n";
    return complex(-z_complex.a,-z_complex.b);
}
complex operator+(const complex&z1_complex,const complex&z2_complex)
{
    std::cout<<"Adunare:\n";
    return complex(z1_complex.a+z2_complex.a,z1_complex.b+z2_complex.b);
}
complex operator-(const complex&z1_complex,const complex&z2_complex)
{
    std::cout<<"Scadere:\n";
    return complex(z1_complex.a-z2_complex.a,z1_complex.b-z2_complex.b);
}
complex operator+(const complex&z1_complex,const double d_number)
{
    std::cout<<"Adunare double1:\n";
    return complex(z1_complex.a+d_number,z1_complex.b);
}
complex operator+(const double d_number,const complex& z2_complex)
{
    std::cout<<"Adunare double2:\n";
    return complex(d_number+z2_complex.a,z2_complex.b);
}
complex operator-(const complex& z1_complex,const double d_number)
{
    std::cout<<"Scadere double1:\n";
    return complex(z1_complex.a-d_number,z1_complex.b);
}
complex operator-(const double d_number,const complex& z2_complex)
{
    std::cout<<"Scadere double2:\n";
    return complex(d_number-z2_complex.a,z2_complex.b);
}
complex operator*(const complex& z1_complex,const complex& z2_complex)
{
    std::cout<<"Inmultire:\n";
    return complex(z1_complex.a*z2_complex.a-z1_complex.b*z2_complex.b,z1_complex.a*z2_complex.b+z1_complex.b*z2_complex.a);
}
complex operator*(const complex& z1_complex,const double d_number)
{
    std::cout<<"Inmultire double1:\n";
    return complex(z1_complex.a*d_number,z1_complex.b*d_number);
}
complex operator*(const double d_number,const complex&z2_complex)
{
    std::cout<<"Inmultire double2:\n";
    return complex(z2_complex.a*d_number,z2_complex.b*d_number);
}
complex operator/(const complex& z1_complex,const complex& z2_complex)
{
    std::cout<<"Impartire:\n";
    if(z2_complex.a==0 && z2_complex.b==0)
    {
        throw std::runtime_error("Nu se poate face impartirea");
    }
    return complex((z1_complex.a*z2_complex.a+z1_complex.b*z2_complex.b)/(z2_complex.a*z2_complex.a+z2_complex.b*z2_complex.b),(z1_complex.b*z2_complex.a-z1_complex.a*z2_complex.b)/(z2_complex.a*z2_complex.a+z2_complex.b*z2_complex.b));
}
complex operator/(const complex& z1_complex,const double d_number)
{
    std::cout<<"Impartire double1:\n";
    if(d_number==0)
    {
        throw std::runtime_error("Nu se poate face impartirea");

    }
    return complex(z1_complex.a/d_number,z1_complex.b/d_number);
}
complex operator/(const double z1_complex,const complex&z2_complex)
{
    std::cout<<"Impartire double2:\n";
    if(z2_complex.a==0 && z2_complex.b==0)
    {
        throw std::runtime_error("Nu se poate face impartirea");
    }
    return complex((z1_complex*z2_complex.a)/(z2_complex.a*z2_complex.a+z2_complex.b*z2_complex.b),(-z1_complex*z2_complex.b)/(z2_complex.a*z2_complex.a+z2_complex.b*z2_complex.b));
}
complex operator^(complex&z1_complex, int n)
{
    int i;
    complex aux;
    aux=z1_complex;
    if(n==0)
    {
        aux.a=1;
        aux.b=0;
    }
    else
        for(i=1; i<n; i++)
            aux=z1_complex*aux;
    return aux;
}
complex operator==(const complex& z1_complex,const complex& z2_complex)
{
    if(z1_complex.a==z2_complex.a && z1_complex.b==z2_complex.b)
        return 1;
    return 0;
}
complex operator==(const complex& z1_complex,const double d_number)
{
    if(z1_complex.a==d_number && z1_complex.b==0)
        return 1;
    return 0;
}
complex operator==(const double d_double,const complex& z2_complex)
{
    if(d_double==z2_complex.a && 0==z2_complex.b)
        return 1;
    return 0;
}
complex operator!=(const complex &z1_complex, const complex& z2_complex)
{
    if(z1_complex.a!=z2_complex.a || z1_complex.b!=z2_complex.b)
        return 1;
    return 0;
}
complex operator!=(const complex&z1_complex,const double d_number)
{
    if(z1_complex.a!=d_number || z1_complex.b!=0)
        return 1;
    return 0;
}
complex operator!=(const double d_number,const complex&z2_complex)
{
    if(d_number!=z2_complex.a || 0!=z2_complex.b)
        return 1;
    return 0;
}
complex& complex::operator+=(const complex&z_complex)
{
    std::cout<<"Operator+= :\n";
    a = a + z_complex.a;
    b = b + z_complex.b;
    return *this;
}
complex& complex::operator+=(const double d_number)
{
    std::cout<<"Operator2+=:";
    a=a+d_number;
    return *this;
}

complex& complex::operator-=(const complex& z_complex)
{
    std::cout<<"Operator-=";
    a=a-z_complex.a;
    b=b-z_complex.b;
    return *this;
}

complex& complex::operator-=(const double d_number)
{
    std::cout<<"Operator2-=";
    a=a-d_number;
    return *this;
}

complex& complex:: operator*=(const complex& z_complex)
{
    std::cout<<"Operator*=";
    (*this)=(*this)*z_complex;
    return *this;
}
complex& complex:: operator*=(const double d_number)
{
    std::cout<<"Operator2*=";
    (*this)=(*this)*d_number;
    return *this;
}
complex& complex:: operator/=(const complex&z_complex)
{
    std::cout<<"Operator/=";
    if(z_complex.a==0 && z_complex.b==0) throw std::runtime_error("Nu se poate face impartirea");
    else (*this)=(*this)/z_complex;
    return *this;
}
complex& complex:: operator/=(const double d_number)
{
    std::cout<<"Operator2/=";
    if(d_number==0) throw std::runtime_error("Nu se poate face impartirea");
    else (*this)=(*this)/d_number;
    return *this;
}
complex complex::Conjugate(const complex& z_complex)
{
    a=z_complex.a;
    b=-z_complex.b;
    return *this;
}
double abs(complex&z_complex)
{
    return sqrt(z_complex.a*z_complex.a+z_complex.b*z_complex.b);
}
std::istream& operator>>(std::istream& stream, complex& z_complex)
{
    stream>>z_complex.a>>z_complex.b;
    return stream;
}
std::ostream& operator<<(std::ostream& stream, const complex& z_complex)
{
    stream<<z_complex.a<<" "<<z_complex.b;
    return stream;
}
