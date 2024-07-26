#ifndef tdnode_bool_h
#define tdnode_bool_h
#include "../Array/Operator/datatypelinker.h"
class tdnode_bool
{
    tp_bool data;

public:
    tdnode_bool *next = NULL;
    tdnode_bool *prev = NULL;
    tdnode_bool()
    {
        // set limit on data
        data.set_Degree_ptr(L);
    }
    tdnode_bool(Degree degree, bool value, Degree value_degree) // d =pointer degree,va=value of variable,vd=degree of value
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
    void set_node(Degree degree, bool value, Degree value_degree)
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
    tp_bool &get_node()
    {
        return data;
    }
    void set_node(tdnode_bool &obj)
    {
        tp_bool v;
        v = obj.get_node();
        data = v;
    }

    tdnode_bool(tp_bool _data)
    {
        data = _data;
    }
    void operator=(tdnode_bool d)
    {
        data = d.data;
        next = d.next;
        prev = d.prev;
    }
    tdnode_bool(tdnode_bool &obj)
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
void t_print(tdnode_bool obj)
{
    obj.p_data();
}
void t_scan(tdnode_bool &obj)
{
    obj.s_data();
}
void t_printfile(ofstream &fout, tdnode_bool obj)
{
    obj.fp_data(fout);
}
void t_scanfile(ifstream &fin, tdnode_bool &obj)
{
    obj.fs_data(fin);
}
#endif /* tnode_int_h*/