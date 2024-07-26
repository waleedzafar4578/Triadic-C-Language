/* This file defines Triadic Double Array and relevant functions:

create, array size, get and set array, reset array, array's components w.r.t degrees, print and scan array

*/

#ifndef tarray_double_h
#define tarray_double_h

#include <iostream>
#include <fstream>
#include "Operator/datatypelinker.h"
#include "t_size.h"
class tarray_double
{

    // Triadic Intger array consists of Triadic integer pointer, integer index, and array size

private:
    tp_double*arr;
    int index;
    t_size size;

    // default constructor starting Triadic Array with 0 index and Null value.
public:
    tarray_double()
    {
        arr = NULL;
        index = 0;
    }

    // parameterized constructor with 0 index, array size and array degree

    tarray_double(int size, Degree d)
    {
        index = 0;
        this->size.set_size(size);
        this->size.set_degree(d);
        switch (d)
        {
        case T:
            arr = new tp_double[size];
            for (int i = 0; i < size; i++)
            {
                arr[i].set_Degree_ptr(d);
            }

            break;
        default:
            arr = new tp_double[size];
            break;
        }
    }

    // destructor

    ~tarray_double()
    {
        delete[] arr;
    }

    // Recreate new array with the same array size (previously given) and degree 'limit'.
    // Hint: change function's name

    void create_array(){
        int size=this->size.get_size();
        Degree d=L;
        this->size.set_degree(d);
        this->size.reset();
        index = 0;
        this->size.set_size(size);
        this->size.set_degree(d);

        switch (d)
        {
        case T:
            arr = new tp_double[size];
            for (int i = 0; i < size; i++)
            {
                arr[i].set_Degree_ptr(d);
            }

            break;
        default:
            arr = new tp_double[size];
            break;
        }
    }

    // Recreate new array using new array size and degree.
    // Hint: change function's name

    void create_array(int size,Degree d){
        this->size.set_size(size);
        this->size.set_degree(d);
        this->size.reset();
        index = 0;
        this->size.set_size(size);
        this->size.set_degree(d);

        switch (d)
        {
        case T:
            arr = new tp_double[size];
            for (int i = 0; i < size; i++)
            {
                arr[i].set_Degree_ptr(d);
            }

            break;
        default:
            arr = new tp_double[size];
            break;
        }
    }

    // Array size is returned.

    int get_size()
    {
        return size.get_size();
    }

    // Triadic Index is meant to be the Triadic Pointer's value (Triadic variable)

    tp_double get_pointer(int index)
    {
        return arr[index];
    }

    // Triadic variable's value is the actual index used by the Triadic Pointer

    void set_pointer_value(int &index, double&v)
    {
        arr[index].set_value(v);
    }

    // Triadic value's degee is the degree of the actual index used by the Triadic Pointer.

    void set_pointer_value_degree(int &index, Degree &d)
    {
        arr[index].set_value_deg(d);
    }

    // Triadic Pointer's value is the actual index used by the Triadic Pointer

    double get_pointer_value(int index)
    {
        return arr[index].get_value();
    }

    // Triadic Pointer's value has a triadic degree.

    Degree get_pointer_value_degree(int index)
    {
        return arr[index].get_Degree_val();
    }

    // Triadic Pointer's degree

    void s_indexD(int index, Degree d)
    {
        arr[index].set_Degree_ptr(d);
    }

    // Triadic Pointer's degree

    Degree g_indexD(int index)
    {
        return arr[index].get_Degree_ptr();
    }

    tp_double operator[](int index)
    {
        return arr[index];
    }

    // This is a special function within this class. This is used to get array's input.

    void input(double val, Degree d, int index)
    {
        arr[index].set_pointer(val, d);
    }

    // This is also a special function within this class. This is used when array is recreated (new array size)

    void reset_cl(int size)
    {
        if (arr != nullptr)
            delete[] arr;
        arr = nullptr;
        arr = new tp_double[size];
    }

    // This is also a special function within this class. This is used when array is recreated (default).

    void reset_cl()
    {
        if (arr != nullptr)
            delete[] arr;
        arr = nullptr;
    }

    // This calculates number of array indices with degree 'L', 'T', and 'F' respectively.
    // This is used primarily within this class.

    void compnent()
    {

        // if (size.get_degree() == T)
        {
            for (int i = 0; i < size.get_size(); i++)
            {
                if (arr[i].get_Degree_ptr() == T)
                {
                    size.inc_ptr_true();

                    if (arr[i].get_Degree_val() == T)
                    {
                        size.inc_val_true();
                    }
                    else if (arr[i].get_Degree_val() == F)
                    {
                        size.inc_val_false();
                    }
                    else{
                        size.inc_val_limit();
                    }


                }
                else
                {
                    size.inc_ptr_limit();
                }
            }
        }

        size.display_components();
    }
};

// End of Triadic Integer Array Class.

