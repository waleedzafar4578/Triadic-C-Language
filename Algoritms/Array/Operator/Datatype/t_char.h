// This file presents a unique datatype namely Triadic Character.

#ifndef t_char_h
#define t_char_h
//----------------------------------------------------------------
#include "Enum/t_enum.h"
//----------------------

// Triadic Character class consists of a tuple: Character value (A-Z or a-z or special characters) and Triadic degree (true, false, limit)

class t_char
{
private:
    //
    char value;
    Degree Deg;

    // Class constructors: default and parameterized

    // default degree of Triadic Character variable is 'limit' (L).

public:
    t_char()
    {
        Deg = L;
    }
    t_char(char v, Degree d = L)
    {
        value = v;
        Deg = d;
    }

    // Class destuctor

    ~t_char()
    {
    }

    // Setter function to assign Triadic Character value

    void set_value(char val)
    {
        value = val;
    }

    // Setter function to assign Triadic degree

    void set_Degree(Degree d)
    {
        Deg = d;
    }

    // Getter function to get/gain/collect Triadic Character value

    char get_value()
    {

        return value;
    }

    // Getter function to get/gain/collect Triadic degree

    Degree get_Degree()
    {
        return Deg;
    }

    // Assignment operator for two Triadic Character variables

    // For instance, two Triadic Character variables are defined as t_char a, b;
    // then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    void operator=(t_char obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }

    // Copy constructor
    // For instance, a Triadic Character variable is defined as t_char a;
    // And somewhere another Triadic Character variable is defined as t_char b(a);
    // Then b = a means value and degree of b gets a's (value, degree) respectively.

    t_char(t_char &obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }
};
// Scan (or read) Triadic Character variable's value and degree from console

void t_scan(t_char &obj)
{
    char val;
    Degree deg;
    cout << "Value: ";
    cin >> val;
    obj.set_value(val);
    // cout << "Degree: ";
    t_scan(deg);
    obj.set_Degree(deg);
}

// Print (or output) Triadic Character variable's value and degree both via console

void t_print(t_char obj)
{
    cout << "Value: " << obj.get_value() << "------->Degree: ";
    t_print(obj.get_Degree());
    cout << endl;
}

// Scan (or read) Triadic Character variable's value via file

void t_scanfile(ifstream &fin, t_char &obj)
{
    char val;
    Degree deg;
    fin >> val;
    obj.set_value(val);
    fin >> val;
    deg = enum_convert(val);
    obj.set_Degree(deg);
}

// Print (or output) Triadic Character variable's value and degree both via file

void t_printfile(ofstream &fout, t_char obj)
{
    fout << obj.get_value() << " " << obj.get_Degree() << endl;
}
#endif /* t_char.h */