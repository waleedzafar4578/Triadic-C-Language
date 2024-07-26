#ifndef tp_char_h
#define tp_char_h

//----------------------------------------------------------------
#include "t_char.h"

// Triadic Character Pointer class consists of a tuple: Character pointer's value (pointer) and Triadic pointer's degree (true, false, limit)

class tp_char
{
private:
    // here creating pointer because we assign null as default value
    t_char *value;
    Degree Deg;

    // Class constructors: default and parameterized

    // default value of Triadic Character pointer is null pointer
    // degree of Triadic Character pointer is 'limit' (L).

public:
    tp_char()
    {
        value = nullptr;
        Deg = L;
    }

    // parameterized Triadic Character Pointer (pointer's value, pointer's degree, degree of pointer's value)

    tp_char(char v, Degree p_d = L, Degree d_d = L)
    {
        switch (p_d)
        {
        case T:
            value = new t_char(v, d_d);
            Deg = p_d;
            break;
        default:
            value = nullptr;
            Deg = p_d;
            break;
        }
    }

    // Class destuctor
    ~tp_char()
    {
        if (value != nullptr)
        {
            delete value;
        }
        value = nullptr;
    }

    // Setter function to assign Triadic Character Pointer's value: Triadic Character variable
    // It only works when Triadic Character pointer's degree is True.

    void set_pointer(t_char val)
    {
        if (value != nullptr)
        {
            value[0].set_Degree(val.get_Degree());
            value[0].set_value(val.get_value());
        }
    }

    // Setter function to assign Triadic Character Pointer's value (char) and value's degree.
    // It only works when Triadic Character pointer's degree is True.

    void set_pointer(char val, Degree d)
    {
        if (value != nullptr)
        {
            value[0].set_Degree(d);
            value[0].set_value(val);
        }
    }

    // Setter function to assign Triadic Character Pointer's value (char)

    void set_value(const char &val)
    {
        if (value != nullptr)
        {
            value[0].set_value(val);
        }
    }

    // Setter function to assign degree of Triadic Character Pointer's valu

    void set_value_deg(Degree d)
    {

        value[0].set_Degree(d);
    }

    // Setter function to assign Triadic Character Pointer's degree

    void set_Degree_ptr(Degree d)
    {
        Deg = d;
        switch (d)
        {
        case T:
            if (value == nullptr)
                value = new t_char(0);
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

    // Getter function to get/gain/collect Triadic Character Pointer's value (char)

    char get_value()
    {
        if (Deg == T)
            return value[0].get_value();
        else
            return -1;
    }

    // Getter function to get/gain/collect Triadic Character Pointer's value (Triadic char)

    t_char get_pointer()
    {
        t_char temp;
        if (Deg == T)
            temp = value[0];
        return temp;
    }

    // Getter function to get/gain/collect Triadic Character Pointer's degree

    Degree get_Degree_ptr()
    {
        return Deg;
    }

    // Getter function to get/gain/collect degree of the Triadic Character Pointer's value (char)

    Degree get_Degree_val()
    {
        if (Deg == T)
            return value[0].get_Degree();
        else
        {
            return L;
        }
    }

    // Assignment operator for two Triadic Character pointers

    // For instance, two Triadic Character pointers are defined as tp_char a, b;
    // then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    tp_char &operator=(tp_char &obj)
    {
        set_Degree_ptr(obj.get_Degree_ptr());
        value = new t_char;
        *(value) = obj.get_pointer();
        return *this;
    }

    // Copy constructor
    // For instance, a Triadic Character pointer is defined as tp_char a;
    // And somewhere another Triadic Character pointer is defined as tp_char b(a);
    // Then b = a means value and degree of b gets a's (value, degree) respectively.

    tp_char(tp_char &obj)
    {
        this->set_Degree_ptr(obj.get_Degree_ptr());
        this->set_value(obj.get_value());
    }
};

// Scan (or read) Triadic Character pointer's degree, value of pointer's variable, and degree of pointer's variable from console

void t_scan(tp_char &obj)
{
    t_char temp;
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

// Print (or output) Triadic Character pointer's degree, value of pointer and degree of pointer's value via console

void t_print(tp_char &obj)
{
    t_char temp;
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

// Scan (or read) Triadic Character pointer's degree, value of pointer's variable, and degree of pointer's variable from file

void t_scanfile(ifstream &fin, tp_char &obj)
{
    Degree d;
    t_char temp;
    int t;
    fin >> t;
    d = enum_convert(t);
    obj.set_Degree_ptr(d);
    t_scanfile(fin, temp);
    obj.set_pointer(temp);
}

// Print (or output) Triadic Character pointer's degree, value of pointer and degree of pointer's value via console

void t_printfile(ofstream &fout, tp_char &obj)
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
#endif /* tp_char.h */