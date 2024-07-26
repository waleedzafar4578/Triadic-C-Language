#pragma once
#include "t_hnode.h"
class t_hetro_stack
{
    t_hnode *top;

public:
    t_hetro_stack()
    {
        top = NULL;
    }
    void push(variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data)
    {
        t_hnode *temp;
        if (get_if<t_bool>(&data))
        {
            temp = new t_hnode(get<t_bool>(data));
        }
        else if (get_if<t_char>(&data))
        {
            temp = new t_hnode(get<t_char>(data));
        }
        else if (get_if<t_double>(&data))
        {
            temp = new t_hnode(get<t_double>(data));
        }
        else if (get_if<t_float>(&data))
        {
            temp = new t_hnode(get<t_float>(data));
        }
        else if (get_if<t_int>(&data))
        {
            temp = new t_hnode(get<t_int>(data));
        }
        else if (get_if<t_ldouble>(&data))
        {
            temp = new t_hnode(get<t_ldouble>(data));
        }
        else if (get_if<t_lint>(&data))
        {
            temp = new t_hnode(get<t_lint>(data));
        }
        else if (get_if<t_sint>(&data))
        {
            temp = new t_hnode(get<t_sint>(data));
        }
        else if (get_if<t_uint>(&data))
        {
            temp = new t_hnode(get<t_uint>(data));
        }
        if (get_if<t_int>(&data))
        {
            temp->data = get<t_int>(data);
        }
        if (get_if<t_float>(&data))
        {
            temp->data = get<t_float>(data);
        }
        if (get_if<t_char>(&data))
        {
            temp->data = get<t_char>(data);
        }
        if (get_if<t_double>(&data))
        {
            temp->data = get<t_double>(data);
        }
        if (get_if<t_ldouble>(&data))
        {
            temp->data = get<t_ldouble>(data);
        }
        if (get_if<t_lint>(&data))
        {
            temp->data = get<t_lint>(data);
        }
        if (get_if<t_sint>(&data))
        {
            temp->data = get<t_sint>(data);
        }
        if (get_if<t_uint>(&data))
        {
            temp->data = get<t_uint>(data);
        }
        if (get_if<t_bool>(&data))
        {
            temp->data = get<t_bool>(data);
        }
        temp->next = top;
        top = temp;
    }
    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }
    variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> topValue()
    {
        if (!isEmpty())
        {
            if (get_if<t_bool>(&top->data))
            {
                return get<t_bool>(top->data);
            }
            if (get_if<t_char>(&top->data))
            {
                return get<t_char>(top->data);
            }
            if (get_if<t_double>(&top->data))
            {
                return get<t_double>(top->data);
            }
            if (get_if<t_float>(&top->data))
            {
                return get<t_float>(top->data);
            }
            if (get_if<t_int>(&top->data))
            {
                return get<t_int>(top->data);
            }
            if (get_if<t_ldouble>(&top->data))
            {
                return get<t_ldouble>(top->data);
            }
            if (get_if<t_lint>(&top->data))
            {
                return get<t_lint>(top->data);
            }
            if (get_if<t_sint>(&top->data))
            {
                return get<t_sint>(top->data);
            }
            if (get_if<t_uint>(&top->data))
            {
                return get<t_uint>(top->data);
            }
        }
        else
        {
            cout << "Stack Is Empty" << endl;
        }
        exit(1);
    }
    void pop()
    {
        t_hnode *temp;
        if (top == NULL)
        {
            cout << "Stack Is Empty" << endl;
            return;
        }
        else
        {
            temp = top;
            top = top->next;
            delete temp;
        }
    }
    void display()
    {
        t_hnode *temp = top;
        while (true)
        {
            if (temp == nullptr)
            {
                break;
            }
            else
            {
                temp->display();
                temp = temp->next;
            }
        }
    }
};