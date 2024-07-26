#ifndef tp_lint_h
#define tp_lint_h

//----------------------------------------------------------------
#include "t_lint.h"

// Print (or output) Triadic Long Integer pointer's degree, value of pointer and degree of pointer's value via console

class tp_lint
{
private:
    // here creating pointer because we assign null as default value
    t_lint *value;
    Degree Deg;

    // Class constructors: default and parameterized

    // default value of Triadic Long Integer pointer is null pointer
    // degree of Triadic Long Integer pointer is 'limit' (L).

public:
    tp_lint()
    {
        value = nullptr;
        Deg = L;
    }

    // parameterized Triadic Long Integer Pointer (pointer's value, pointer's degree, degree of pointer's value)

    tp_lint(long int v, Degree p_d = L, Degree d_d = L)
    {
        switch (p_d)
        {
        case T:
            value = new t_lint(v, d_d);
            Deg = p_d;
            break;
        default:
            value = nullptr;
            Deg = p_d;
            break;
        }
    }

    // Class destuctor
    ~tp_lint()
    {
        if (value != nullptr)
        {
            delete value;
        }
        value = nullptr;
    }

    // Setter function to assign Triadic Long Integer Pointer's value: Triadic Long Integer variable
    // It only works when Triadic Long Integer pointer's degree is True.

    void set_pointer(t_lint val)
    {
        if (value != nullptr)
        {
            value[0].set_Degree(val.get_Degree());
            value[0].set_value(val.get_value());
        }
    }

    // Setter function to assign Triadic Long Integer Pointer's value (lint) and value's degree.
    // It only works when Triadic Long Integer pointer's degree is True.

    void set_pointer(long int val, Degree d)
    {
        if (value != nullptr)
        {
            value[0].set_Degree(d);
            value[0].set_value(val);
        }
    }

    // Setter function to assign Triadic Long Integer Pointer's value (lint)

    void set_value(long int val)
    {
        if (value != nullptr)
        {
            value[0].set_value(val);
        }
    }

    // Setter function to assign degree of Triadic Long Integer Pointer's value

    void set_value_deg(Degree d)
    {

        value[0].set_Degree(d);
    }

    // Setter function to assign Triadic Long Integer Pointer's degree

    void set_Degree_ptr(Degree d)
    {
        Deg = d;
        switch (d)
        {
        case T:
            if (value == nullptr)
                value = new t_lint(0);
            break;
        case F:
        case L:
            delete value;
            value = nullptr;
            break;
        default:

            break;
        }
    }

    // Getter function to get/gain/collect Triadic Long Integer Pointer's value (lint)

    long int get_value()
    {
        if (Deg == T)
            return value[0].get_value();
        else
            return -1;
    }

    // Getter function to get/gain/collect Triadic Long Integer Pointer's value (Triadic lint)

    t_lint get_pointer()
    {
        t_lint temp;
        if (Deg == T)
            temp = value[0];
        return temp;
    }

    // Getter function to get/gain/collect Triadic Long Integer Pointer's degree

    Degree get_Degree_ptr()
    {
        return Deg;
    }

    // Getter function to get/gain/collect degree of the Triadic Long Integer Pointer's value (lint)

    Degree get_Degree_val()
    {
        if (Deg == T)
            return value[0].get_Degree();
        else
        {
            return L;
        }
    }

    // Assignment operator for two Triadic Long Integer pointers

    // For instance, two Triadic Long Integer pointers are defined as tp_lint a, b;
    // then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    tp_lint &operator=(tp_lint &obj)
    {
        set_Degree_ptr(obj.get_Degree_ptr());
        value = new t_lint;
        *(value) = obj.get_pointer();
        return *this;
    }

    // Copy constructor
    // For instance, a Triadic Long Integer pointer is defined as tp_lint a;
    // And somewhere another Triadic Long Integer pointer is defined as tp_lint b(a);
    // Then b = a means value and degree of b gets a's (value, degree) respectively.

    tp_lint(tp_lint &obj)
    {
        this->set_Degree_ptr(obj.get_Degree_ptr());
        this->set_value(obj.get_value());
    }
};

// Scan (or read) Triadic Long Integer pointer's degree, value of pointer's variable, and degree of pointer's variable from console

void t_scan(tp_lint &obj)
{
    t_lint temp;
    Degree d;
    cout << "Pointer ";
    t_scan(d);
    obj.set_Degree_ptr(d);
    if (d == T)
    {
        t_scan(temp);
        obj.set_pointer(temp);
    }
}

// Print (or output) Triadic Long Integer pointer's degree, value of pointer and degree of pointer's value via console

void t_print(tp_lint &obj)
{
    t_lint temp;
    // Degree d;
    // d = obj.get_Degree_ptr();
    if (obj.get_Degree_ptr() == T)
    {
        temp = obj.get_pointer();
        t_print(temp);
    }
    else
    {
        cout << "Warning Memory allocation error." << endl;
    }
}

// Scan (or read) Triadic Long Integer pointer's degree, value of pointer's variable, and degree of pointer's variable from file

void t_scanfile(ifstream &fin, tp_lint &obj)
{
    Degree d;
    t_lint temp;
    int t;
    fin >> t;
    d = enum_convert(t);
    obj.set_Degree_ptr(d);
    t_scanfile(fin, temp);
    obj.set_pointer(temp);
}

// Print (or output) Triadic Long Integer pointer's degree, value of pointer and degree of pointer's value via console

void t_printfile(ofstream &fout, tp_lint &obj)
{
    if (obj.get_Degree_ptr() == T)
    {
        fout << obj.get_Degree_ptr() << " " << obj.get_value() << " " << obj.get_Degree_val() << endl;
    }
    else
    {
        fout << obj.get_Degree_ptr() << " " << -1 << " " << L << endl;
    }
}
#endif /* tp_lint.h */