#ifndef tp_uint_h
#define tp_uint_h

//----------------------------------------------------------------
#include "t_uint.h"

// Triadic Unsigned Integer Pointer class consists of a tuple: Unsigned Integer pointer's value (pointer) and Triadic pointer's degree (true, false, limit)

class tp_uint
{
private:
    // here creating pointer because we assign null as default value
    t_uint *value;
    Degree Deg;

    // Class constructors: default and parameterized

    // default value of Triadic Unsigned Integer pointer is null pointer
    // degree of Triadic Unsigned Integer pointer is 'limit' (L).

public:
    tp_uint()
    {
        value = nullptr;
        Deg = L;
    }

    // parameterized Triadic Unsigned Integer Pointer (pointer's value, pointer's degree, degree of pointer's value)

    tp_uint(unsigned int v, Degree p_d = L, Degree d_d = L)
    {
        switch (p_d)
        {
        case T:
            value = new t_uint(v, d_d);
            Deg = p_d;
            break;
        default:
            value = nullptr;
            Deg = p_d;
            break;
        }
    }

    // Class destuctor
    ~tp_uint()
    {
        if (value != nullptr)
        {
            delete value;
        }
        value = nullptr;
    }

    // Setter function to assign Triadic Unsigned Integer Pointer's value: Triadic Unsigned Integer variable
    // It only works when Triadic Unsigned Integer pointer's degree is True.

    void set_pointer(t_uint val)
    {
        if (value != nullptr)
        {
            value[0].set_Degree(val.get_Degree());
            value[0].set_value(val.get_value());
        }
    }

    // Setter function to assign Triadic Unsigned Integer Pointer's value (uint) and value's degree.
    // It only works when Triadic Unsigned Integer pointer's degree is True.

    void set_pointer(unsigned int val, Degree d)
    {
        if (value != nullptr)
        {
            value[0].set_Degree(d);
            value[0].set_value(val);
        }
    }

    // Setter function to assign Triadic Unsigned Integer Pointer's value (uint)

    void set_value(unsigned int val)
    {
        if (value != nullptr)
        {
            value[0].set_value(val);
        }
    }

    // Setter function to assign degree of Triadic Unsigned Integer Pointer's value

    void set_value_deg(Degree d)
    {

        value[0].set_Degree(d);
    }

    // Setter function to assign Triadic Unsigned Integer Pointer's degree

    void set_Degree_ptr(Degree d)
    {
        Deg = d;
        switch (d)
        {
        case T:
            if (value == nullptr)
                value = new t_uint(0);
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

    // Getter function to get/gain/collect Triadic Unsigned Integer Pointer's value (uint)

    unsigned int get_value()
    {
        if (Deg == T)
            return value[0].get_value();
        else
            return -1;
    }

    // Getter function to get/gain/collect Triadic Unsigned Integer Pointer's value (Triadic uint)

    t_uint get_pointer()
    {
        t_uint temp;
        if (Deg == T)
            temp = value[0];
        return temp;
    }

    // Getter function to get/gain/collect Triadic Unsigned Integer Pointer's degree

    Degree get_Degree_ptr()
    {
        return Deg;
    }

    // Getter function to get/gain/collect degree of the Triadic Unsigned Integer Pointer's value (uint)

    Degree get_Degree_val()
    {
        if (Deg == T)
            return value[0].get_Degree();
        else
        {
            return L;
        }
    }

    // Assignment operator for two Triadic Unsigned Integer pointers

    // For instance, two Triadic Unsigned Integer pointers are defined as tp_uint a, b;
    // then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    tp_uint &operator=(tp_uint &obj)
    {
        set_Degree_ptr(obj.get_Degree_ptr());
        value = new t_uint;
        *(value) = obj.get_pointer();
        return *this;
    }

    // Copy constructor
    // For instance, a Triadic Unsigned Integer pointer is defined as tp_uint a;
    // And somewhere another Triadic Unsigned Integer pointer is defined as tp_uint b(a);
    // Then b = a means value and degree of b gets a's (value, degree) respectively.

    tp_uint(tp_uint &obj)
    {
        this->set_Degree_ptr(obj.get_Degree_ptr());
        this->set_value(obj.get_value());
    }
};

// Scan (or read) Triadic Unsigned Integer pointer's degree, value of pointer's variable, and degree of pointer's variable from console

void t_scan(tp_uint &obj)
{
    t_uint temp;
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

// Print (or output) Triadic Unsigned Integer pointer's degree, value of pointer and degree of pointer's value via console

void t_print(tp_uint &obj)
{
    t_uint temp;
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

// Scan (or read) Triadic Unsigned Integer pointer's degree, value of pointer's variable, and degree of pointer's variable from file

void t_scanfile(ifstream &fin, tp_uint &obj)
{
    Degree d;
    t_uint temp;
    int t;
    fin >> t;
    d = enum_convert(t);
    obj.set_Degree_ptr(d);
    t_scanfile(fin, temp);
    obj.set_pointer(temp);
}

// Print (or output) Triadic Unsigned Integer pointer's degree, value of pointer and degree of pointer's value via console

void t_printfile(ofstream &fout, tp_uint &obj)
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
#endif /* tp_uint.h */