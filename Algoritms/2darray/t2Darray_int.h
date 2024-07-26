#ifndef t_i2darray_h
#define t_i2darray_h

#include <iostream>
#include <fstream>
#include "../Array/Operator/datatypelinker.h"
// #include "t_size.h"
class t2Darray_int
{
private:
    tp_int **arr;
    int row;
    int col;

public:
    t2Darray_int()
    {
        arr = NULL;
    }
    t2Darray_int(int row, int col, Degree d = L)
    {
        this->row = row;
        this->col = col;
        arr = new tp_int *[row];
        for (int j = 0; j < row; j++)
        {
            arr[j] = new tp_int[col];
        }
        for (int j = 0; j < row; j++)
        {
            for (int i = 0; i < col; i++)
            {
                arr[j][i].set_Degree_ptr(d);
            }
        }
    }
    ~t2Darray_int()
    {

        delete[] arr;
    }
    void print()
    {
        for (int j = 0; j < row; j++)
        {
            for (int i = 0; i < col; i++)
            {
                t_print(arr[j][i]);
            }
        }
    }
    void print(int r, int c)
    {
        t_print(arr[r][c]);
    }
    void in()
    {
        for (int j = 0; j < row; j++)
        {
            for (int i = 0; i < col; i++)
            {
                t_scan(arr[j][i]);
            }
        }
    }
    void in(int r, int c)
    {
        if (r < row && c < col)
        {
            t_scan(arr[r][c]);
        }
        else
        {
            cout << "Please enter correct values." << endl;
        }
    }
    int numberOfRows()
    {
        return row;
    }
    int numberofColumns()
    {
        return col;
    }
    void set(int r, int c, Degree pd, int val = 0, Degree vd = L)
    {
        arr[r][c].set_Degree_ptr(pd);
        if (pd == T)
        {
            if (r < row && c < col)
            {
                arr[r][c].set_value(val);
                arr[r][c].set_value_deg(vd);
            }
        }
    }
    tp_int& get(int r, int c)
    {
        tp_int *t=new tp_int(0,L,T);
        if (r < row && c < col)
        {
            t[0].set_Degree_ptr(T);
            t[0].set_pointer(arr[r][c].get_value(),arr[r][c].get_Degree_val());
        }
        return *t;
    }
};

void t_scan(t2Darray_int &obj, int row, int col)
{
    obj.in(row, col);
}
void t_scan(t2Darray_int &obj)
{
    obj.in();
}

void t_print(t2Darray_int &obj, int row, int col)
{
    obj.print(row, col);
}

void t_print(t2Darray_int &obj)
{
    obj.print();
}
void t_set(t2Darray_int &obj, int row, int col, Degree pd, int val = 0, Degree vd = L)
{
    obj.set(row, col, pd, val, vd);
}
tp_int& t_get(t2Darray_int &obj, int row, int col){
    return obj.get(row,col);
}

#endif