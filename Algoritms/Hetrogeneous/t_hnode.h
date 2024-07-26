#pragma once

#include<variant>
#include<string>
#include"../Array/Operator/datatypelinker.h"
class t_hnode
{
public:
    variant<t_int, t_float, t_char, t_bool , t_double , t_ldouble , t_lint , t_sint , t_uint> data;
    t_hnode *next;
    t_hnode(variant<t_int, t_float, t_char, t_bool , t_double , t_ldouble , t_lint , t_sint , t_uint> r_data)
    {
        if(get_if<t_int>(&r_data))
        {
            data = get<t_int>(r_data);
        }
        if(get_if<t_float>(&r_data))
        {
            data = get<t_float>(r_data);
        }
        if(get_if<t_char>(&r_data))
        {
            data = get<t_char>(r_data);
        }
        if(get_if<t_double>(&r_data))
        {
            data = get<t_double>(r_data);
        }
        if(get_if<t_ldouble>(&r_data))
        {
            data = get<t_ldouble>(r_data);
        }
        if(get_if<t_lint>(&r_data))
        {
            data = get<t_lint>(r_data);
        }
        if(get_if<t_sint>(&r_data))
        {
            data = get<t_sint>(r_data);
        }
        if(get_if<t_uint>(&r_data))
        {
            data = get<t_uint>(r_data);
        }
        if(get_if<t_bool>(&r_data))
        {
            data = get<t_bool>(r_data);
        }
        next = nullptr;
    }
    void display()
    {
        if (get_if<t_int>(&data))
        {
            t_print(get<t_int>(data));
        }
        else if (get_if<t_float>(&data))
        {
            t_print(get<t_float>(data));
        }
        else if (get_if<t_char>(&data))
        {
            t_print(get<t_char>(data));
        }
        else if (get_if<t_bool>(&data))
        {
            t_print(get<t_bool>(data));
        }
        else if (get_if<t_double>(&data))
        {
            t_print(get<t_double>(data));
        }
        else if (get_if<t_ldouble>(&data))
        {
            t_print(get<t_ldouble>(data));
        }
        else if (get_if<t_lint>(&data))
        {
            t_print(get<t_lint>(data));
        }
        else if (get_if<t_sint>(&data))
        {
            t_print(get<t_sint>(data));
        }
        else if (get_if<t_uint>(&data))
        {
            t_print(get<t_uint>(data));
        }
        else
        {
            cout << "Empty" << endl;
        }
    }
};