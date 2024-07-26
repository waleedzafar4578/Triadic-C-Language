#ifndef trbnode_float_h
#define trbnode_float_h
#include "../Array/Operator/datatypelinker.h"
#include "../Array/tarray_float.h"
#include "../Array/t_size.h"

enum Color
{
    RED,
    BLACK
};

class trbnode_float
{
public:
    tp_float data;
    bool color;
    trbnode_float *left, *right, *parent;

    // Constructor
    trbnode_float(tp_float data)
    {
        this->data = data;
        left = right = parent = NULL;
        this->color = RED;
    }
    trbnode_float(trbnode_float &obj)
    {
        data = obj.data;
        color = obj.color;
        parent = obj.parent;
        left = obj.left;
        right = obj.right;
    }
    tp_float &get_node()
    {
        return data;
    }
};

#endif