// This calculates number of array indices with degree 'L', 'T', and 'F' respectively.
// This is used primarily within this class.

void icomponent(tarray_double &obj)
{
    obj.compnent();
}

// Set degree of the Triadic Pointer's Index using parameter

void set_idegree(tarray_double &obj, int index, Degree d)
{
    obj.s_indexD(index, d);
}

// Set degree of the Triadic Pointer's Index using console

void set_idegree(tarray_double &obj, int index)
{
    char c;
    cout << "Degree:";
    cin >> c;
    Degree d = enum_convert(c);
    obj.s_indexD(index, d);
}

// Set degree of the Triadic Pointer's value using parameter

void set_vdegree(tarray_double &obj, int index, Degree d)
{
    obj.set_pointer_value_degree(index, d);
}

// Set degree of the Triadic Pointer's value using console

void set_vdegree(tarray_double &obj, int index)
{
    char c;
    cout << "Degree:";
    cin >> c;
    Degree d = enum_convert(c);
    obj.set_pointer_value_degree(index, d);
}

// Set value of the Triadic Pointer's value using parameter

void set_value(tarray_double &obj, int index, double val)
{
    obj.set_pointer_value(index, val);
}

// Set value of the Triadic Pointer's value using parameter

void set_value(tarray_double &obj, int index)
{
    double val;
    cout << "Value:";
    cin >> val;
    obj.set_pointer_value(index, val);
}

// Scan (or read) Array's value against given index only

void t_scan(tarray_double &obj, int index)
{

here:
    if (obj.g_indexD(index) == T)
    {
        double val;
        cout << "Value:";
        cin >> val;
        char c;
        cout << "Degree:";
        cin >> c;
        Degree d = enum_convert(c);
        obj.input(val, d, index);
    }
    else
    {
        cout << "Please First set index degree true then take scan." << endl;
        cout << "If you want to set index degree True." << endl;
        cout << "Press 1 for True:" << endl;
        cout << "Press 2 for exit:" << endl;
        int i;
        cin >> i;
        if (i == 1)
        {
            obj.s_indexD(index, T);
            goto here;
        }
    }
}

// Scan (or read) Array's values and their degrees within starting and ending indices range

void t_scan(tarray_double &obj, int sindex, int eindex)
{
    for (int i = sindex; i < eindex; i++)
    {
        if (obj.g_indexD(i) == T)
        {
            int val;
            cout << "Value:";
            cin >> val;
            char c;
            cout << "Degree:";
            cin >> c;
            Degree d = enum_convert(c);
            obj.input(val, d, i);
        }
        else
        {
            cout << "Please First set index degree true then take scan."
                 << "Index:" << i << endl;
        }
    }
}

// Scan (or read) complete Array's values and their degrees

void t_scan(tarray_double &obj)
{
    for(int i = 0; i < obj.get_size(); i++)
    {
        if (obj.g_indexD(i) == T)
        {
            double val;
            cout << "Value:";
            cin >> val;
            char c;
            cout << "Degree:";
            cin >> c;
            Degree d = enum_convert(c);
            obj.input(val, d, i);
        }
        else
        {
            cout << "Please First set index degree true then take scan."
                 << "Index:" << i << endl;
        }
    }
}

// Print (or Output) only given index of the Triadic Array

void t_print(tarray_double &obj, int index)
{
    if (obj.g_indexD(index) == T)
    {
        cout <<"Value: "<< obj.get_pointer_value(index) <<" -----> Degree:";
        Degree d = obj.get_pointer_value_degree(index);
        t_print(d);
    }
    else
    {
        cout << "Index:" << index << " Is not available" << endl;
    }
}

// Print (or Output) Triadic Array within starting and ending indices range.

void t_print(tarray_double &obj, int sindex, int eindex)
{

    for (int i = sindex; i < eindex; i++)
    {
        if (obj.g_indexD(i) == T)
        {
            cout <<"Value: "<< obj.get_pointer_value(i) <<" -----> Degree:";
            Degree d = obj.get_pointer_value_degree(i);
            t_print(d);
        }
        else{
            cout<<"This index not avalible."<<endl;
        }
    }
}

// Print (or Output) complete  Triadic Array

void t_print(tarray_double &obj)
{
    for(int i = 0; i < obj.get_size(); i++)
    {
        if (obj.g_indexD(i) == T)
        {
            cout <<"Value: "<< obj.get_pointer_value(i) <<" -----> Degree:";
            Degree d = obj.get_pointer_value_degree(i);
            t_print(d);
        }
        else{
            cout<<"This index not avalible."<<endl;
        }
    }
}

// Reset Triadic Array to call recreate (or new) Triadic Array.
// This reset Triadic array to use previous array size and degree.

void reset(tarray_double &obj)
{
   obj.create_array();
}

    // Reset Triadic Array to call recreate (or new) Triadic Array. 
	// This reset Triadic array to use new array size and degree.
	// Missing
    
#endif