#ifndef tp_double_h
#define tp_double_h

//----------------------------------------------------------------
#include "t_double.h"

// Triadic Double Pointer class consists of a tuple: Double pointer's value (pointer) and Triadic pointer's degree (true, false, limit)

class tp_double
{
private:
    // here creating pointer because we assign null as default value
    t_double *value;
    Degree Deg;

    // Class constructors: default and parameterized

    // default value of Triadic Double pointer is null pointer
    // degree of Triadic Double pointer is 'limit' (L).

public:
    tp_double()
    {
        value = nullptr;
        Deg = L;
    }

    // parameterized Triadic Double Pointer (pointer's value, pointer's degree, degree of pointer's value)

    tp_double(double v, Degree p_d = L, Degree d_d = L)
    {
        switch (p_d)
        {
        case T:
            value = new t_double(v, d_d);
            Deg = p_d;
            break;
        default:
            value = nullptr;
            Deg = p_d;
            break;
        }
    }

    // Class destuctor
    ~tp_double()
    {
        if (value != nullptr)
        {
            delete value;
        }
        value = nullptr;
    }

    // Setter function to assign Triadic Double Pointer's value: Triadic Double variable
    // It only works when Triadic Double pointer's degree is True.

    void set_pointer(t_double val)
    {
        if (value != nullptr)
        {
            value[0].set_Degree(val.get_Degree());
            value[0].set_value(val.get_value());
        }
    }

    // Setter function to assign Triadic Double Pointer's value (double) and value's degree.
    // It only works when Triadic Double pointer's degree is True.

    void set_pointer(double val, Degree d)
    {
        if (value != nullptr)
        {
            value[0].set_Degree(d);
            value[0].set_value(val);
        }
    }

    // Setter function to assign Triadic Double Pointer's value (double)

    void set_value(double val)
    {
        if (value != nullptr)
        {
            value[0].set_value(val);
        }
    }

    // Setter function to assign degree of Triadic Double Pointer's value

    void set_value_deg(Degree d)
    {

        value[0].set_Degree(d);
    }

    // Setter function to assign Triadic Double Pointer's degree

    void set_Degree_ptr(Degree d)
    {
        Deg = d;
        switch (d)
        {
        case T:
            if (value == nullptr)
                value = new t_double(0);
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

    // Getter function to get/gain/collect Triadic Double Pointer's value (double)

    double get_value()
    {
        if (Deg == T)
            return value[0].get_value();
        else
            return -1;
    }

    // Getter function to get/gain/collect Triadic Double Pointer's value (Triadic double)

    t_double get_pointer()
    {
        t_double temp;
        if (Deg == T)
            temp = value[0];
        return temp;
    }

    // Getter function to get/gain/collect Triadic Double Pointer's degree

    Degree get_Degree_ptr()
    {
        return Deg;
    }

    // Getter function to get/gain/collect degree of the Triadic Double Pointer's value (double)

    Degree get_Degree_val()
    {
        if (Deg == T)
            return value[0].get_Degree();
        else
        {
            return L;
        }
    }

    // Assignment operator for two Triadic Double pointers

    // For instance, two Triadic Double pointers are defined as tp_double a, b;
    // then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    tp_double &operator=(tp_double &obj)
    {
        set_Degree_ptr(obj.get_Degree_ptr());
        value = new t_double;
        *(value) = obj.get_pointer();
        return *this;
    }

    // Copy constructor
    // For instance, a Triadic Double pointer is defined as tp_double a;
    // And somewhere another Triadic Double pointer is defined as tp_double b(a);
    // Then b = a means value and degree of b gets a's (value, degree) respectively.

    tp_double(tp_double &obj)
    {
        this->set_Degree_ptr(obj.get_Degree_ptr());
        this->set_value(obj.get_value());
    }
};

// Scan (or read) Triadic Double pointer's degree, value of pointer's variable, and degree of pointer's variable from console

void t_scan(tp_double &obj)
{
    t_double temp;
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

// Print (or output) Triadic Double pointer's degree, value of pointer and degree of pointer's value via console

void t_print(tp_double &obj)
{
    t_double temp;
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

// Scan (or read) Triadic Double pointer's degree, value of pointer's variable, and degree of pointer's variable from file

void t_scanfile(ifstream &fin, tp_double &obj)
{
    Degree d;
    t_double temp;
    int t;
    fin >> t;
    d = enum_convert(t);
    obj.set_Degree_ptr(d);
    t_scanfile(fin, temp);
    obj.set_pointer(temp);
}

// Print (or output) Triadic Double pointer's degree, value of pointer and degree of pointer's value via console

void t_printfile(ofstream &fout, tp_double &obj)
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
#endif /* tp_double.h */