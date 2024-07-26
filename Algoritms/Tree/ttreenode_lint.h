#ifndef ttreenode_lint_h
#define ttreenode_lint_h
#include "../Array/Operator/datatypelinker.h"
#include "../Array/tarray_int.h"
#include "../Array/t_size.h"
class ttreenode_lint
{
    tp_lint data;

public:
    ttreenode_lint *left = NULL;
    ttreenode_lint *right = NULL;
    ttreenode_lint()
    {
        // set limit on data
        data.set_Degree_ptr(L);
    }
    ttreenode_lint(Degree degree, long int value, Degree value_degree) // d =pointer degree,va=value of variable,vd=degree of value
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
    void set_node(Degree degree, long int value, Degree value_degree)
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
    tp_lint &get_node()
    {
        return data;
    }
    void set_node(ttreenode_lint &obj)
    {
        tp_lint v;
        v = obj.get_node();
        data = v;
    }

    ttreenode_lint(tp_lint _data)
    {
        data = _data;
    }
    void operator=(ttreenode_lint obj)
    {
        data = obj.data;
        left = obj.left;
        right = obj.right;
    }
    ttreenode_lint(ttreenode_lint &obj)
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
void t_print(ttreenode_lint obj)
{
    obj.p_data();
}
void t_scan(ttreenode_lint &obj)
{
    obj.s_data();
}
void t_printfile(ofstream &fout, ttreenode_lint obj)
{
    obj.fp_data(fout);
}
void t_scanfile(ifstream &fin, ttreenode_lint &obj)
{
    obj.fs_data(fin);
}
#endif /* tnode_int_h*/