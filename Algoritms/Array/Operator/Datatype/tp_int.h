#ifndef tp_int_h
#define tp_int_h

//----------------------------------------------------------------
#include "t_int.h"

// Triadic Integer Pointer class consists of a tuple: Integer pointer's value (pointer) and Triadic pointer's degree (true, false, limit)

class tp_int
{
private:
    // here creating pointer because we assign null as default value
    t_int *value;
    Degree Deg;

    // Class constructors: default and parameterized

    // default value of Triadic Integer pointer is null pointer
    // degree of Triadic Integer pointer is 'limit' (L).

public:
    tp_int()
    {
        value = nullptr;
        Deg = L;
    }

    // parameterized Triadic Integer Pointer (pointer's value, pointer's degree, degree of pointer's value)

    tp_int(int v, Degree p_d = L, Degree d_d = L)
    {
        switch (p_d)
        {
        case T:
            value = new t_int(v, d_d);
            Deg = p_d;
            break;
        default:
            value = nullptr;
            Deg = p_d;
            break;
        }
    }

    // Class destuctor

    ~tp_int()
    {
        if (value != nullptr)
        {
            delete value;
        }
        value = nullptr;
    }

    // Setter function to assign Triadic Integer Pointer's value: Triadic Integer variable
    // It only works when Triadic Integer pointer's degree is True.

    void set_pointer(t_int val)
    {
        if (value != nullptr)
        {
            value[0].set_Degree(val.get_Degree());
            value[0].set_value(val.get_value());
        }
    }

    // Setter function to assign Triadic Integer Pointer's value (int) and value's degree.
    // It only works when Triadic Integer pointer's degree is True.

    void set_pointer(int val, Degree d)
    {
        if (value != nullptr)
        {

            value[0].set_value(val);
            value[0].set_Degree(d);
        }
    }

    // Setter function to assign Triadic Integer Pointer's value (int)

    void set_value(int val)
    {
        if (value != nullptr)
        {
            value[0].set_value(val);
        }
    }

    // Setter function to assign degree of Triadic Integer Pointer's value

    void set_value_deg(Degree d)
    {

        value[0].set_Degree(d);
    }

    // Setter function to assign Triadic Integer Pointer's degree

    void set_Degree_ptr(Degree d)
    {
        Deg = d;
        switch (d)
        {
        case T:
            if (value == nullptr)
                value = new t_int(0);
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

    // Getter function to get/gain/collect Triadic Integer Pointer's value (int)

    int get_value()
    {
        if (Deg == T)
            return value[0].get_value();
        else
            return -1;
    }

    // Getter function to get/gain/collect Triadic Integer Pointer's value (Triadic int)

    t_int get_pointer()
    {
        t_int temp;
        if (Deg == T)
            temp = value[0];
        return temp;
    }

    // Getter function to get/gain/collect Triadic Integer Pointer's degree

    Degree get_Degree_ptr()
    {
        return Deg;
    }

    // Getter function to get/gain/collect degree of the Triadic Integer Pointer's value (int)

    Degree get_Degree_val()
    {
        if (Deg == T)
            return value[0].get_Degree();
        else
        {
            return L;
        }
    }

    // Assignment operator for two Triadic Integer pointers

    // For instance, two Triadic Integer pointers are defined as tp_int a, b;
    // then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    tp_int &operator=(tp_int &obj)
    {
        // Deg = obj.get_Degree_ptr();
        set_Degree_ptr(obj.get_Degree_ptr());
        value = new t_int;
        *(value) = obj.get_pointer();
        return *this;
    }

    // Copy constructor
    // For instance, a Triadic Integer pointer is defined as tp_int a;
    // And somewhere another Triadic Integer pointer is defined as tp_int b(a);
    // Then b = a means value and degree of b gets a's (value, degree) respectively.

    tp_int(tp_int &obj)
    {
        this->set_Degree_ptr(obj.get_Degree_ptr());
        this->set_value(obj.get_value());
        this->set_value_deg(obj.get_Degree_val());
    }
};

// Scan (or read) Triadic Integer pointer's degree, value of pointer's variable, and degree of pointer's variable from console

void t_scan(tp_int &obj)
{
    t_int temp;
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

// Print (or output) Triadic Integer pointer's degree, value of pointer and degree of pointer's value via console

void t_print(tp_int &obj)
{
    t_int temp;
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

// Scan (or read) Triadic Integer pointer's degree, value of pointer's variable, and degree of pointer's variable from file

void t_scanfile(ifstream &fin, tp_int &obj)
{
    Degree d;
    t_int temp;
    int t;
    fin >> t;
    d = enum_convert(t);
    obj.set_Degree_ptr(d);
    t_scanfile(fin, temp);
    obj.set_pointer(temp);
}

// Print (or output) Triadic Integer pointer's degree, value of pointer and degree of pointer's value via console

void t_printfile(ofstream &fout, tp_int &obj)
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
#endif /* tp_int.h */
