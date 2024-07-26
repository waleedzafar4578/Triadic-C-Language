#ifndef tdnode_char_h
#define tdnode_char_h
#include "../Array/Operator/datatypelinker.h"
class tdnode_char
{
    tp_char data;

public:
    tdnode_char *next = NULL;
    tdnode_char *prev = NULL;
    tdnode_char()
    {
        // set limit on data
        data.set_Degree_ptr(L);
    }
    tdnode_char(Degree degree, char value, Degree value_degree) // d =pointer degree,va=value of variable,vd=degree of value
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
    void set_node(Degree degree, char value, Degree value_degree)
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
    tp_char &get_node()
    {
        return data;
    }
    void set_node(tdnode_char &obj)
    {
        tp_char v;
        v = obj.get_node();
        data = v;
    }

    tdnode_char(tp_char _data)
    {
        data = _data;
    }
    void operator=(tdnode_char d)
    {
        data = d.data;
        next = d.next;
        prev = d.prev;
    }
    tdnode_char(tdnode_char &obj)
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
void t_print(tdnode_char obj)
{
    obj.p_data();
}
void t_scan(tdnode_char &obj)
{
    obj.s_data();
}
void t_printfile(ofstream &fout, tdnode_char obj)
{
    obj.fp_data(fout);
}
void t_scanfile(ifstream &fin, tdnode_char &obj)
{
    obj.fs_data(fin);
}
#endif /* tnode_int_h*/