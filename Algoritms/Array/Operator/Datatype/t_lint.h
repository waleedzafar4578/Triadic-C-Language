// This file presents a unique datatype namely Triadic Long Integer.

#ifndef t_lint_h
#define t_lint_h
//----------------------------------------------------------------
#include "Enum/t_enum.h"
//----------------------

// Triadic Long Integer class consists of a tuple: Long Integer value (true or false) and Triadic degree (true, false, limit)

class t_lint
{
private:
    //
    long int value;
    Degree Deg;

    // Class constructors: default and parameterized

    // default degree of Triadic Long Integer variable is 'limit' (L).

public:
    t_lint()
    {
        Deg = L;
    }
    t_lint(long int v, Degree d = L)
    {
        value = v;
        Deg = d;
    }
    // Class destuctor
    ~t_lint()
    {
    }

    // Setter function to assign Triadic Long Integer value

    void set_value(long int val)
    {
        value = val;
    }

    // Setter function to assign Triadic degree

    void set_Degree(Degree d)
    {
        Deg = d;
    }

    // Getter function to get/gain/collect Triadic Long Integer value

    long int get_value()
    {

        return value;
    }

    // Getter function to get/gain/collect Triadic degree

    Degree get_Degree()
    {
        return Deg;
    }

    // Assignment operator for two Triadic Long Integer variables

    // For instance, two Triadic Long Integer variables are defined as t_lint a, b;
    // then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    void operator=(t_lint obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }

    // Copy constructor
    // For instance, a Triadic Long Integer variable is defined as t_lint a;
    // And somewhere another Triadic Long Integer variable is defined as t_lint b(a);
    // Then b = a means value and degree of b gets a's (value, degree) respectively.

    t_lint(t_lint &obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }
};

// Scan (or read) Triadic Long Integer variable's value and degree from console

void t_scan(t_lint &obj)
{
    long int val;
    Degree deg;
    cout << "Value: ";
    cin >> val;
    obj.set_value(val);
    // cout << "Degree: ";
    t_scan(deg);
    obj.set_Degree(deg);
}

// Print (or output) Triadic Long Integer variable's value and degree both via console

void t_print(t_lint obj)
{
    cout << "Value: " << obj.get_value() << "------->Degree: ";
    t_print(obj.get_Degree());
    cout << endl;
}

// Scan (or read) Triadic Long Integer variable's value via file

void t_scanfile(ifstream &fin, t_lint &obj)
{
    long int val;
    Degree deg;
    int i;
    fin >> val;
    obj.set_value(val);
    fin >> i;
    deg = enum_convert(i);
    obj.set_Degree(deg);
}

// Print (or output) Triadic Long Integer variable's value and degree both via file

void t_printfile(ofstream &fout, t_lint obj)
{
    fout << obj.get_value() << " " << obj.get_Degree() << endl;
}
#endif /* t_lint.h */