// This file presents a unique datatype namely Triadic Boolean. 

#ifndef t_bool_h
#define t_bool_h
//----------------------------------------------------------------
#include "Enum/t_enum.h"
//----------------------

// Triadic Boolean class consists of a tuple: Boolean value (true or false) and Triadic degree (true, false, limit)
 
class t_bool
{
private:
    //
    bool value;
    Degree Deg;

// Class constructors: default and parameterized 

// default degree of Triadic Boolean variable is 'limit' (L).

public:
    t_bool()
    {
        Deg = L;
    }

 
   t_bool(bool v, Degree d = L)
    {
        value = v;
        Deg = d;
    }
    

// Class destuctor

    ~t_bool()
    {
    }

// Setter function to assign Triadic Boolean value

    void set_value(bool val)
    {
        value = val;
    }

// Setter function to assign Triadic degree

    void set_Degree(Degree d)
    {
        Deg = d;
    }

// Getter function to get/gain/collect Triadic Boolean value

    bool get_value()
    {

        return value;
    }

// Getter function to get/gain/collect Triadic degree

    Degree get_Degree()
    {
        return Deg;
    }

// Assignment operator for two Triadic Boolean variables

// For instance, two Triadic Boolean variables are defined as t_bool a, b; 
// then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    void operator=(t_bool obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }
  
// Copy constructor
// For instance, a Triadic Boolean variable is defined as t_bool a;
// And somewhere another Triadic Boolean variable is defined as t_bool b(a); 
// Then b = a means value and degree of b gets a's (value, degree) respectively.

    t_bool(t_bool &obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }
};

// Scan (or read) Triadic Boolean variable's value and degree from console

void t_scan(t_bool & obj)
{
    bool val;
    Degree deg;
    cout << "Value: ";
    cin >> val;
    obj.set_value(val);
    cout << "Degree: ";
    t_scan(deg);
    obj.set_Degree(deg);
}

// Print (or output) Triadic Boolean variable's value and degree both via console

void t_print(t_bool obj)
{
    cout << "Value: " << obj.get_value() << "------->Degree: " ;
     t_print(obj.get_Degree());
     cout<<endl;
}

// Scan (or read) Triadic Boolean variable's value via file

void t_scanfile(ifstream &fin, t_bool & obj)
{
    bool val;
    int i;
    Degree deg;
    fin>> val; obj.set_value(val);
    fin>> i; deg=enum_convert(i); obj.set_Degree(deg); 
}

// Print (or output) Triadic Boolean variable's value and degree both via file
 
void t_printfile(ofstream &fout, t_bool obj)
{
    fout << obj.get_value() << " " << obj.get_Degree() << endl;
}

#endif /* t_bool.h */