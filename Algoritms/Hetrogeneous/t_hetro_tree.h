#pragma once
#include "t_hetro_tree_node.h"
class t_hetro_tree
{
    t_hetro_tree_node *Root;

public:
    t_hetro_tree()
    {
        Root = NULL;
    }
    t_hetro_tree_node* getRoot()
    {
        return Root;
    }
    bool isEmpty()
    {
        return (Root == NULL);
    }
    void Display()
    {
        display(Root);
    }
    void display(t_hetro_tree_node *pointer)
    {
        if (pointer != NULL)
        {
            display(pointer->left);
            pointer->display();
            display(pointer->right);
        }
    }
    void Insert(variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> _primaryKeyData)
    {
        t_hetro_tree_node *temp;
        if (get_if<t_bool>(&_primaryKeyData))
        {
            temp = new t_hetro_tree_node(get<t_bool>(_primaryKeyData));
            temp->primaryKeyData = get<t_bool>(_primaryKeyData);
        }
        else if (get_if<t_char>(&_primaryKeyData))
        {
            temp = new t_hetro_tree_node(get<t_char>(_primaryKeyData));
            temp->primaryKeyData = get<t_char>(_primaryKeyData);
        }
        else if (get_if<t_double>(&_primaryKeyData))
        {
            temp = new t_hetro_tree_node(get<t_double>(_primaryKeyData));
            temp->primaryKeyData = get<t_double>(_primaryKeyData);
        }
        else if (get_if<t_float>(&_primaryKeyData))
        {
            temp = new t_hetro_tree_node(get<t_float>(_primaryKeyData));
            temp->primaryKeyData = get<t_float>(_primaryKeyData);
        }
        else if (get_if<t_int>(&_primaryKeyData))
        {
            temp = new t_hetro_tree_node(get<t_int>(_primaryKeyData));
            temp->primaryKeyData = get<t_int>(_primaryKeyData);
        }
        else if (get_if<t_ldouble>(&_primaryKeyData))
        {
            temp = new t_hetro_tree_node(get<t_ldouble>(_primaryKeyData));
            temp->primaryKeyData = get<t_ldouble>(_primaryKeyData);
        }
        else if (get_if<t_lint>(&_primaryKeyData))
        {
            temp = new t_hetro_tree_node(get<t_lint>(_primaryKeyData));
            temp->primaryKeyData = get<t_lint>(_primaryKeyData);
        }
        else if (get_if<t_sint>(&_primaryKeyData))
        {
            temp = new t_hetro_tree_node(get<t_sint>(_primaryKeyData));
            temp->primaryKeyData = get<t_sint>(_primaryKeyData);
        }
        else if (get_if<t_uint>(&_primaryKeyData))
        {
            temp = new t_hetro_tree_node(get<t_uint>(_primaryKeyData));
            temp->primaryKeyData = get<t_uint>(_primaryKeyData);
        }
        temp->right = NULL;
        temp->left = NULL;
        t_hetro_tree_node *Parent;
        if (isEmpty())
            Root = temp;
        else
        {
            t_hetro_tree_node *temp2;
            temp2 = Root;
            if (get_if<t_bool>(&_primaryKeyData))
            {
                while (temp2 != NULL)
                {
                    Parent = temp2;
                    if (get<t_bool>(_primaryKeyData).get_value() > get<t_bool>(temp2->primaryKeyData).get_value())
                        temp2 = temp2->right;
                    else
                        temp2 = temp2->left;
                }
                if (get<t_bool>(_primaryKeyData).get_value() < get<t_bool>(Parent->primaryKeyData).get_value())
                    Parent->left = temp;
                else
                    Parent->right = temp;
            }
            else if (get_if<t_char>(&_primaryKeyData))
            {
                while (temp2 != NULL)
                {
                    Parent = temp2;
                    if (get<t_char>(_primaryKeyData).get_value() > get<t_char>(temp2->primaryKeyData).get_value())
                        temp2 = temp2->right;
                    else
                        temp2 = temp2->left;
                }
                if (get<t_char>(_primaryKeyData).get_value() < get<t_char>(Parent->primaryKeyData).get_value())
                    Parent->left = temp;
                else
                    Parent->right = temp;
            }
            else if (get_if<t_double>(&_primaryKeyData))
            {
                while (temp2 != NULL)
                {
                    Parent = temp2;
                    if (get<t_double>(_primaryKeyData).get_value() > get<t_double>(temp2->primaryKeyData).get_value())
                        temp2 = temp2->right;
                    else
                        temp2 = temp2->left;
                }
                if (get<t_double>(_primaryKeyData).get_value() < get<t_double>(Parent->primaryKeyData).get_value())
                    Parent->left = temp;
                else
                    Parent->right = temp;
            }
            else if (get_if<t_float>(&_primaryKeyData))
            {
                while (temp2 != NULL)
                {
                    Parent = temp2;
                    if (get<t_float>(_primaryKeyData).get_value() > get<t_float>(temp2->primaryKeyData).get_value())
                        temp2 = temp2->right;
                    else
                        temp2 = temp2->left;
                }
                if (get<t_float>(_primaryKeyData).get_value() < get<t_float>(Parent->primaryKeyData).get_value())
                    Parent->left = temp;
                else
                    Parent->right = temp;
            }
            else if (get_if<t_int>(&_primaryKeyData))
            {
                while (temp2 != NULL)
                {
                    Parent = temp2;
                    if (get<t_int>(_primaryKeyData).get_value() > get<t_int>(temp2->primaryKeyData).get_value())
                        temp2 = temp2->right;
                    else
                        temp2 = temp2->left;
                }
                if (get<t_int>(_primaryKeyData).get_value() < get<t_int>(Parent->primaryKeyData).get_value())
                    Parent->left = temp;
                else
                    Parent->right = temp;
            }
            else if (get_if<t_ldouble>(&_primaryKeyData))
            {
                while (temp2 != NULL)
                {
                    Parent = temp2;
                    if (get<t_ldouble>(_primaryKeyData).get_value() > get<t_ldouble>(temp2->primaryKeyData).get_value())
                        temp2 = temp2->right;
                    else
                        temp2 = temp2->left;
                }
                if (get<t_ldouble>(_primaryKeyData).get_value() < get<t_ldouble>(Parent->primaryKeyData).get_value())
                    Parent->left = temp;
                else
                    Parent->right = temp;
            }
            else if (get_if<t_lint>(&_primaryKeyData))
            {
                while (temp2 != NULL)
                {
                    Parent = temp2;
                    if (get<t_lint>(_primaryKeyData).get_value() > get<t_lint>(temp2->primaryKeyData).get_value())
                        temp2 = temp2->right;
                    else
                        temp2 = temp2->left;
                }
                if (get<t_lint>(_primaryKeyData).get_value() < get<t_lint>(Parent->primaryKeyData).get_value())
                    Parent->left = temp;
                else
                    Parent->right = temp;
            }
            else if (get_if<t_sint>(&_primaryKeyData))
            {
                while (temp2 != NULL)
                {
                    Parent = temp2;
                    if (get<t_sint>(_primaryKeyData).get_value() > get<t_sint>(temp2->primaryKeyData).get_value())
                        temp2 = temp2->right;
                    else
                        temp2 = temp2->left;
                }
                if (get<t_sint>(_primaryKeyData).get_value() < get<t_sint>(Parent->primaryKeyData).get_value())
                    Parent->left = temp;
                else
                    Parent->right = temp;
            }
            else if (get_if<t_uint>(&_primaryKeyData))
            {
                while (temp2 != NULL)
                {
                    Parent = temp2;
                    if (get<t_uint>(_primaryKeyData).get_value() > get<t_uint>(temp2->primaryKeyData).get_value())
                        temp2 = temp2->right;
                    else
                        temp2 = temp2->left;
                }
                if (get<t_uint>(_primaryKeyData).get_value() < get<t_uint>(Parent->primaryKeyData).get_value())
                    Parent->left = temp;
                else
                    Parent->right = temp;
            }
        }
    }
    t_hetro_tree_node *findMinimum(t_hetro_tree_node* _Root)
    {
        t_hetro_tree_node* currentNode = _Root;
        while(currentNode->left != NULL)
            currentNode = currentNode->left;
        return currentNode;
    }
    t_hetro_tree_node *Deletion(t_hetro_tree_node *_Root, variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> _primaryKeyData)
    {
        if (_Root == NULL)
        {
            cout << "Tree Is Empty" << endl;
            exit(1);
        }
        if (get_if<t_int>(&_Root->primaryKeyData) && get_if<t_int>(&_primaryKeyData))
        {
            if (get<t_int>(_Root->primaryKeyData).get_value() > get<t_int>(_primaryKeyData).get_value())
            {
                _Root->left = Deletion(_Root->left, get<t_int>(_primaryKeyData));
            }
            else if (get<t_int>(_Root->primaryKeyData).get_value() < get<t_int>(_primaryKeyData).get_value())
            {
                _Root->right = Deletion(_Root->right, get<t_int>(_primaryKeyData));
            }
            else
            {
                if (_Root->left == NULL && _Root->right == NULL)
                {
                    delete _Root;
                    _Root = NULL;
                }
                else if (_Root->left == NULL)
                {
                    t_hetro_tree_node *temp = _Root->right;
                    delete _Root;
                    _Root = temp;
                }
                else if (_Root->right == NULL)
                {
                    t_hetro_tree_node* temp = _Root->left;
                    delete _Root;
                    _Root = temp;
                }
                else
                {
                    t_hetro_tree_node* temp = findMinimum(_Root->right);
                    _Root->primaryKeyData = get<t_int>(temp->primaryKeyData);
                    _Root->right = Deletion(_Root->right , get<t_int>(_Root->primaryKeyData));
                }
            }
        }
        else if (get_if<t_bool>(&_Root->primaryKeyData) && get_if<t_bool>(&_primaryKeyData))
        {
            if (get<t_bool>(_Root->primaryKeyData).get_value() > get<t_bool>(_primaryKeyData).get_value())
            {
                _Root->left = Deletion(_Root->left, get<t_bool>(_primaryKeyData));
            }
            else if (get<t_bool>(_Root->primaryKeyData).get_value() < get<t_bool>(_primaryKeyData).get_value())
            {
                _Root->right = Deletion(_Root->right, get<t_bool>(_primaryKeyData));
            }
            else
            {
                if (_Root->left == NULL && _Root->right == NULL)
                {
                    delete _Root;
                    _Root = NULL;
                }
                else if (_Root->left == NULL)
                {
                    t_hetro_tree_node *temp = _Root->right;
                    delete _Root;
                    _Root = temp;
                }
                else if (_Root->right == NULL)
                {
                    t_hetro_tree_node* temp = _Root->left;
                    delete _Root;
                    _Root = temp;
                }
                else
                {
                    t_hetro_tree_node* temp = findMinimum(_Root->right);
                    _Root->primaryKeyData = get<t_bool>(temp->primaryKeyData);
                    _Root->right = Deletion(_Root->right , get<t_bool>(_Root->primaryKeyData));
                }
            }
        }
        else if (get_if<t_char>(&_Root->primaryKeyData) && get_if<t_char>(&_primaryKeyData))
        {
            if (get<t_char>(_Root->primaryKeyData).get_value() > get<t_char>(_primaryKeyData).get_value())
            {
                _Root->left = Deletion(_Root->left, get<t_char>(_primaryKeyData));
            }
            else if (get<t_char>(_Root->primaryKeyData).get_value() < get<t_char>(_primaryKeyData).get_value())
            {
                _Root->right = Deletion(_Root->right, get<t_char>(_primaryKeyData));
            }
            else
            {
                if (_Root->left == NULL && _Root->right == NULL)
                {
                    delete _Root;
                    _Root = NULL;
                }
                else if (_Root->left == NULL)
                {
                    t_hetro_tree_node *temp = _Root->right;
                    delete _Root;
                    _Root = temp;
                }
                else if (_Root->right == NULL)
                {
                    t_hetro_tree_node* temp = _Root->left;
                    delete _Root;
                    _Root = temp;
                }
                else
                {
                    t_hetro_tree_node* temp = findMinimum(_Root->right);
                    _Root->primaryKeyData = get<t_char>(temp->primaryKeyData);
                    _Root->right = Deletion(_Root->right , get<t_char>(_Root->primaryKeyData));
                }
            }
        }
        else if (get_if<t_double>(&_Root->primaryKeyData) && get_if<t_double>(&_primaryKeyData))
        {
            if (get<t_double>(_Root->primaryKeyData).get_value() > get<t_double>(_primaryKeyData).get_value())
            {
                _Root->left = Deletion(_Root->left, get<t_double>(_primaryKeyData));
            }
            else if (get<t_double>(_Root->primaryKeyData).get_value() < get<t_double>(_primaryKeyData).get_value())
            {
                _Root->right = Deletion(_Root->right, get<t_double>(_primaryKeyData));
            }
            else
            {
                if (_Root->left == NULL && _Root->right == NULL)
                {
                    delete _Root;
                    _Root = NULL;
                }
                else if (_Root->left == NULL)
                {
                    t_hetro_tree_node *temp = _Root->right;
                    delete _Root;
                    _Root = temp;
                }
                else if (_Root->right == NULL)
                {
                    t_hetro_tree_node* temp = _Root->left;
                    delete _Root;
                    _Root = temp;
                }
                else
                {
                    t_hetro_tree_node* temp = findMinimum(_Root->right);
                    _Root->primaryKeyData = get<t_double>(temp->primaryKeyData);
                    _Root->right = Deletion(_Root->right , get<t_double>(_Root->primaryKeyData));
                }
            }
        }
        else if (get_if<t_float>(&_Root->primaryKeyData) && get_if<t_float>(&_primaryKeyData))
        {
            if (get<t_float>(_Root->primaryKeyData).get_value() > get<t_float>(_primaryKeyData).get_value())
            {
                _Root->left = Deletion(_Root->left, get<t_float>(_primaryKeyData));
            }
            else if (get<t_float>(_Root->primaryKeyData).get_value() < get<t_float>(_primaryKeyData).get_value())
            {
                _Root->right = Deletion(_Root->right, get<t_float>(_primaryKeyData));
            }
            else
            {
                if (_Root->left == NULL && _Root->right == NULL)
                {
                    delete _Root;
                    _Root = NULL;
                }
                else if (_Root->left == NULL)
                {
                    t_hetro_tree_node *temp = _Root->right;
                    delete _Root;
                    _Root = temp;
                }
                else if (_Root->right == NULL)
                {
                    t_hetro_tree_node* temp = _Root->left;
                    delete _Root;
                    _Root = temp;
                }
                else
                {
                    t_hetro_tree_node* temp = findMinimum(_Root->right);
                    _Root->primaryKeyData = get<t_float>(temp->primaryKeyData);
                    _Root->right = Deletion(_Root->right , get<t_float>(_Root->primaryKeyData));
                }
            }
        }
        else if (get_if<t_ldouble>(&_Root->primaryKeyData) && get_if<t_ldouble>(&_primaryKeyData))
        {
            if (get<t_ldouble>(_Root->primaryKeyData).get_value() > get<t_ldouble>(_primaryKeyData).get_value())
            {
                _Root->left = Deletion(_Root->left, get<t_ldouble>(_primaryKeyData));
            }
            else if (get<t_ldouble>(_Root->primaryKeyData).get_value() < get<t_ldouble>(_primaryKeyData).get_value())
            {
                _Root->right = Deletion(_Root->right, get<t_ldouble>(_primaryKeyData));
            }
            else
            {
                if (_Root->left == NULL && _Root->right == NULL)
                {
                    delete _Root;
                    _Root = NULL;
                }
                else if (_Root->left == NULL)
                {
                    t_hetro_tree_node *temp = _Root->right;
                    delete _Root;
                    _Root = temp;
                }
                else if (_Root->right == NULL)
                {
                    t_hetro_tree_node* temp = _Root->left;
                    delete _Root;
                    _Root = temp;
                }
                else
                {
                    t_hetro_tree_node* temp = findMinimum(_Root->right);
                    _Root->primaryKeyData = get<t_ldouble>(temp->primaryKeyData);
                    _Root->right = Deletion(_Root->right , get<t_ldouble>(_Root->primaryKeyData));
                }
            }
        }
        else if (get_if<t_lint>(&_Root->primaryKeyData) && get_if<t_lint>(&_primaryKeyData))
        {
            if (get<t_lint>(_Root->primaryKeyData).get_value() > get<t_lint>(_primaryKeyData).get_value())
            {
                _Root->left = Deletion(_Root->left, get<t_lint>(_primaryKeyData));
            }
            else if (get<t_lint>(_Root->primaryKeyData).get_value() < get<t_lint>(_primaryKeyData).get_value())
            {
                _Root->right = Deletion(_Root->right, get<t_lint>(_primaryKeyData));
            }
            else
            {
                if (_Root->left == NULL && _Root->right == NULL)
                {
                    delete _Root;
                    _Root = NULL;
                }
                else if (_Root->left == NULL)
                {
                    t_hetro_tree_node *temp = _Root->right;
                    delete _Root;
                    _Root = temp;
                }
                else if (_Root->right == NULL)
                {
                    t_hetro_tree_node* temp = _Root->left;
                    delete _Root;
                    _Root = temp;
                }
                else
                {
                    t_hetro_tree_node* temp = findMinimum(_Root->right);
                    _Root->primaryKeyData = get<t_lint>(temp->primaryKeyData);
                    _Root->right = Deletion(_Root->right , get<t_lint>(_Root->primaryKeyData));
                }
            }
        }
        else if (get_if<t_sint>(&_Root->primaryKeyData) && get_if<t_sint>(&_primaryKeyData))
        {
            if (get<t_sint>(_Root->primaryKeyData).get_value() > get<t_sint>(_primaryKeyData).get_value())
            {
                _Root->left = Deletion(_Root->left, get<t_sint>(_primaryKeyData));
            }
            else if (get<t_sint>(_Root->primaryKeyData).get_value() < get<t_sint>(_primaryKeyData).get_value())
            {
                _Root->right = Deletion(_Root->right, get<t_sint>(_primaryKeyData));
            }
            else
            {
                if (_Root->left == NULL && _Root->right == NULL)
                {
                    delete _Root;
                    _Root = NULL;
                }
                else if (_Root->left == NULL)
                {
                    t_hetro_tree_node *temp = _Root->right;
                    delete _Root;
                    _Root = temp;
                }
                else if (_Root->right == NULL)
                {
                    t_hetro_tree_node* temp = _Root->left;
                    delete _Root;
                    _Root = temp;
                }
                else
                {
                    t_hetro_tree_node* temp = findMinimum(_Root->right);
                    _Root->primaryKeyData = get<t_sint>(temp->primaryKeyData);
                    _Root->right = Deletion(_Root->right , get<t_sint>(_Root->primaryKeyData));
                }
            }
        }
        else if (get_if<t_uint>(&_Root->primaryKeyData) && get_if<t_uint>(&_primaryKeyData))
        {
            if (get<t_uint>(_Root->primaryKeyData).get_value() > get<t_uint>(_primaryKeyData).get_value())
            {
                _Root->left = Deletion(_Root->left, get<t_uint>(_primaryKeyData));
            }
            else if (get<t_uint>(_Root->primaryKeyData).get_value() < get<t_uint>(_primaryKeyData).get_value())
            {
                _Root->right = Deletion(_Root->right, get<t_uint>(_primaryKeyData));
            }
            else
            {
                if (_Root->left == NULL && _Root->right == NULL)
                {
                    delete _Root;
                    _Root = NULL;
                }
                else if (_Root->left == NULL)
                {
                    t_hetro_tree_node *temp = _Root->right;
                    delete _Root;
                    _Root = temp;
                }
                else if (_Root->right == NULL)
                {
                    t_hetro_tree_node* temp = _Root->left;
                    delete _Root;
                    _Root = temp;
                }
                else
                {
                    t_hetro_tree_node* temp = findMinimum(_Root->right);
                    _Root->primaryKeyData = get<t_uint>(temp->primaryKeyData);
                    _Root->right = Deletion(_Root->right , get<t_uint>(_Root->primaryKeyData));
                }
            }
        }
        else
        {
            cout<<"The Datatype Of Entered Value Doesnot Match With Primary Key"<<endl;
            exit(1);
        }
        return _Root;
    }
};