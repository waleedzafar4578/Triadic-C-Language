#include "ttreenode_ldouble.h"
ttreenode_ldouble *bstree_insert(ttreenode_ldouble *root, ttreenode_ldouble &obj, tp_ldouble &val);
ttreenode_ldouble *bstree_delete(ttreenode_ldouble *root, long double key);
ttreenode_ldouble *bstree_insert(ttreenode_ldouble *root, Degree pointer_degree, long double value, Degree value_degree, tp_ldouble &val);
void bstree_print(ttreenode_ldouble *root);
class tbstree_ldouble
{
    ttreenode_ldouble *root = NULL;

public:
    int index = 0;
    tp_ldouble d_base[10];
    // t_bstree_int(Degree pd, int d, Degree de)
    // {
    //     dlist = new ttreenode_int(pd, d, de);
    //     dlist->right = nullptr;
    // }
    // t_bstree_int(ttreenode_int &obj)
    // {
    //     dlist = new ttreenode_int(obj);
    //     dlist->right = nullptr;
    // }
    void insert_node(ttreenode_ldouble &obj)
    {
        root = bstree_insert(root, obj, d_base[index]);
        if (d_base[index].get_Degree_ptr() == T)
        {
            index++;
        }
    }
    void insert_node(Degree pointer_degree, long double value, Degree value_degree)
    {
        root = bstree_insert(root, pointer_degree, value, value_degree, d_base[index]);
        if (d_base[index].get_Degree_ptr() == T)
        {
            index++;
        }
    }

    void l_p()
    {
        bstree_print(root);
        cout << "data which not campere able." << endl;
        for (int i = index-1; i >= 0; i--)
            t_print(d_base[index - i-1]);
    }
    void l_s()
    {
        ttreenode_ldouble input;
        t_scan(input);
        root = bstree_insert(root, input, d_base[index]);
        if (d_base[index].get_Degree_ptr() == T)
        {
            index++;
        }
    }
    void delete_node(long double key)
    {
        root = bstree_delete(root, key);
    }
};
void t_scan(tbstree_ldouble &obj)
{
    obj.l_s();
}
void t_print(tbstree_ldouble &obj)
{
    obj.l_p();
}
ttreenode_ldouble *bstree_insert(ttreenode_ldouble *root, ttreenode_ldouble &obj, tp_ldouble &val)
{
    tp_ldouble t2(obj.get_node().get_value(), obj.get_node().get_Degree_ptr(), obj.get_node().get_Degree_val());
    if (root == NULL)
    {
        return new ttreenode_ldouble(obj);
    }
    else if (root != NULL && t2.get_Degree_ptr() == T)
    {
        t_ldouble t2_1(t2.get_pointer().get_value(), t2.get_pointer().get_Degree());
        t_ldouble t1(root->get_node().get_pointer().get_value(), root->get_node().get_pointer().get_Degree());
        t_ldouble ans;
        ans = tlt(t1, t2_1);
        if (ans.get_Degree() == T && ans.get_value() == t1.get_value())
        {

            root->right = bstree_insert(root->right, obj, val);
        }
        else if (ans.get_Degree() == F && ans.get_value() == t2_1.get_value())
        {
            root->left = bstree_insert(root->left, obj, val);
        }
        else
        {
            val.set_Degree_ptr(T);
            val.set_pointer(obj.get_node().get_pointer());
            return NULL;
        }
    }

    return root;
}
ttreenode_ldouble *bstree_insert(ttreenode_ldouble *root, Degree pointer_degree, long double value, Degree value_degree, tp_ldouble &val)
{

    if (root == NULL)
    {
        return new ttreenode_ldouble(pointer_degree, value, value_degree);
    }
    else if (root != NULL && pointer_degree == T)
    {
        t_ldouble t2_1(value, value_degree);
        t_ldouble t1(root->get_node().get_pointer().get_value(), root->get_node().get_pointer().get_Degree());
        t_ldouble ans;
        ans = tlt(t1, t2_1);
        if (ans.get_Degree() == T && ans.get_value() == t1.get_value())
        {

            root->right = bstree_insert(root->right, pointer_degree, value, value_degree, val);
        }
        else if (ans.get_Degree() == F && ans.get_value() == t2_1.get_value())
        {
            root->left = bstree_insert(root->left, pointer_degree, value, value_degree, val);
        }
        else
        {
            val.set_Degree_ptr(T);
            val.set_pointer(value, value_degree);
            return root;
        }
    }

    return root;
}
ttreenode_ldouble* minimum(ttreenode_ldouble* root)
{
    ttreenode_ldouble* current = root;
    while(current && current->left != NULL)
        current = current->left;
    return current;
}
ttreenode_ldouble *bstree_delete(ttreenode_ldouble *root, long double key)
{
    if(root == NULL)
        return root;
    if(key < root->get_node().get_value())
        root->left = bstree_delete(root->left , key);
    else if(key > root->get_node().get_value())
        root->right = bstree_delete(root->right , key);
    else
    {
        if(root->left == NULL)
        {
            ttreenode_ldouble *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            ttreenode_ldouble* temp = root->left;
            free(root);
            return temp;
        }
        ttreenode_ldouble* temp = minimum(root->right);
        root->set_node(*temp);
        root->right = bstree_delete(root->right , temp->get_node().get_value());
    }
    return root;
}
void bstree_print(ttreenode_ldouble *root)
{
    if (root == NULL)
    {
        return;
    }

    bstree_print(root->left);
    t_print(*root);
    bstree_print(root->right);
}