#ifndef ttreenode_float_h
#define ttreenode_float_h
#include "../Array/Operator/datatypelinker.h"
#include "../Array/tarray_int.h"
#include "../Array/t_size.h"
class ttreenode_float
{
    tp_float data;

public:
    ttreenode_float *left = NULL;
    ttreenode_float *right = NULL;
    ttreenode_float()
    {
        // set limit on data
        data.set_Degree_ptr(L);
    }
    ttreenode_float(Degree degree, float value, Degree value_degree) // d =pointer degree,va=value of variable,vd=degree of value
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
    void set_node(Degree degree, float value, Degree value_degree)
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
    tp_float &get_node()
    {
        return data;
    }
    void set_node(ttreenode_float &obj)
    {
        tp_float v;
        v = obj.get_node();
        data = v;
    }

    ttreenode_float(tp_float _data)
    {
        data = _data;
    }
    void operator=(ttreenode_float obj)
    {
        data = obj.data;
        left = obj.left;
        right = obj.right;
    }
    ttreenode_float(ttreenode_float &obj)
    {
        data = obj.data;
        left = obj.left;
        right = obj.right;
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
void t_print(ttreenode_float obj)
{
    obj.p_data();
}
void t_scan(ttreenode_float &obj)
{
    obj.s_data();
}
void t_printfile(ofstream &fout, ttreenode_float obj)
{
    obj.fp_data(fout);
}
void t_scanfile(ifstream &fin, ttreenode_float &obj)
{
    obj.fs_data(fin);
}
#endif /* tnode_int_h*/