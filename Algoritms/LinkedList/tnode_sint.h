#ifndef tnode_sint_h
#define tnode_sint_h
#include "../Array/Operator/datatypelinker.h"
class tnode_sint
{
    tp_sint data;

public:
    tnode_sint *next = NULL;
    tnode_sint()
    {
        // set limit on data
        data.set_Degree_ptr(L);
    }
    tnode_sint(Degree degree, short int value, Degree value_degree) // d =pointer degree,va=value of variable,vd=degree of value
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
    void set_node(tnode_sint &obj)
    {
        tp_sint v;
        v = obj.get_node();
        data = v;
    }

    tnode_sint(tp_sint _data)
    {
        data = _data;
    }
    void operator=(tnode_sint d)
    {
        data = d.data;
        next = d.next;
    }
    tnode_sint(tnode_sint &obj)
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
void t_print(tnode_sint obj)
{
    obj.p_data();
}
void t_scan(tnode_sint &obj)
{
    obj.s_data();
}
void t_printfile(ofstream &fout, tnode_sint obj)
{
    obj.fp_data(fout);
}
void t_scanfile(ifstream &fin, tnode_sint &obj)
{
    obj.fs_data(fin);
}
#endif /* tnode_int_h*/