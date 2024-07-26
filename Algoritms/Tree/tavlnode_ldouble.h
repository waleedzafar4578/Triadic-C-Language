#ifndef tavlnode_ldouble_h
#define tavlnode_ldouble_h
#include "../Array/Operator/datatypelinker.h"
#include "../Array/tarray_int.h"
#include "../Array/t_size.h"
class tavlnode_ldouble
{
    tp_ldouble data;

public:
    tavlnode_ldouble *right;
    tavlnode_ldouble *left;
    int height;
    tavlnode_ldouble()
    {
        data.set_Degree_ptr(L);
    }
    tavlnode_ldouble(Degree degree, long double value, Degree value_degree, int _height)
    {
        data.set_Degree_ptr(degree);
        if (degree == T)
        {
            data.set_value(value);
            data.set_value_deg(value_degree);
        }
        height = _height;
    }
    tavlnode_ldouble(Degree degree, long double value, Degree value_degree)
    {
        data.set_Degree_ptr(degree);
        if (degree == T)
        {
            data.set_value(value);
            data.set_value_deg(value_degree);
        }
        right = NULL;
        left = NULL;
        height = 1;
    }
    void set_node(Degree degree, long double value, Degree value_degree, int _height)
    {
        data.set_Degree_ptr(degree);
        if (degree == T)
        {
            data.set_value(value);
            data.set_value_deg(value_degree);
        }
        height = _height;
    }
    tp_ldouble &get_node()
    {
        return data;
    }
    void set_node(tavlnode_ldouble &obj)
    {
        tp_ldouble v;
        v = obj.get_node();
        data = v;
    }
    tavlnode_ldouble(tp_ldouble _data)
    {
        data = _data;
        right = NULL;
        left = NULL;
        height = 1;
    }
    void operator=(tavlnode_ldouble obj)
    {
        data = obj.data;
        left = obj.left;
        right = obj.right;
        height = obj.height;
    }
    tavlnode_ldouble(tavlnode_ldouble &obj)
    {
        data = obj.data;
        left = obj.left;
        right = obj.right;
        height = obj.height;
    }
    int max(int a, int b) { return (a > b) ? a : b; }

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
void t_print(tavlnode_ldouble obj)
{
    obj.p_data();
}
void t_scan(tavlnode_ldouble &obj)
{
    obj.s_data();
}
void t_printfile(ofstream &fout, tavlnode_ldouble obj)
{
    obj.fp_data(fout);
}
void t_scanfile(ifstream &fin, tavlnode_ldouble &obj)
{
    obj.fs_data(fin);
}
int getHeight(tavlnode_ldouble *obj)
{
    if (obj == 0)
        return 0;
    return obj->height;
}
int getBalancingFactor(tavlnode_ldouble *obj)
{
    if (obj == NULL)
        return 0;
    return getHeight(obj->left) - getHeight(obj->right);
}
tavlnode_ldouble *rotateRight(tavlnode_ldouble *root)
{
    tavlnode_ldouble *leftSubTree_X = root->left;
    tavlnode_ldouble *rightSubTreeOf_X_y = leftSubTree_X->right;
    leftSubTree_X->right = root;
    root->left = rightSubTreeOf_X_y;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    leftSubTree_X->height = max(getHeight(leftSubTree_X->left), getHeight(leftSubTree_X->right)) + 1;
    return leftSubTree_X;
}
tavlnode_ldouble *rotateLeft(tavlnode_ldouble *root)
{
    tavlnode_ldouble *rightSubTree_X = root->right;
    tavlnode_ldouble *leftSubTreeOf_X_y = rightSubTree_X->left;
    rightSubTree_X->left = root;
    root->right = leftSubTreeOf_X_y;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    rightSubTree_X->height = max(getHeight(rightSubTree_X->left), getHeight(rightSubTree_X->right)) + 1;
    return rightSubTree_X;
}
#endif
