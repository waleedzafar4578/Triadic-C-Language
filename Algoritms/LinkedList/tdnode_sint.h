#ifndef tdnode_sint_h
#define tdnode_sint_h
#include "../Array/Operator/datatypelinker.h"
class tdnode_sint
{
    tp_sint data;

public:
    tdnode_sint *next = NULL;
    tdnode_sint *prev = NULL;
    tdnode_sint()
    {
        // set limit on data
        data.set_Degree_ptr(L);
    }
    tdnode_sint(Degree degree, short int value, Degree value_degree) // d =pointer degree,va=value of variable,vd=degree of value
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
    void set_node(Degree degree, short int value, Degree value_degree)
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
    tp_sint &get_node()
    {
        return data;
    }
    void set_node(tdnode_sint &obj)
    {
        tp_sint v;
        v = obj.get_node();
        data = v;
    }

    tdnode_sint(tp_sint _data)
    {
        data = _data;
    }
    void operator=(tdnode_sint d)
    {
        data = d.data;
        next = d.next;
        prev = d.prev;
    }
    tdnode_sint(tdnode_sint &obj)
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
void t_print(tdnode_sint obj)
{
    obj.p_data();
}
void t_scan(tdnode_sint &obj)
{
    obj.s_data();
}
void t_printfile(ofstream &fout, tdnode_sint obj)
{
    obj.fp_data(fout);
}
void t_scanfile(ifstream &fin, tdnode_sint &obj)
{
    obj.fs_data(fin);
}
#endif /* tnode_int_h*/