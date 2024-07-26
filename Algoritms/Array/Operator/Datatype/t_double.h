// This file presents a unique datatype namely Triadic Double.

#ifndef t_double_h
#define t_double_h
//----------------------------------------------------------------
#include "Enum/t_enum.h"
//----------------------

// Triadic Double class consists of a tuple: Double value and Triadic degree (true, false, limit)

class t_double
{
private:
    //
    double value;
    Degree Deg;

    // Class constructors: default and parameterized

    // default degree of Triadic Double variable is 'limit' (L).

public:
    t_double()
    {
        Deg = L;
    }
    t_double(double v, Degree d = L)
    {
        value = v;
        Deg = d;
    }

    // Class destructor

    ~t_double()
    {
    }

    // Setter function to assign Triadic Double value

    void set_value(double val)
    {
        value = val;
    }

    // Setter function to assign Triadic degree

    void set_Degree(Degree d)
    {
        Deg = d;
    }

    // Getter function to get/gain/collect Triadic Double value

    double get_value()
    {

        return value;
    }

    // Getter function to get/gain/collect Triadic degree
    
    Degree get_Degree()
    {
        return Deg;
    }

    // Assignment operator for two Triadic Double variables

    // For instance, two Triadic Double variables are defined as t_double a, b;
    // then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    void operator=(t_double obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }

    // Copy constructor
    // For instance, a Triadic Double variable is defined as t_double a;
    // And somewhere another Triadic Double variable is defined as t_double b(a);
    // Then b = a means value and degree of b gets a's (value, degree) respectively.

    t_double(t_double &obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }
};

// Scan (or read) Triadic Double variable's value and degree from console

void t_scan(t_double &obj)
{
    double val;
    Degree deg;
    cout << "Value: ";
    cin >> val;
    obj.set_value(val);
    // cout << "Degree: ";
    t_scan(deg);
    obj.set_Degree(deg);
}

// Print (or output) Triadic Double variable's value and degree both via console

void t_print(t_double obj)
{
    cout << "Value: " << obj.get_value() << "------->Degree: ";
    t_print(obj.get_Degree());
    cout << endl;
}

// Scan (or read) Triadic Double variable's value via file

void t_scanfile(ifstream &fin, t_double &obj)
{
    double val;
    int i;
    Degree deg;
    fin >> val;
    obj.set_value(val);
    fin >> i;
    deg = enum_convert(i);
    obj.set_Degree(deg);
}

// Print (or output) Triadic Double variable's value and degree both via file

void t_printfile(ofstream &fout, t_double obj)
{
    fout << obj.get_value() << " " << obj.get_Degree() << endl;
}
#endif /* t_double.h */