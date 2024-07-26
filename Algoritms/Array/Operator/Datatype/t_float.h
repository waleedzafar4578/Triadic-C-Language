// This file presents a unique datatype namely Triadic Float.

#ifndef t_float_h
#define t_float_h
//----------------------------------------------------------------
#include "Enum/t_enum.h"
//----------------------

// Triadic Float class consists of a tuple: Float value and Triadic degree (true, false, limit)

class t_float
{
private:
    //
    float value;
    Degree Deg;

    // Class constructors: default and parameterized

    // default degree of Triadic Float variable is 'limit' (L).

public:
    t_float()
    {
        Deg = L;
    }
    t_float(float v, Degree d = L)
    {
        value = v;
        Deg = d;
    }

    // Class destructor

    ~t_float()
    {
    }

    // Setter function to assign Triadic Float value

    void set_value(float val)
    {
        value = val;
    }

    // Setter function to assign Triadic degree

    void set_Degree(Degree d)
    {
        Deg = d;
    }

    // Getter function to get/gain/collect Triadic Float value

    float get_value()
    {

        return value;
    }

    // Getter function to get/gain/collect Triadic degree

    Degree get_Degree()
    {
        return Deg;
    }
    
    // Assignment operator for two Triadic Float variables

    // For instance, two Triadic Float variables are defined as t_bool a, b;
    // then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    void operator=(t_float obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }

    // Copy constructor
    // For instance, a Triadic Float variable is defined as t_float a;
    // And somewhere another Triadic Float variable is defined as t_float b(a);
    // Then b = a means value and degree of b gets a's (value, degree) respectively.

    t_float(t_float &obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }
};

// Scan (or read) Triadic Float variable's value and degree from console

void t_scan(t_float &obj)
{
    float val;
    Degree deg;
    cout << "Value: ";
    cin >> val;
    obj.set_value(val);
    // cout << "Degree: ";
    t_scan(deg);
    obj.set_Degree(deg);
}

// Print (or output) Triadic Float variable's value and degree both via console

void t_print(t_float obj)
{
    cout << "Value: " << obj.get_value() << "------->Degree: ";
    t_print(obj.get_Degree());
    cout << endl;
}

// Scan (or read) Triadic Float variable's value via file

void t_scanfile(ifstream &fin, t_float &obj)
{
    float val;
    int i;
    Degree deg;
    fin >> val;
    obj.set_value(val);
    fin >> i;
    deg = enum_convert(i);
    obj.set_Degree(deg);
}

// Print (or output) Triadic Float variable's value and degree both via file

void t_printfile(ofstream &fout, t_float obj)
{
    fout << obj.get_value() << " " << obj.get_Degree() << endl;
}
#endif /* t_float.h */