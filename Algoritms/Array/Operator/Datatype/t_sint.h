// This file presents a unique datatype namely Triadic Short Integer.

#ifndef t_sint_h
#define t_sint_h
//----------------------------------------------------------------
#include "Enum/t_enum.h"
//----------------------

// Triadic Short Integer class consists of a tuple: Short Integer value (true or false) and Triadic degree (true, false, limit)

class t_sint
{
private:
    //
    short int value;
    Degree Deg;

    // Class constructors: default and parameterized

    // default degree of Triadic Short Integer variable is 'limit' (L).

public:
    t_sint()
    {
        Deg = L;
    }
    t_sint(short int v, Degree d = L)
    {
        value = v;
        Deg = d;
    }

    // Class destuctor

    ~t_sint()
    {
    }

    // Setter function to assign Triadic Short Integer value

    void set_value(short int val)
    {
        value = val;
    }

    // Setter function to assign Triadic degree

    void set_Degree(Degree d)
    {
        Deg = d;
    }

    // Getter function to get/gain/collect Triadic Short Integer value

    short int get_value()
    {

        return value;
    }

    // Getter function to get/gain/collect Triadic degree

    Degree get_Degree()
    {
        return Deg;
    }

    // Assignment operator for two Triadic Short Integer variables

    // For instance, two Triadic Short Integer variables are defined as t_sint a, b;
    // then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    void operator=(t_sint obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }

    // Copy constructor
    // For instance, a Triadic Short Integer variable is defined as t_sint a;
    // And somewhere another Triadic Short Integer variable is defined as t_sint b(a);
    // Then b = a means value and degree of b gets a's (value, degree) respectively.

    t_sint(t_sint &obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }
};

// Scan (or read) Triadic Short Integer variable's value and degree from console

void t_scan(t_sint &obj)
{
    short int val;
    Degree deg;
    cout << "Value: ";
    cin >> val;
    obj.set_value(val);
    // cout << "Degree: ";
    t_scan(deg);
    obj.set_Degree(deg);
}

// Print (or output) Triadic Short Integer variable's value and degree both via console

void t_print(t_sint obj)
{
    cout << "Value: " << obj.get_value() << "------->Degree: ";
    t_print(obj.get_Degree());
    cout << endl;
}

// Scan (or read) Triadic Short Integer variable's value via file

void t_scanfile(ifstream &fin, t_sint &obj)
{
    short int val;
    int i;
    Degree deg;
    fin >> val;
    obj.set_value(val);
    fin >> i;
    deg = enum_convert(i);
    obj.set_Degree(deg);
}

// Print (or output) Triadic Short Integer variable's value and degree both via file

void t_printfile(ofstream &fout, t_sint obj)
{
    fout << obj.get_value() << " " << obj.get_Degree() << endl;
}
#endif /* t_sint.h */