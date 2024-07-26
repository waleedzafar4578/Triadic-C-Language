#ifndef tdnode_int_h
#define tdnode_int_h
#include "../Array/Operator/datatypelinker.h"
class tdnode_int
{
    tp_int data;

public:
    tdnode_int *next = NULL;
    tdnode_int *prev = NULL;
    tdnode_int()
    {
        // set limit on data
        data.set_Degree_ptr(L);
    }
    tdnode_int(Degree degree, int value, Degree value_degree) // d =pointer degree,va=value of variable,vd=degree of value
    {
        // set limit on data
        data.set_Degree_ptr(degree);
        if (degree == T)
        {
            // data.set_pointer(va,vd);
            data.set_value(value);
            data.set_value_deg(value_degree);
        }
    }
    void set_node(Degree degree, int value, Degree value_degree)
    {
        // set limit on data
        data.set_Degree_ptr(degree);
        if (degree == T)
        {
            // data.set_pointer(va,vd);
            data.set_value(value);
            data.set_value_deg(value_degree);
        }
    }
    tp_int &get_node()
    {
        return data;
    }
    void set_node(tdnode_int &obj)
    {
        tp_int v;
        v = obj.get_node();
        data = v;
    }

    tdnode_int(tp_int _data)
    {
        data = _data;
    }
    void operator=(tdnode_int d)
    {
        data = d.data;
        next = d.next;
        prev = d.prev;
    }
    tdnode_int(tdnode_int &obj)
    {
        data = obj.data;
        next = obj.next;
        prev = obj.prev;
    }
    // help to printing data on console
    void p_data()
    {
        t_print(data);
    }
    void s_data()
    {
        t_scan(data);
    }
    void fp_data(ofstream &fout)
    {
        t_printfile(fout, data);
    }
    void fs_data(ifstream &fin)
    {
        t_scanfile(fin, data);
    }
};
void t_print(tdnode_int obj)
{
    obj.p_data();
}
void t_scan(tdnode_int &obj)
{
    obj.s_data();
}
void t_printfile(ofstream &fout, tdnode_int obj)
{
    obj.fp_data(fout);
}
void t_scanfile(ifstream &fin, tdnode_int &obj)
{
    obj.fs_data(fin);
}
#endif /* tnode_int_h*/