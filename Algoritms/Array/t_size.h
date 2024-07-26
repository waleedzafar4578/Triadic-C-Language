#ifndef t_size_h
#define t_size_h

#include <iostream>
#include <fstream>
#include "Operator/datatypelinker.h"
class t_size
{
private:
    Degree d;
    int size;
    int t_ptr_true;
    int t_ptr_limit;
    int t_val_true;
    int t_val_false;
    int t_val_limit;

public:
    t_size()
    {
        t_ptr_true = 0;
        t_ptr_limit = 0;
        t_val_true = 0;
        t_val_false = 0;
        t_val_limit = 0;
    }
    void set_size(int size) { this->size = size; }
    int get_size() { return size; }
    void set_degree(Degree d) { this->d = d; }
    Degree get_degree() { return this->d; }
    void inc_ptr_true() { t_ptr_true++; }
    void inc_ptr_limit() { t_ptr_limit++; }
    void reset_ptr_true() { t_ptr_true = 0; }
    void reset_ptr_limit() { t_ptr_limit = 0; }
    void inc_val_true() { t_val_true++; }
    void inc_val_false() { t_val_false++; }
    void inc_val_limit() { t_val_limit++; }
    void reset_val_true() { t_val_true = 0; }
    void reset_val_false() { t_val_false = 0; }
    void reset_val_limit() { t_val_limit = 0; }

    void set_ptr_true(int val) { t_ptr_true = val; }
    void set_ptr_limit(int val) { t_ptr_limit = val; }
    int get_ptr_true() { return t_ptr_true; }
    int get_ptr_limit() { return t_ptr_limit; }
    void set_val_true(int val) { t_val_true = val; }
    void set_val_false(int val) { t_val_false = val; }
    void set_val_limit(int val) { t_val_limit = val; }
    int get_val_true() { return t_val_true; }
    int get_val_false() { return t_val_false; }
    int get_val_limit() { return t_val_limit; }
    void reset(){
        t_ptr_true = 0;
        t_ptr_limit = 0;
        t_val_true = 0;
        t_val_false = 0;
        t_val_limit = 0;
    }
    void display_components()
    {
        cout << "Size: " << size << endl;
        cout << "Size Degree: ";
        t_print(d);
        cout << "Number of True pointer : " << t_ptr_true << endl;
        cout << "Number of Limit pointer : " << t_ptr_limit << endl;
        cout << "Number of True value : " << t_val_true << endl;
        cout << "Number of Limit value : " << t_val_limit << endl;
        cout << "Number of False value : " << t_val_false << endl;
    }
};

#endif