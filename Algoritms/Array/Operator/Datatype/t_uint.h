// This file presents a unique datatype namely Triadic Unsigned Integer.

#ifndef t_uint_h
#define t_uint_h
//----------------------------------------------------------------
#include "Enum/t_enum.h"
//----------------------

// Triadic Unsigned Integer class consists of a tuple: Unsigned Integer value (true or false) and Triadic degree (true, false, limit)

class t_uint
{
private:
    //
    unsigned int value;
    Degree Deg;

    // Class constructors: default and parameterized

    // default degree of Triadic Unsigned Integer variable is 'limit' (L).

public:
    t_uint()
    {
        Deg = L;
    }
    t_uint(unsigned int v, Degree d = L)
    {
        value = v;
        Deg = d;
    }

    // Class destuctor

    ~t_uint()
    {
    }

    // Setter function to assign Triadic Unsigned Integer value

    void set_value(unsigned int val)
    {
        value = val;
    }

    // Setter function to assign Triadic degree

    void set_Degree(Degree d)
    {
        Deg = d;
    }

    // Getter function to get/gain/collect Triadic Unsigned Integer value

    unsigned int get_value()
    {

        return value;
    }

    // Getter function to get/gain/collect Triadic degree

    Degree get_Degree()
    {
        return Deg;
    }

    // Assignment operator for two Triadic Unsigned Integer variables

    // For instance, two Triadic Unsigned Integer variables are defined as t_uint a, b;
    // then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    void operator=(t_uint obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }

    // Copy constructor
    // For instance, a Triadic Unsigned Integer variable is defined as t_uint a;
    // And somewhere another Triadic Unsigned Integer variable is defined as t_uint b(a);
    // Then b = a means value and degree of b gets a's (value, degree) respectively.

    t_uint(t_uint &obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }
};

// Scan (or read) Triadic Unsigned Integer variable's value and degree from console

void t_scan(t_uint &obj)
{
    unsigned int val;
    Degree deg;
    cout << "Value: ";
    cin >> val;
    obj.set_value(val);
    // cout << "Degree: ";
    t_scan(deg);
    obj.set_Degree(deg);
}

// Print (or output) Triadic Unsigned Integer variable's value and degree both via console

void t_print(t_uint obj)
{
    cout << "Value: " << obj.get_value() << "------->Degree: ";
    t_print(obj.get_Degree());
    cout << endl;
}

// Scan (or read) Triadic Unsigned Integer variable's value via file

void t_scanfile(ifstream &fin, t_uint &obj)
{
    unsigned int val;
    int i;
    Degree deg;
    fin >> val;
    obj.set_value(val);
    fin >> i;
    deg = enum_convert(i);
    obj.set_Degree(deg);
}

// Print (or output) Triadic Unsigned Integer variable's value and degree both via file

void t_printfile(ofstream &fout, t_uint obj)
{
    fout << obj.get_value() << " " << obj.get_Degree() << endl;
}
#endif /* t_uint.h */