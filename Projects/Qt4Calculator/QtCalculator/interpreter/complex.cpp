#include "complex.h"

#include <math.h>

complex::complex()
    :r(0),i(0)
{

}

complex::complex(double _r)
    :r(_r), i(0)
{

}

complex::complex(QString& value)
{
    if(value.right(1) == "i")
    {
        r = 0;
        if(value.length() == 1)
        {
            i = 1;
        }
        else
        {
            i = value.left(value.length() - 1).toDouble();
        }
    }
    else
    {
        r = value.toDouble();
        i = 0;
    }
}

complex::complex(const complex& comp)
    :r(comp.r),i(comp.i)
{

}

complex& complex::operator=(double _r)
{
    r = _r;
    i = 0;
    return *this;
}

complex& complex::operator+=(const complex& comp)
{
    r += comp.r;
    i += comp.i;
    return *this;
}

complex& complex::operator-=(const complex& comp)
{
    r -= comp.r;
    i -= comp.i;
    return *this;
}

complex& complex::operator*=(const complex& comp)
{
    if(i != 0 || comp.i != 0)
    {
        double temp = r * comp.r - i * comp.i;
        i = r * comp.i + i * comp.r;
        r = temp;
    }
    else
    {
        r *= comp.r;
    }
    return *this;
}

complex& complex::operator/=(const complex& comp)
{
    if(i != 0 || comp.i != 0)
    {
        double temp = (r * comp.r + i * comp.i)/(comp.r * comp.r + comp.i * comp.i);
        i = (i * comp.r - r * comp.i)/(comp.r * comp.r + comp.i * comp.i);
        r = temp;
    }
    else
    {
        r /= comp.r;
    }
    return *this;
}

double complex::getAbs()
{
    return sqrt(r * r + i * i);
}

QString complex::toString()
{
    QString valueString;
    if(r != 0)
    {
        QString real;
        real.setNum(r, 'g', 12);
        valueString += real;
    }
    if(i != 0)
    {
        QString imaginary;
        imaginary.setNum(i, 'g', 12);
        imaginary += "i";
        if(valueString.length() > 0 && i > 0)
        {
            valueString += "+";
        }
        valueString += imaginary;
    }
    return valueString;
}

complex operator+(const complex lhs, const complex rhs)
{
    complex ret(lhs);
    ret += rhs;
    return ret;
}

complex operator-(const complex lhs, const complex rhs)
{
    complex ret(lhs);
    ret -= rhs;
    return ret;
}
complex operator*(const complex lhs, const complex rhs)
{
    complex ret(lhs);
    ret *= rhs;
    return ret;
}
complex operator/(const complex lhs, const complex rhs)
{
    complex ret(lhs);
    ret /= rhs;
    return ret;
}
