#ifndef tp_bool_h
#define tp_bool_h

//----------------------------------------------------------------
#include "t_bool.h"

// Triadic Boolean Pointer class consists of a tuple: Boolean pointer's value (pointer) and Triadic pointer's degree (true, false, limit)

class tp_bool
{
private:
    // here creating pointer because we assign null as default value
    t_bool *value;
    Degree Deg;

    // Class constructors: default and parameterized

    // default value of Triadic Boolean pointer is null pointer
    // degree of Triadic Boolean pointer is 'limit' (L).

public:
    tp_bool()
    {
        value = nullptr;
        Deg = L;
    }

    // parameterized Triadic Boolean Pointer (pointer's value, pointer's degree, degree of pointer's value)

    tp_bool(bool v, Degree p_d = L, Degree d_d = L)
    {
        switch (p_d)
        {
        case T:
            value = new t_bool(v, d_d);
            Deg = p_d;
            break;
        default:
            value = nullptr;
            Deg = p_d;
            break;
        }
    }

    // Class destuctor
    ~tp_bool()
    {
        if (value != nullptr)
        {
            delete value;
        }
        value = nullptr;
    }

    // Setter function to assign Triadic Boolean Pointer's value: Triadic Boolean variable
    // It only works when Triadic Boolean pointer's degree is True.

    void set_pointer(t_bool val)
    {
        if (value != nullptr)
        {
            value[0].set_Degree(val.get_Degree());
            value[0].set_value(val.get_value());
        }
    }

    // Setter function to assign Triadic Boolean Pointer's value (bool) and value's degree.
    // It only works when Triadic Boolean pointer's degree is True.

    void set_pointer(bool val, Degree d)
    {
        if (value != nullptr)
        {
            value[0].set_Degree(d);
            value[0].set_value(val);
        }
    }

    // Setter function to assign Triadic Boolean Pointer's value (bool)

    void set_value(bool val)
    {
        if (value != nullptr)
        {
            value[0].set_value(val);
        }
    }

    // Setter function to assign degree of Triadic Boolean Pointer's value

    void set_value_deg(Degree d)
    {

        value[0].set_Degree(d);
    }

    // Setter function to assign Triadic Boolean Pointer's degree

    void set_Degree_ptr(Degree d)
    {
        Deg = d;
        switch (d)
        {
        case T:
            if (value == nullptr)
                value = new t_bool(0);
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

    // Getter function to get/gain/collect Triadic Boolean Pointer's value (bool)

    bool get_value()
    {
        if (Deg == T)
            return value[0].get_value();
        else
            return -1;
    }

    // Getter function to get/gain/collect Triadic Boolean Pointer's value (Triadic Bool)

    t_bool get_pointer()
    {
        t_bool temp;
        if (Deg == T)
            temp = value[0];
        return temp;
    }

    // Getter function to get/gain/collect Triadic Boolean Pointer's degree

    Degree get_Degree_ptr()
    {
        return Deg;
    }

    // Getter function to get/gain/collect degree of the Triadic Boolean Pointer's value (bool)

    Degree get_Degree_val()
    {
        if (Deg == T)
            return value[0].get_Degree();
        else
        {
            return L;
        }
    }

    // Assignment operator for two Triadic Boolean pointers

    // For instance, two Triadic Boolean pointers are defined as tp_bool a, b;
    // then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    void operator=(tp_bool obj)
    {
        this->set_Degree_ptr(obj.get_Degree_ptr());
        this->set_value(obj.get_value());
    }

    // Copy constructor
    // For instance, a Triadic Boolean pointer is defined as tp_bool a;
    // And somewhere another Triadic Boolean pointer is defined as tp_bool b(a);
    // Then b = a means value and degree of b gets a's (value, degree) respectively.

    tp_bool(tp_bool &obj)
    {
        this->set_Degree_ptr(obj.get_Degree_ptr());
        this->set_value(obj.get_value());
    }
};

// Scan (or read) Triadic Boolean pointer's degree, value of pointer's variable, and degree of pointer's variable from console

void t_scan(tp_bool &obj)
{
    t_bool temp;
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

// Print (or output) Triadic Boolean pointer's degree, value of pointer and degree of pointer's value via console

void t_print(tp_bool &obj)
{
    t_bool temp;
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

// Scan (or read) Triadic Boolean pointer's degree, value of pointer's variable, and degree of pointer's variable from file

void t_scanfile(ifstream &fin, tp_bool &obj)
{
    Degree d;
    t_bool temp;
    int t;
    fin >> t;
    d = enum_convert(t);
    obj.set_Degree_ptr(d);
    t_scanfile(fin, temp);
    obj.set_pointer(temp);
}

// Print (or output) Triadic Boolean pointer's degree, value of pointer and degree of pointer's value via console

void t_printfile(ofstream &fout, tp_bool &obj)
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

#endif /* tp_bool.h */