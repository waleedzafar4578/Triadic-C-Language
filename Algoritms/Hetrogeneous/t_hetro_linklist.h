#pragma once
#include "t_hnode.h"
class t_hetro_linklist
{
private:
    t_hnode *head;
    t_hnode *add_node(t_hnode *head, variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data)
    {
        if (head == nullptr)
        {
            if (get_if<t_bool>(&data))
            {
                head = new t_hnode(get<t_bool>(data));
            }
            else if (get_if<t_char>(&data))
            {
                head = new t_hnode(get<t_char>(data));
            }
            else if (get_if<t_double>(&data))
            {
                head = new t_hnode(get<t_double>(data));
            }
            else if (get_if<t_float>(&data))
            {
                head = new t_hnode(get<t_float>(data));
            }
            else if (get_if<t_int>(&data))
            {
                head = new t_hnode(get<t_int>(data));
            }
            else if (get_if<t_ldouble>(&data))
            {
                head = new t_hnode(get<t_ldouble>(data));
            }
            else if (get_if<t_lint>(&data))
            {
                head = new t_hnode(get<t_lint>(data));
            }
            else if (get_if<t_sint>(&data))
            {
                head = new t_hnode(get<t_sint>(data));
            }
            else if (get_if<t_uint>(&data))
            {
                head = new t_hnode(get<t_uint>(data));
            }
            return head;
        }
        else
        {
            if (get_if<t_bool>(&data))
            {
                head->next = add_node(head->next, get<t_bool>(data));
            }
            else if (get_if<t_char>(&data))
            {
                head->next = add_node(head->next, get<t_char>(data));
            }
            else if (get_if<t_double>(&data))
            {
                head->next = add_node(head->next, get<t_double>(data));
            }
            else if (get_if<t_float>(&data))
            {
                head->next = add_node(head->next, get<t_float>(data));
            }
            else if (get_if<t_int>(&data))
            {
                head->next = add_node(head->next, get<t_int>(data));
            }
            else if (get_if<t_ldouble>(&data))
            {
                head->next = add_node(head->next, get<t_ldouble>(data));
            }
            else if (get_if<t_lint>(&data))
            {
                head->next = add_node(head->next, get<t_lint>(data));
            }
            else if (get_if<t_sint>(&data))
            {
                head->next = add_node(head->next, get<t_sint>(data));
            }
            else if (get_if<t_uint>(&data))
            {
                head->next = add_node(head->next, get<t_uint>(data));
            }
        }
        return head;
    }

public:
    t_hetro_linklist()
    {
        head = nullptr;
    }
    t_hetro_linklist(variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data)
    {
        if (get_if<t_bool>(&data))
        {
            head = new t_hnode(get<t_bool>(data));
        }
        else if (get_if<t_char>(&data))
        {
            head = new t_hnode(get<t_char>(data));
        }
        else if (get_if<t_double>(&data))
        {
            head = new t_hnode(get<t_double>(data));
        }
        else if (get_if<t_float>(&data))
        {
            head = new t_hnode(get<t_float>(data));
        }
        else if (get_if<t_int>(&data))
        {
            head = new t_hnode(get<t_int>(data));
        }
        else if (get_if<t_ldouble>(&data))
        {
            head = new t_hnode(get<t_ldouble>(data));
        }
        else if (get_if<t_lint>(&data))
        {
            head = new t_hnode(get<t_lint>(data));
        }
        else if (get_if<t_sint>(&data))
        {
            head = new t_hnode(get<t_sint>(data));
        }
        else if (get_if<t_uint>(&data))
        {
            head = new t_hnode(get<t_uint>(data));
        }
    }
    void insert(variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data)
    {
        if (get_if<t_bool>(&data))
        {
            head = add_node(head, get<t_bool>(data));
        }
        else if (get_if<t_char>(&data))
        {
            head = add_node(head, get<t_char>(data));
        }
        else if (get_if<t_double>(&data))
        {
            head = add_node(head, get<t_double>(data));
        }
        else if (get_if<t_float>(&data))
        {
            head = add_node(head, get<t_float>(data));
        }
        else if (get_if<t_int>(&data))
        {
            head = add_node(head, get<t_int>(data));
        }
        else if (get_if<t_ldouble>(&data))
        {
            head = add_node(head, get<t_ldouble>(data));
        }
        else if (get_if<t_lint>(&data))
        {
            head = add_node(head, get<t_lint>(data));
        }
        else if (get_if<t_sint>(&data))
        {
            head = add_node(head, get<t_sint>(data));
        }
        else if (get_if<t_uint>(&data))
        {
            head = add_node(head, get<t_uint>(data));
        }
    }
    void remove(int index)
    {
        t_hnode *temp = head;
        t_hnode *temp2 = NULL;
        int length = 0;
        if (head == nullptr)
        {
            cout << "List Is Empty" << endl;
            return;
        }
        while (temp != NULL)
        {
            temp = temp->next;
            length++;
        }
        if (length < index + 1)
        {
            cout << "Index Out Of Range" << endl;
            return;
        }
        temp = head;
        if (index == 0)
        {
            head = head->next;
            delete temp;
            return;
        }
        while (index-- > 0)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = temp->next;
        delete temp;
    }
    void remove(variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data)
    {
        t_hnode* current = head;
        int index = 0;
        bool found = false;
        while(current != NULL)
        {
            if(get_if<t_uint>(&data) && get_if<t_uint>(&current->data))
            {
                if(get<t_uint>(data).get_value() == get<t_uint>(current->data).get_value() && get<t_uint>(data).get_Degree() == get<t_uint>(current->data).get_Degree())
                {
                    found = true;
                    break;
                }
            }
            if(get_if<t_sint>(&data) && get_if<t_sint>(&current->data))
            {
                if(get<t_sint>(data).get_value() == get<t_sint>(current->data).get_value() && get<t_sint>(data).get_Degree() == get<t_sint>(current->data).get_Degree())
                {
                    found = true;
                    break;
                }
            }
            if(get_if<t_lint>(&data) && get_if<t_lint>(&current->data))
            {
                if(get<t_lint>(data).get_value() == get<t_lint>(current->data).get_value() && get<t_lint>(data).get_Degree() == get<t_lint>(current->data).get_Degree())
                {
                    found = true;
                    break;
                }
            }
            if(get_if<t_float>(&data) && get_if<t_float>(&current->data))
            {
                if(get<t_float>(data).get_value() == get<t_float>(current->data).get_value() && get<t_float>(data).get_Degree() == get<t_float>(current->data).get_Degree())
                {
                    found = true;
                    break;
                }
            }
            if(get_if<t_double>(&data) && get_if<t_double>(&current->data))
            {
                if(get<t_double>(data).get_value() == get<t_double>(current->data).get_value() && get<t_double>(data).get_Degree() == get<t_double>(current->data).get_Degree())
                {
                    found = true;
                    break;
                }
            }
            if(get_if<t_char>(&data) && get_if<t_char>(&current->data))
            {
                if(get<t_char>(data).get_value() == get<t_char>(current->data).get_value() && get<t_char>(data).get_Degree() == get<t_char>(current->data).get_Degree())
                {
                    found = true;
                    break;
                }
            }
            if(get_if<t_bool>(&data) && get_if<t_bool>(&current->data))
            {
                if(get<t_bool>(data).get_value() == get<t_bool>(current->data).get_value() && get<t_bool>(data).get_Degree() == get<t_bool>(current->data).get_Degree())
                {
                    found = true;
                    break;
                }
            }
            if(get_if<t_int>(&data) && get_if<t_int>(&current->data))
            {
                if(get<t_int>(data).get_value() == get<t_int>(current->data).get_value() && get<t_int>(data).get_Degree() == get<t_int>(current->data).get_Degree())
                {
                    found = true;
                    break;
                }
            }
            if(get_if<t_ldouble>(&data) && get_if<t_ldouble>(&current->data))
            {
                if(get<t_ldouble>(data).get_value() == get<t_ldouble>(current->data).get_value() && get<t_ldouble>(data).get_Degree() == get<t_ldouble>(current->data).get_Degree())
                {
                    found = true;
                    break;
                }
            }
            index++;
            current = current->next;
        }
        if(found == false)
        {
            cout<<"Value Is Not Present In List"<<endl;
            return;
        }
        else
        {
            remove(index);
        }
    }
    void display()
    {
        t_hnode *temp = head;
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