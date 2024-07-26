#include "ttreenode_int.h"
ttreenode_int *tree_insert(ttreenode_int *root, ttreenode_int &obj);
ttreenode_int *tree_delete(ttreenode_int *root, int i);
ttreenode_int *tree_insert(ttreenode_int *root, Degree pd, int d, Degree de);
void tree_print(ttreenode_int *root);
class t_tree_int
{
    ttreenode_int *root = NULL;

public:
    // t_tree_int(Degree pd, int d, Degree de)
    // {
    //     dlist = new tnode_int(pd, d, de);
    //     dlist->right = nullptr;
    // }
    // t_tree_int(tnode_int &obj)
    // {
    //     dlist = new tnode_int(obj);
    //     dlist->right = nullptr;
    // }
    void insert_node(ttreenode_int &obj)
    {
        root = tree_insert(root, obj);
    }
    void insert_node(Degree pd, int d, Degree de)
    {
        root = tree_insert(root, pd, d, de);
    }

    void l_p()
    {
        tree_print(root);
    }
    void l_s()
    {
        ttreenode_int in;
        t_scan(in);
        root = tree_insert(root, in);
    }
    void delete_node(int i)
    {
        root = tree_delete(root, i);
    }
};
void t_scan(t_tree_int &obj)
{
    obj.l_s();
}
void t_print(t_tree_int &obj)
{
    obj.l_p();
}
ttreenode_int *tree_insert(ttreenode_int *root, ttreenode_int &obj)
{
    if (root == NULL)
    {
        return new ttreenode_int(obj);
    }
    else if (root->left == NULL)
    {
        root->left = tree_insert(root->left, obj);
    }
    else
    {
        root->right = tree_insert(root->right, obj);
    }

    return root;
}
ttreenode_int *tree_insert(ttreenode_int *root, Degree pd, int d, Degree de)
{
    if (root == NULL)
    {
        return new ttreenode_int(pd, d, de);
    }
    else if (root->left == NULL)
    {
        root->left = tree_insert(root->left, pd, d, de);
    }
    else
    {
        root->right = tree_insert(root->right, pd, d, de);
    }

    return root;
}
ttreenode_int *tree_delete(ttreenode_int *root, int i)
{
    if (i == 0)
    {
        ttreenode_int *temp = root->right;
        delete root;
        return temp;
    }
    root->left = tree_delete(root->left, --i);
    root->right = tree_delete(root->right, --i);
    return root;
}
void tree_print(ttreenode_int *root)
{
    if (root == NULL)
    {
        return;
    }
    t_print(*root);
    tree_print(root->left);
    tree_print(root->right);
}