#include <bits/stdc++.h>
#include "trbnode_float.h"
using namespace std;

// enum Color {RED, BLACK};

// struct Node
// {
// 	int data;
// 	bool color;
// 	Node *left, *right, *parent;

// 	// Constructor
// 	Node(int data)
// 	{
// 	this->data = data;
// 	left = right = parent = NULL;
// 	this->color = RED;
// 	}
// };

// Class to represent Red-Black Tree
class RBTree
{
private:
    trbnode_float *root;

protected:
    void rotateLeft(trbnode_float *&, trbnode_float *&);
    void rotateRight(trbnode_float *&, trbnode_float *&);
    void fixViolation(trbnode_float *&, trbnode_float *&);

public:
    tp_float d_base[10];
    int index = 0;
    // Constructor
    RBTree() { root = NULL; }
    void insert(tp_float &n);
    void inorder();
    void levelOrder();
};

// A recursive function to do inorder traversal
void inorderHelper(trbnode_float *root)
{
    if (root == NULL)
        return;

    inorderHelper(root->left);
    t_print(root->data);
    inorderHelper(root->right);
}

/* A utility function to insert
    a new node with given key
in BST */
trbnode_float *BSTInsert(trbnode_float *root, trbnode_float &obj, tp_float &val)
{
    tp_float t2(obj.get_node().get_value(), obj.get_node().get_Degree_ptr(), obj.get_node().get_Degree_val());
    /* If the tree is empty, return a new node */
    if (root == NULL)
        return new trbnode_float(obj);
    else if (root != NULL && t2.get_Degree_ptr() == T)
    {
        t_float t2_1(t2.get_pointer().get_value(), t2.get_pointer().get_Degree());
        t_float t1(root->get_node().get_pointer().get_value(), root->get_node().get_pointer().get_Degree());
        t_float ans;
        ans = tlt(t1, t2_1);
        if (ans.get_Degree() == T && ans.get_value() == t1.get_value())
        {
            root->right = BSTInsert(root->right, obj, val);
        }
        else if (ans.get_Degree() == F && ans.get_value() == t2_1.get_value())
        {
            root->left = BSTInsert(root->left, obj, val);
        }
        else
        {
            val.set_Degree_ptr(T);
            val.set_pointer(obj.get_node().get_pointer());
            return NULL;
        }
    }

    /* return the (unchanged) node pointer */
    return root;
}

// Utility function to do level order traversal
void levelOrderHelper(trbnode_float *root)
{
    if (root == NULL)
        return;

    std::queue<trbnode_float *> q;
    q.push(root);

    while (!q.empty())
    {
        trbnode_float *temp = q.front();
        t_print(temp->data);
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

void RBTree::rotateLeft(trbnode_float *&root, trbnode_float *&pt)
{
    trbnode_float *pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != NULL)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_right;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;

    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

void RBTree::rotateRight(trbnode_float *&root, trbnode_float *&pt)
{
    trbnode_float *pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_left;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;

    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

// This function fixes violations
// caused by BST insertion
void RBTree::fixViolation(trbnode_float *&root, trbnode_float *&pt)
{
    trbnode_float *parent_pt = NULL;
    trbnode_float *grand_parent_pt = NULL;

    while ((pt != root) && (pt->color != BLACK) &&
           (pt->parent->color == RED))
    {

        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        /* Case : A
            Parent of pt is left child
            of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left)
        {

            trbnode_float *uncle_pt = grand_parent_pt->right;

            /* Case : 1
            The uncle of pt is also red
            Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->color ==
                                        RED)
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }

            else
            {
                /* Case : 2
                pt is right child of its parent
                Left-rotation required */
                if (pt == parent_pt->right)
                {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3
                pt is left child of its parent
                Right-rotation required */
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color,
                     grand_parent_pt->color);
                pt = parent_pt;
            }
        }

        /* Case : B
        Parent of pt is right child
        of Grand-parent of pt */
        else
        {
            trbnode_float *uncle_pt = grand_parent_pt->left;

            /* Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color ==
                                       RED))
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                /* Case : 2
                pt is left child of its parent
                Right-rotation required */
                if (pt == parent_pt->left)
                {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3
                pt is right child of its parent
                Left-rotation required */
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color,
                     grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK;
}

// Function to insert a new node with given data
void RBTree::insert(tp_float &data)
{
    trbnode_float *pt = new trbnode_float(data);

    // Do a normal BST insert
    root = BSTInsert(root, *pt, d_base[index]);
    if (d_base[index].get_Degree_ptr() == T)
    {
        index++;
    }
    // fix Red Black Tree violations
    fixViolation(root, pt);
}

// Function to do inorder and level order traversals
void RBTree::inorder() { inorderHelper(root); }
void RBTree::levelOrder() { levelOrderHelper(root); }
