#ifndef COMPLEX_H
#define COMPLEX_H

#include <QString>

class complex
{
public:
    complex();
    complex(double _r);
    complex(QString& value);
    complex(const complex& comp);

    complex& operator=(double _r);
    complex& operator+=(const complex& comp);
    complex& operator-=(const complex& comp);
    complex& operator*=(const complex& comp);
    complex& operator/=(const complex& comp);

    double getAbs();
    QString toString();

    double r;
    double i;
};

complex operator+(const complex lhs, const complex rhs);
complex operator-(const complex lhs, const complex rhs);
complex operator*(const complex lhs, const complex rhs);
complex operator/(const complex lhs, const complex rhs);

#endif // COMPLEX_H
