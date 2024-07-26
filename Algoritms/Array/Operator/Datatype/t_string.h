// This file presents a unique datatype namely Triadic String. 

#ifndef t_string_h
#define t_string_h

//----------------------------------------------------------------
#include<string>
#include "Enum/t_enum.h"
//----------------------

// Triadic String class consists of a tuple: String value (true or false) and Triadic degree (true, false, limit)
 
class t_string
{
private:
    //
    string value;
    Degree Deg;

// Class constructors: default and parameterized 

// default degree of Triadic String variable is 'limit' (L).

public:
    t_string()
    {
        Deg = L;
    }

 
   t_string(string v, Degree d = L)
    {
        value = v;
        Deg = d;
    }
    

// Class destuctor

    ~t_string()
    {
    }

// Setter function to assign Triadic String value

    void set_value(string val)
    {
        value = val;
    }

// Setter function to assign Triadic degree

    void set_Degree(Degree d)
    {
        Deg = d;
    }

// Getter function to get/gain/collect Triadic String value

    string get_value()
    {

        return value;
    }

// Getter function to get/gain/collect Triadic degree

    Degree get_Degree()
    {
        return Deg;
    }

// Assignment operator for two Triadic String variables

// For instance, two Triadic String variables are defined as t_string a, b; 
// then, a = b means value and degree of Triadic a gets Triadic b's (value, degree).

    void operator=(t_string obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }
  
// Copy constructor
// For instance, a Triadic String variable is defined as t_string a;
// And somewhere another Triadic String variable is defined as t_string b(a); 
// Then b = a means value and degree of b gets a's (value, degree) respectively.

    t_string(t_string &obj)
    {
        this->set_value(obj.get_value());
        this->set_Degree(obj.get_Degree());
    }
};

// Scan (or read) Triadic String variable's value and degree from console

void t_scan(t_string & obj)
{
    string val;
    Degree deg;
    cout << "Value: ";
    cin >> val;
    obj.set_value(val);
    cout << "Degree: ";
    t_scan(deg);
    obj.set_Degree(deg);
}

// Print (or output) Triadic String variable's value and degree both via console

void t_print(t_string obj)
{
    cout << "Value: " << obj.get_value() << "------->Degree: " ;
     t_print(obj.get_Degree());
     cout<<endl;
}

// Scan (or read) Triadic String variable's value via file

void t_scanfile(ifstream &fin, t_string & obj)
{
    string val;
    int i;
    Degree deg;
    fin>> val; obj.set_value(val);
    fin>> i; deg=enum_convert(i); obj.set_Degree(deg); 
}

// Print (or output) Triadic String variable's value and degree both via file
 
void t_printfile(ofstream &fout, t_string obj)
{
    fout << obj.get_value() << " " << obj.get_Degree() << endl;
}

#endif