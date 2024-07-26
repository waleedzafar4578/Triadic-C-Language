#ifndef tdnode_double_h
#define tdnode_double_h
#include "../Array/Operator/datatypelinker.h"
class tdnode_double
{
    tp_double data;

public:
    tdnode_double *next = NULL;
    tdnode_double *prev = NULL;
    tdnode_double()
    {
        // set limit on data
        data.set_Degree_ptr(L);
    }
    tdnode_double(Degree degree, double value, Degree value_degree) // d =pointer degree,va=value of variable,vd=degree of value
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
    void set_node(Degree degree, double value, Degree value_degree)
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
    tp_double &get_node()
    {
        return data;
    }
    void set_node(tdnode_double &obj)
    {
        tp_double v;
        v = obj.get_node();
        data = v;
    }

    tdnode_double(tp_double _data)
    {
        data = _data;
    }
    void operator=(tdnode_double d)
    {
        data = d.data;
        next = d.next;
        prev = d.prev;
    }
    tdnode_double(tdnode_double &obj)
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
void t_print(tdnode_double obj)
{
    obj.p_data();
}
void t_scan(tdnode_double &obj)
{
    obj.s_data();
}
void t_printfile(ofstream &fout, tdnode_double obj)
{
    obj.fp_data(fout);
}
void t_scanfile(ifstream &fin, tdnode_double &obj)
{
    obj.fs_data(fin);
}
#endif /* tnode_int_h*/