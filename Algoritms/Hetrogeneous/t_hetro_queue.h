#pragma once
#include "t_hnode.h"
class t_hetro_queue
{
    t_hnode *front;
    t_hnode *rear;

public:
    t_hetro_queue()
    {
        front = NULL;
        rear = NULL;
    }
    bool isEmpty()
    {
        if(front == NULL && rear == NULL)
            return true;
        else
            return false;
    }
    void enqueue(variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data)
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
        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void dequeue()
    {
        if(front == NULL)
        {
            cout<<"Queue Is Empty"<<endl;
            return;
        }
        t_hnode* temp = front;
        front = front->next;
        if(front == NULL)
            rear = NULL;
        delete temp;
    }
    void display()
    {
        t_hnode *temp = front;
        while (true)
        {
            if (temp == NULL)
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
    variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> frontValue()
    {
        if (!(front == NULL))
        {
            if (get_if<t_bool>(&front->data))
            {
                return get<t_bool>(front->data);
            }
            if (get_if<t_char>(&front->data))
            {
                return get<t_char>(front->data);
            }
            if (get_if<t_double>(&front->data))
            {
                return get<t_double>(front->data);
            }
            if (get_if<t_float>(&front->data))
            {
                return get<t_float>(front->data);
            }
            if (get_if<t_int>(&front->data))
            {
                return get<t_int>(front->data);
            }
            if (get_if<t_ldouble>(&front->data))
            {
                return get<t_ldouble>(front->data);
            }
            if (get_if<t_lint>(&front->data))
            {
                return get<t_lint>(front->data);
            }
            if (get_if<t_sint>(&front->data))
            {
                return get<t_sint>(front->data);
            }
            if (get_if<t_uint>(&front->data))
            {
                return get<t_uint>(front->data);
            }
        }
        else
        {
            cout << "Stack Is Empty" << endl;
        }
        exit(1);
    }
    variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> rearValue()
    {
        if (!(rear == NULL))
        {
            if (get_if<t_bool>(&rear->data))
            {
                return get<t_bool>(rear->data);
            }
            if (get_if<t_char>(&rear->data))
            {
                return get<t_char>(rear->data);
            }
            if (get_if<t_double>(&rear->data))
            {
                return get<t_double>(rear->data);
            }
            if (get_if<t_float>(&rear->data))
            {
                return get<t_float>(rear->data);
            }
            if (get_if<t_int>(&rear->data))
            {
                return get<t_int>(rear->data);
            }
            if (get_if<t_ldouble>(&rear->data))
            {
                return get<t_ldouble>(rear->data);
            }
            if (get_if<t_lint>(&rear->data))
            {
                return get<t_lint>(rear->data);
            }
            if (get_if<t_sint>(&rear->data))
            {
                return get<t_sint>(rear->data);
            }
            if (get_if<t_uint>(&rear->data))
            {
                return get<t_uint>(rear->data);
            }
        }
        else
        {
            cout << "Stack Is Empty" << endl;
        }
        exit(1);
    }
};