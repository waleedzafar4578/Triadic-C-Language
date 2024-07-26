// This file presents a unique datatype namely Triadic Long Double.

#ifndef t_ldouble_h
#define t_ldouble_h
//----------------------------------------------------------------
#include "Enum/t_enum.h"
//----------------------

// Triadic Long Double class consists of a tuple: Long Double value and Triadic degree (true, false, limit)

class t_ldouble
{
private:
    //
    long double value;
    Degree Deg;

    // Class constructors: default and parameterized

    // default degree of Triadic Long Double variable is 'limit' (L).

public:
    t_ldouble()
    {
        Deg = L;
    }
    t_ldouble(long double v, Degree d = L)
    {
        value = v;
        Deg = d;
    }

    // Class destructor

    ~t_ldouble()
    {
    }

    // Setter function to assign Triadic Long Double value

    void set_value(long double val)
    {
        value = val;
    }

    // Setter function to assign Triadic degree

    void set_Degree(Degree d)
    {
        Deg = d;
    }

    // Getter function to get/gain/collect Triadic Long Double value

    long double get_value()
    {

        return value;
    }

    // Getter function to get/gain/collect Triadic degree

    Degree get_Degree()
    {
        return Deg;
    }

    // Assignment operator for two Triadic Long Double variables

    // For instance, two Triadic Long Double variables are defined as t_ldouble a, b;
    // then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    void operator=(t_ldouble obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }

    // Copy constructor
    // For instance, a Triadic Long Double variable is defined as t_ldouble a;
    // And somewhere another Triadic Long Double variable is defined as t_ldouble b(a);
    // Then b = a means value and degree of b gets a's (value, degree) respectively.

    t_ldouble(t_ldouble &obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }
};

// Scan (or read) Triadic Long Double variable's value and degree from console

void t_scan(t_ldouble &obj)
{
    long double val;
    Degree deg;
    cout << "Value: ";
    cin >> val;
    obj.set_value(val);
    // cout << "Degree: ";
    t_scan(deg);
    obj.set_Degree(deg);
}

// Print (or output) Triadic Long Double variable's value and degree both via console

void t_print(t_ldouble obj)
{
    cout << "Value: " << obj.get_value() << "------->Degree: ";
    t_print(obj.get_Degree());
    cout << endl;
}

// Scan (or read) Triadic Long Double variable's value via file

void t_scanfile(ifstream &fin, t_ldouble &obj)
{
    long double val;
    Degree deg;
    int i;
    fin >> val;
    obj.set_value(val);
    fin >> i;
    deg = enum_convert(i);
    obj.set_Degree(deg);
}

// Print (or output) Triadic Long Double variable's value and degree both via file

void t_printfile(ofstream &fout, t_ldouble obj)
{
    fout << obj.get_value() << " " << obj.get_Degree() << endl;
}
#endif /* t_ldouble.h */