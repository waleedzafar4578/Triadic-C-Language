#ifndef tp_string_h
#define tp_string_h

//----------------------------------------------------------------
#include "t_string.h"

// Triadic String Pointer class consists of a tuple: String pointer's value (pointer) and Triadic pointer's degree (true, false, limit)

class tp_string
{
private:
    // here creating pointer because we assign null as default value
    t_string *value;
    Degree Deg;

    // Class constructors: default and parameterized

    // default value of Triadic String pointer is null pointer
    // degree of Triadic String pointer is 'limit' (L).

public:
    tp_string()
    {
        value = nullptr;
        Deg = L;
    }

    // parameterized Triadic String Pointer (pointer's value, pointer's degree, degree of pointer's value)

    tp_string(string v, Degree p_d = L, Degree d_d = L)
    {
        switch (p_d)
        {
        case T:
            value = new t_string(v, d_d);
            Deg = p_d;
            break;
        default:
            value = nullptr;
            Deg = p_d;
            break;
        }
    }

    // Class destuctor
    ~tp_string()
    {
        if (value != nullptr)
        {
            delete value;
        }
        value = nullptr;
    }

    // Setter function to assign Triadic String Pointer's value: Triadic String variable
    // It only works when Triadic String pointer's degree is True.

    void set_pointer(t_string val)
    {
        if (value != nullptr)
        {
            value[0].set_Degree(val.get_Degree());
            value[0].set_value(val.get_value());
        }
    }

    // Setter function to assign Triadic String Pointer's value (string) and value's degree.
    // It only works when Triadic String pointer's degree is True.

    void set_pointer(string val, Degree d)
    {
        if (value != nullptr)
        {
            value[0].set_Degree(d);
            value[0].set_value(val);
        }
    }

    // Setter function to assign Triadic String Pointer's value (string)

    void set_value(string val)
    {
        if (value != nullptr)
        {
            value[0].set_value(val);
        }
    }

    // Setter function to assign degree of Triadic String Pointer's value

    void set_value_deg(Degree d)
    {

        value[0].set_Degree(d);
    }

    // Setter function to assign Triadic String Pointer's degree

    void set_Degree_ptr(Degree d)
    {
        Deg = d;
        switch (d)
        {
        case T:
            if (value == nullptr)
                value = new t_string(0);
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

    // Getter function to get/gain/collect Triadic String Pointer's value (string)

    string get_value()
    {
        if (Deg == T)
            return value[0].get_value();
        else
            return "";
    }

    // Getter function to get/gain/collect Triadic String Pointer's value (Triadic string)

    t_string get_pointer()
    {
        t_string temp;
        if (Deg == T)
            temp = value[0];
        return temp;
    }

    // Getter function to get/gain/collect Triadic String Pointer's degree

    Degree get_Degree_ptr()
    {
        return Deg;
    }

    // Getter function to get/gain/collect degree of the Triadic String Pointer's value (string)

    Degree get_Degree_val()
    {
        if (Deg == T)
            return value[0].get_Degree();
        else
        {
            return L;
        }
    }

    // Assignment operator for two Triadic String pointers

    // For instance, two Triadic String pointers are defined as tp_string a, b;
    // then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    tp_string &operator=(tp_string &obj)
    {
        set_Degree_ptr(obj.get_Degree_ptr());
        value = new t_string;
        *(value) = obj.get_pointer();
        return *this;
    }

    // Copy constructor
    // For instance, a Triadic String pointer is defined as tp_string a;
    // And somewhere another Triadic String pointer is defined as tp_string b(a);
    // Then b = a means value and degree of b gets a's (value, degree) respectively.

    tp_string(tp_string &obj)
    {
        this->set_Degree_ptr(obj.get_Degree_ptr());
        this->set_value(obj.get_value());
    }
};

// Scan (or read) Triadic String pointer's degree, value of pointer's variable, and degree of pointer's variable from console

void t_scan(tp_string &obj)
{
    t_string temp;
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

// Print (or output) Triadic String pointer's degree, value of pointer and degree of pointer's value via console

void t_print(tp_string &obj)
{
    t_string temp;
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

// Scan (or read) Triadic String pointer's degree, value of pointer's variable, and degree of pointer's variable from file

void t_scanfile(ifstream &fin, tp_string &obj)
{
    Degree d;
    t_string temp;
    int t;
    fin >> t;
    d = enum_convert(t);
    obj.set_Degree_ptr(d);
    t_scanfile(fin, temp);
    obj.set_pointer(temp);
}

// Print (or output) Triadic String pointer's degree, value of pointer and degree of pointer's value via console

void t_printfile(ofstream &fout, tp_string &obj)
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
#endif /* tp_string.h */