#include "tavlnode_ldouble.h"
tavlnode_ldouble *avltree_insert(tavlnode_ldouble *root, tavlnode_ldouble &obj, tp_ldouble &val);
tavlnode_ldouble *avltree_delete(tavlnode_ldouble *root, long double key);
tavlnode_ldouble *avltree_insert(tavlnode_ldouble *root, Degree pointer_degree, long double value, Degree value_degree, tp_ldouble &val);
void avltree_print(tavlnode_ldouble *root);
class tavltree_ldouble
{
    tavlnode_ldouble *root = NULL;

public:
    int index = 0;
    tp_ldouble d_base[10];
    void insert_node(tavlnode_ldouble &obj)
    {
        root = avltree_insert(root, obj, d_base[index]);
        if (d_base[index].get_Degree_ptr() == T)
        {
            index++;
        }
    }
    void insert_node(Degree pointer_degree, long double value, Degree value_degree)
    {
        root = avltree_insert(root, pointer_degree, value, value_degree, d_base[index]);
        if (d_base[index].get_Degree_ptr() == T)
        {
            index++;
        }
    }
    void l_s()
    {
        tavlnode_ldouble input;
        t_scan(input);
        root = avltree_insert(root, input, d_base[index]);
        if (d_base[index].get_Degree_ptr() == T)
        {
            index++;
        }
    }
    void l_p()
    {
        avltree_print(root);
        cout << "data which not campere able." << endl;
        for (int i = index - 1; i >= 0; i--)
            t_print(d_base[index - i - 1]);
    }
    void delete_node(long double key)
    {
        root = avltree_delete(root , key);
    }
};
void t_scan(tavltree_ldouble &obj)
{
    obj.l_s();
}
void t_print(tavltree_ldouble &obj)
{
    obj.l_p();
}
tavlnode_ldouble *avltree_insert(tavlnode_ldouble *root, tavlnode_ldouble &obj, tp_ldouble &val)
{
    tp_ldouble t2(obj.get_node().get_value(), obj.get_node().get_Degree_ptr(), obj.get_node().get_Degree_val());
    if (root == NULL)
        return new tavlnode_ldouble(obj);
    else if (root != NULL && t2.get_Degree_ptr() == T)
    {
        t_ldouble t2_1(t2.get_pointer().get_value(), t2.get_pointer().get_Degree());
        t_ldouble t1(root->get_node().get_pointer().get_value(), root->get_node().get_pointer().get_Degree());
        t_ldouble ans;
        ans = tlt(t1, t2_1);
        if (ans.get_Degree() == T && ans.get_value() == t1.get_value())
        {

            root->right = avltree_insert(root->right, obj, val);
        }
        else if (ans.get_Degree() == F && ans.get_value() == t2_1.get_value())
        {
            root->left = avltree_insert(root->left, obj, val);
        }
        else
        {
            val.set_Degree_ptr(T);
            val.set_pointer(obj.get_node().get_pointer());
            return NULL;
        }
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int BalanceFactor = getBalancingFactor(root);
    if (BalanceFactor > 1)
    {
        if (obj.get_node().get_value() < root->left->get_node().get_value())
            return rotateRight(root);
        else if (obj.get_node().get_value() < root->left->get_node().get_value())
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    if (BalanceFactor < -1)
    {
        if (obj.get_node().get_value() > root->right->get_node().get_value())
            return rotateLeft(root);
        else if (obj.get_node().get_value() < root->right->get_node().get_value())
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }
    return root;
}
tavlnode_ldouble *avltree_insert(tavlnode_ldouble *root, Degree pointer_degree, long double value, Degree value_degree, tp_ldouble &val)
{
    if (root == NULL)
    {
        return new tavlnode_ldouble(pointer_degree, value, value_degree);
    }
    else if (root != NULL && pointer_degree == T)
    {
        t_ldouble t2_1(value, value_degree);
        t_ldouble t1(root->get_node().get_pointer().get_value(), root->get_node().get_pointer().get_Degree());
        t_ldouble ans;
        ans = tlt(t1, t2_1);
        if (ans.get_Degree() == T && ans.get_value() == t1.get_value())
        {

            root->right = avltree_insert(root->right, pointer_degree, value, value_degree, val);
        }
        else if (ans.get_Degree() == F && ans.get_value() == t2_1.get_value())
        {
            root->left = avltree_insert(root->left, pointer_degree, value, value_degree, val);
        }
        else
        {
            val.set_Degree_ptr(T);
            val.set_pointer(value, value_degree);
            return root;
        }
    }
    int BalanceFactor = getBalancingFactor(root);
    if (BalanceFactor > 1)
    {
        if (value < root->left->get_node().get_value())
            return rotateRight(root);
        else if (value > root->left->get_node().get_value())
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    if (BalanceFactor < -1)
    {
        if (value > root->right->get_node().get_value())
            return rotateLeft(root);
        else if (value < root->right->get_node().get_value())
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }
    return root;
}
tavlnode_ldouble *minimum(tavlnode_ldouble *root)
{
    tavlnode_ldouble *current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}
tavlnode_ldouble *avltree_delete(tavlnode_ldouble *root, long double key)
{
    if (root == NULL)
        return root;
    if (key < root->get_node().get_value())
        root->left = avltree_delete(root->left, key);
    else if (key > root->get_node().get_value())
        root->right = avltree_delete(root->right, key);
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            tavlnode_ldouble *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            tavlnode_ldouble *temp = minimum(root->right);
            root->set_node(*temp);
            root->right = avltree_delete(root->right , temp->get_node().get_value());
        }
    }
    if(root == NULL)
        return root;
    root->height = 1 + max(getHeight(root->left) , getHeight(root->right));
    int BalanceFactor = getBalancingFactor(root);
    if(BalanceFactor > 1)
    {
        if(getBalancingFactor(root->left) >= 0)
        {
            return rotateRight(root);
        }
        else
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    if(BalanceFactor < -1)
    {
        if(getBalancingFactor(root->right) <= 0)
            return rotateLeft(root);
        else
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }
    return root;
}
void avltree_print(tavlnode_ldouble *root)
{
    if (root == NULL)
        return;
    avltree_print(root->left);
    t_print(*root);
    avltree_print(root->right);
}