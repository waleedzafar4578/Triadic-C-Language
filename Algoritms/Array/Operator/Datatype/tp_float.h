#ifndef tp_float_h
#define tp_float_h

//----------------------------------------------------------------
#include "t_float.h"

// Triadic Float Pointer class consists of a tuple: Float pointer's value (pointer) and Triadic pointer's degree (true, false, limit)

class tp_float
{
private:
    // here creating pointer because we assign null as default value
    t_float *value;
    Degree Deg;

    // Class constructors: default and parameterized

    // default value of Triadic Float pointer is null pointer
    // degree of Triadic Float pointer is 'limit' (L).

public:
    tp_float()
    {
        value = nullptr;
        Deg = L;
    }

    // parameterized Triadic Float Pointer (pointer's value, pointer's degree, degree of pointer's value)

    tp_float(float v, Degree p_d = L, Degree d_d = L)
    {
        switch (p_d)
        {
        case T:
            value = new t_float(v, d_d);
            Deg = p_d;
            break;
        default:
            value = nullptr;
            Deg = p_d;
            break;
        }
    }
    // Class destuctor
    ~tp_float()
    {
        if (value != nullptr)
        {
            delete value;
        }
        value = nullptr;
    }

    // Setter function to assign Triadic Float Pointer's value: Triadic Float variable
    // It only works when Triadic Float pointer's degree is True.

    void set_pointer(t_float val)
    {
        if (value != nullptr)
        {
            value[0].set_Degree(val.get_Degree());
            value[0].set_value(val.get_value());
        }
    }

    // Setter function to assign Triadic Float Pointer's value (float) and value's degree.
    // It only works when Triadic Float pointer's degree is True.
    void set_pointer(float val, Degree d)
    {
        if (value != nullptr)
        {
            value[0].set_Degree(d);
            value[0].set_value(val);
        }
    }

    // Setter function to assign Triadic Float Pointer's value (float)

    void set_value(float val)
    {
        if (value != nullptr)
        {
            value[0].set_value(val);
        }
    }

    // Setter function to assign degree of Triadic Float Pointer's value

    void set_value_deg(Degree d)
    {

        value[0].set_Degree(d);
    }

    // Setter function to assign Triadic Float Pointer's degree

    void set_Degree_ptr(Degree d)
    {
        Deg = d;
        switch (d)
        {
        case T:
            if (value == nullptr)
                value = new t_float(0);
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

    // Getter function to get/gain/collect Triadic Float Pointer's value (float)

    float get_value()
    {
        if (Deg == T)
            return value[0].get_value();
        else
            return -1;
    }

    // Getter function to get/gain/collect Triadic Float Pointer's value (Triadic float)

    t_float get_pointer()
    {
        t_float temp;
        if (Deg == T)
            temp = value[0];
        return temp;
    }

    // Getter function to get/gain/collect Triadic Float Pointer's degree

    Degree get_Degree_ptr()
    {
        return Deg;
    }

    // Getter function to get/gain/collect degree of the Triadic Float Pointer's value (float)

    Degree get_Degree_val()
    {
        if (Deg == T)
            return value[0].get_Degree();
        else
        {
            return L;
        }
    }

    // Assignment operator for two Triadic Float pointers

    // For instance, two Triadic Float pointers are defined as tp_float a, b;
    // then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    tp_float &operator=(tp_float &obj)
    {
        set_Degree_ptr(obj.get_Degree_ptr());
        value = new t_float;
        *(value) = obj.get_pointer();
        return *this;
    }

    // Copy constructor
    // For instance, a Triadic Float pointer is defined as tp_float a;
    // And somewhere another Triadic Float pointer is defined as tp_float b(a);
    // Then b = a means value and degree of b gets a's (value, degree) respectively.

    tp_float(tp_float &obj)
    {
        this->set_Degree_ptr(obj.get_Degree_ptr());
        this->set_value(obj.get_value());
    }
};

// Scan (or read) Triadic Float pointer's degree, value of pointer's variable, and degree of pointer's variable from console

void t_scan(tp_float &obj)
{
    t_float temp;
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

// Print (or output) Triadic Float pointer's degree, value of pointer and degree of pointer's value via console

void t_print(tp_float &obj)
{
    t_float temp;
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

// Scan (or read) Triadic Float pointer's degree, value of pointer's variable, and degree of pointer's variable from file

void t_scanfile(ifstream &fin, tp_float &obj)
{
    Degree d;
    t_float temp;
    int t;
    fin >> t;
    d = enum_convert(t);
    obj.set_Degree_ptr(d);
    t_scanfile(fin, temp);
    obj.set_pointer(temp);
}

// Print (or output) Triadic Float pointer's degree, value of pointer and degree of pointer's value via console

void t_printfile(ofstream &fout, tp_float &obj)
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
#endif /* tp_float.h */