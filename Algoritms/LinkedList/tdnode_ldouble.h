#ifndef tdnode_ldouble_h
#define tdnode_ldouble_h
#include "../Array/Operator/datatypelinker.h"
class tdnode_ldouble
{
    tp_ldouble data;

public:
    tdnode_ldouble *next = NULL;
    tdnode_ldouble *prev = NULL;
    tdnode_ldouble()
    {
        // set limit on data
        data.set_Degree_ptr(L);
    }
    tdnode_ldouble(Degree degree, long double value, Degree value_degree) // d =pointer degree,va=value of variable,vd=degree of value
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
    void set_node(Degree degree, long double value, Degree value_degree)
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
    tp_ldouble &get_node()
    {
        return data;
    }
    void set_node(tdnode_ldouble &obj)
    {
        tp_ldouble v;
        v = obj.get_node();
        data = v;
    }

    tdnode_ldouble(tp_ldouble _data)
    {
        data = _data;
    }
    void operator=(tdnode_ldouble d)
    {
        data = d.data;
        next = d.next;
        prev = d.prev;
    }
    tdnode_ldouble(tdnode_ldouble &obj)
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
void t_print(tdnode_ldouble obj)
{
    obj.p_data();
}
void t_scan(tdnode_ldouble &obj)
{
    obj.s_data();
}
void t_printfile(ofstream &fout, tdnode_ldouble obj)
{
    obj.fp_data(fout);
}
void t_scanfile(ifstream &fin, tdnode_ldouble &obj)
{
    obj.fs_data(fin);
}
#endif /* tnode_int_h*/