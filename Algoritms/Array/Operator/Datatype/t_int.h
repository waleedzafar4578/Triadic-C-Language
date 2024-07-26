// This file presents a unique datatype namely Triadic Integer.

#ifndef t_int_h
#define t_int_h
//----------------------------------------------------------------
#include "Enum/t_enum.h"
//----------------------

// Triadic Integer class consists of a tuple: Integer value and Triadic degree (true, false, limit)

class t_int
{
private:
    //
    int value;
    Degree Deg;

    // Class constructors: default and parameterized

    // default degree of Triadic Integer variable is 'limit' (L).

public:
    t_int()
    {
        Deg = L;
    }
    t_int(int v, Degree d = L)
    {
        value = v;
        Deg = d;
    }

    // Class destructor

    ~t_int()
    {
    }

    // Assignment operator for two Triadic Integer variables

    // For instance, two Triadic Integer variables are defined as t_int a, b;
    // then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    void operator=(t_int obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }

    // Setter function to assign Triadic Integer value

    void set_value(int val)
    {
        value = val;
    }

    // Setter function to assign Triadic degree

    void set_Degree(Degree d)
    {
        Deg = d;
    }

    // Getter function to get/gain/collect Triadic Integer value

    int get_value()
    {

        return value;
    }

    // Getter function to get/gain/collect Triadic degree

    Degree get_Degree()
    {
        return Deg;
    }

    // Copy constructor
    // For instance, a Triadic Integer variable is defined as t_int a;
    // And somewhere another Triadic Integer variable is defined as t_int b(a);
    // Then b = a means value and degree of b gets a's (value, degree) respectively.

    t_int(t_int &obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }

    // friend void t_scan(t_int & obj);
    // friend void t_print(t_int  obj);
    // friend void t_scanfile(ifstream &fin, t_int & obj);
    // friend void t_printfile(ofstream &fout, t_int obj);
};

// Scan (or read) Triadic Integer variable's value and degree from console

void t_scan(t_int &obj)
{
    int val;
    Degree deg;
    cout << "Value: ";
    cin >> val;
    obj.set_value(val);
    t_scan(deg);
    obj.set_Degree(deg);
}

// Print (or output) Triadic Integer variable's value and degree both via console

void t_print(t_int obj)
{
    cout << "Value: " << obj.get_value() << "------->Degree: ";
    t_print(obj.get_Degree());
    cout << endl;
}

// Scan (or read) Triadic Integer variable's value via file

void t_scanfile(ifstream &fin, t_int &obj)
{
    int val;
    Degree deg;
    fin >> val;
    obj.set_value(val);
    fin >> val;
    deg = enum_convert(val);
    obj.set_Degree(deg);
}

// Print (or output) Triadic Integer variable's value and degree both via file

void t_printfile(ofstream &fout, t_int obj)
{
    fout << obj.get_value() << " " << obj.get_Degree() << endl;
}
#endif /* t_int.h */