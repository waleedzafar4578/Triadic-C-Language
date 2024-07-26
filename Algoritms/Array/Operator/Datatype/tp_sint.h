#ifndef tp_sint_h
#define tp_sint_h

//----------------------------------------------------------------
#include "t_sint.h"

// Triadic Short Integer Pointer class consists of a tuple: Short Integer pointer's value (pointer) and Triadic pointer's degree (true, false, limit)

class tp_sint
{
private:
    // here creating pointer because we assign null as default value
    t_sint *value;
    Degree Deg;

    // Class constructors: default and parameterized

    // default value of Triadic Short Integer pointer is null pointer
    // degree of Triadic Short Integer pointer is 'limit' (L).

public:
    tp_sint()
    {
        value = nullptr;
        Deg = L;
    }

    // parameterized Triadic Short Integer Pointer (pointer's value, pointer's degree, degree of pointer's value)

    tp_sint(short int v, Degree p_d = L, Degree d_d = L)
    {
        switch (p_d)
        {
        case T:
            value = new t_sint(v, d_d);
            Deg = p_d;
            break;
        default:
            value = nullptr;
            Deg = p_d;
            break;
        }
    }

    // Class destuctor
    ~tp_sint()
    {
        if (value != nullptr)
        {
            delete value;
        }
        value = nullptr;
    }

    // Setter function to assign Triadic Short Integer Pointer's value: Triadic Short Integer variable
    // It only works when Triadic Short Integer pointer's degree is True.

    void set_pointer(t_sint val)
    {
        if (value != nullptr)
        {
            value[0].set_Degree(val.get_Degree());
            value[0].set_value(val.get_value());
        }
    }

    // Setter function to assign Triadic Short Integer Pointer's value (sint) and value's degree.
    // It only works when Triadic Short Integer pointer's degree is True.

    void set_pointer(short int val, Degree d)
    {
        if (value != nullptr)
        {
            value[0].set_Degree(d);
            value[0].set_value(val);
        }
    }

    // Setter function to assign Triadic Short Integer Pointer's value (sint)

    void set_value(short int val)
    {
        if (value != nullptr)
        {
            value[0].set_value(val);
        }
    }

    // Setter function to assign degree of Triadic Short Integer Pointer's value

    void set_value_deg(Degree d)
    {

        value[0].set_Degree(d);
    }

    // Setter function to assign Triadic Short Integer Pointer's degree

    void set_Degree_ptr(Degree d)
    {
        Deg = d;
        switch (d)
        {
        case T:
            if (value == nullptr)
                value = new t_sint(0);
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

    // Getter function to get/gain/collect Triadic Short Integer Pointer's value (sint)

    short int get_value()
    {
        if (Deg == T)
            return value[0].get_value();
        else
            return -1;
    }

    // Getter function to get/gain/collect Triadic Short Integer Pointer's value (Triadic sint)

    t_sint get_pointer()
    {
        t_sint temp;
        if (Deg == T)
            temp = value[0];
        return temp;
    }

    // Getter function to get/gain/collect Triadic Short Integer Pointer's degree

    Degree get_Degree_ptr()
    {
        return Deg;
    }

    // Getter function to get/gain/collect degree of the Triadic Short Integer Pointer's value (sint)

    Degree get_Degree_val()
    {
        if (Deg == T)
            return value[0].get_Degree();
        else
        {
            return L;
        }
    }
    
     // Assignment operator for two Triadic Short Integer pointers

    // For instance, two Triadic Short Integer pointers are defined as tp_sint a, b;
    // then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    tp_sint &operator=(tp_sint &obj)
    {
        set_Degree_ptr(obj.get_Degree_ptr());
        value = new t_sint;
        *(value) = obj.get_pointer();
        return *this;
    }
    
    // Copy constructor
    // For instance, a Triadic Short Integer pointer is defined as tp_sint a;
    // And somewhere another Triadic Short Integer pointer is defined as tp_sint b(a);
    // Then b = a means value and degree of b gets a's (value, degree) respectively.

    tp_sint(tp_sint &obj)
    {
        this->set_Degree_ptr(obj.get_Degree_ptr());
        this->set_value(obj.get_value());
    }
};

// Scan (or read) Triadic Short Integer pointer's degree, value of pointer's variable, and degree of pointer's variable from console

void t_scan(tp_sint &obj)
{
    t_sint temp;
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

// Print (or output) Triadic Short Integer pointer's degree, value of pointer and degree of pointer's value via console

void t_print(tp_sint &obj)
{
    t_sint temp;
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

// Scan (or read) Triadic Short Integer pointer's degree, value of pointer's variable, and degree of pointer's variable from file

void t_scanfile(ifstream &fin, tp_sint &obj)
{
    Degree d;
    t_sint temp;
    int t;
    fin >> t;
    d = enum_convert(t);
    obj.set_Degree_ptr(d);
    t_scanfile(fin, temp);
    obj.set_pointer(temp);
}

// Print (or output) Triadic Short Integer pointer's degree, value of pointer and degree of pointer's value via console

void t_printfile(ofstream &fout, tp_sint &obj)
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
#endif /* tp_sint.h */