#pragma once

#include<variant>
#include<string>
#include"../Array/Operator/datatypelinker.h"
class t_hetro_tree_node
{
public:
    variant<t_int, t_float, t_char, t_bool , t_double , t_ldouble , t_lint , t_sint , t_uint> primaryKeyData;
    t_hetro_tree_node *right;
    t_hetro_tree_node *left;
    t_hetro_tree_node(variant<t_int, t_float, t_char, t_bool , t_double , t_ldouble , t_lint , t_sint , t_uint> r_data)
    {
        if(get_if<t_int>(&r_data))
        {
            primaryKeyData = get<t_int>(r_data);
        }
        if(get_if<t_float>(&r_data))
        {
            primaryKeyData = get<t_float>(r_data);
        }
        if(get_if<t_char>(&r_data))
        {
            primaryKeyData = get<t_char>(r_data);
        }
        if(get_if<t_double>(&r_data))
        {
            primaryKeyData = get<t_double>(r_data);
        }
        if(get_if<t_ldouble>(&r_data))
        {
            primaryKeyData = get<t_ldouble>(r_data);
        }
        if(get_if<t_lint>(&r_data))
        {
            primaryKeyData = get<t_lint>(r_data);
        }
        if(get_if<t_sint>(&r_data))
        {
            primaryKeyData = get<t_sint>(r_data);
        }
        if(get_if<t_uint>(&r_data))
        {
            primaryKeyData = get<t_uint>(r_data);
        }
        if(get_if<t_bool>(&r_data))
        {
            primaryKeyData = get<t_bool>(r_data);
        }
        right = nullptr;
        left = nullptr;
    }
    void display()
    {
        if (get_if<t_int>(&primaryKeyData))
        {
            t_print(get<t_int>(primaryKeyData));
        }
        else if (get_if<t_float>(&primaryKeyData))
        {
            t_print(get<t_float>(primaryKeyData));
        }
        else if (get_if<t_char>(&primaryKeyData))
        {
            t_print(get<t_char>(primaryKeyData));
        }
        else if (get_if<t_bool>(&primaryKeyData))
        {
            t_print(get<t_bool>(primaryKeyData));
        }
        else if (get_if<t_double>(&primaryKeyData))
        {
            t_print(get<t_double>(primaryKeyData));
        }
        else if (get_if<t_ldouble>(&primaryKeyData))
        {
            t_print(get<t_ldouble>(primaryKeyData));
        }
        else if (get_if<t_lint>(&primaryKeyData))
        {
            t_print(get<t_lint>(primaryKeyData));
        }
        else if (get_if<t_sint>(&primaryKeyData))
        {
            t_print(get<t_sint>(primaryKeyData));
        }
        else if (get_if<t_uint>(&primaryKeyData))
        {
            t_print(get<t_uint>(primaryKeyData));
        }
        else
        {
            cout << "Empty" << endl;
        }
    }
};