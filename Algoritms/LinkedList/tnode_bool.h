#ifndef tnode_int_h
#define tnode_int_h
#include "../Array/Operator/datatypelinker.h"
class tnode_bool
{
    tp_bool data;

public:
    tnode_bool *next = NULL;
    tnode_bool()
    {
        // set limit on data
        data.set_Degree_ptr(L);
    }
    tnode_bool(Degree degree, bool value, Degree value_degree) // d =pointer degree,va=value of variable,vd=degree of value
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
    void set_node(tnode_bool &obj)
    {
        tp_bool v;
        v = obj.get_node();
        data = v;
    }

    tnode_bool(tp_bool _data)
    {
        data = _data;
    }
    void operator=(tnode_bool d)
    {
        data = d.data;
        next = d.next;
    }
    tnode_bool(tnode_bool &obj)
    {
        data = obj.data;
        next = obj.next;
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
void t_print(tnode_bool obj)
{
    obj.p_data();
}
void t_scan(tnode_bool &obj)
{
    obj.s_data();
}
void t_printfile(ofstream &fout, tnode_bool obj)
{
    obj.fp_data(fout);
}
void t_scanfile(ifstream &fin, tnode_bool &obj)
{
    obj.fs_data(fin);
}
#endif /* tnode_int_h*/