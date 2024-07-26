#include "t_bplus_tree_node.h"
#include <bits/stdc++.h>
class t_bplus_tree
{
    t_bplus_tree_node *Root;

public:
    t_bplus_tree()
    {
        Root = NULL;
    }
    t_bplus_tree_node *getRoot()
    {
        return Root;
    }
    void Insert(t_int value)
    {
        if (Root == NULL)
        {
            Root = new t_bplus_tree_node;
            int loca = 0;
            if (Root->keys.g_indexD(0) == L)
            {
                Root->keys.s_indexD(0, T);
                Root->keys.set_pointer_value(loca, -1);
                Root->keys.set_pointer_value_degree(loca, T);
            }
            Root->keys.set_pointer_value(loca, value.get_value());
            Root->keys.set_pointer_value_degree(loca, value.get_Degree());
            Root->isLeaf = true;
            Root->size = 1;
        }
        else
        {
            t_bplus_tree_node *currentNode = Root;
            t_bplus_tree_node *Parent;
            while (currentNode->isLeaf == false)
            {
                Parent = currentNode;
                for (int i = 0; i < currentNode->size; i++)
                {
                    if (value.get_value() < currentNode->keys.get_pointer_value(i))
                    {
                        currentNode = currentNode->pointer[i];
                        break;
                    }
                    if (i == currentNode->size - 1)
                    {
                        currentNode = currentNode->pointer[i + 1];
                        break;
                    }
                }
            }
            if (currentNode->size < ORDER)
            {
                int i = 0;
                while (value.get_value() > currentNode->keys.get_pointer_value(i) && i < currentNode->size)
                    i++;
                for (int j = currentNode->size; j > i; j--)
                {
                    int locat = j - 1;
                    if (currentNode->keys.g_indexD(j) == L)
                    {
                        currentNode->keys.s_indexD(j, T);
                        currentNode->keys.set_pointer_value(j, -1);
                        currentNode->keys.set_pointer_value_degree(j, T);
                    }
                    currentNode->keys.set_pointer_value(j, currentNode->keys.get_pointer_value(locat));
                    currentNode->keys.set_pointer_value_degree(j, currentNode->keys.get_pointer_value_degree(locat));
                }
                if (currentNode->keys.g_indexD(i) == L)
                {
                    currentNode->keys.s_indexD(i, T);
                    currentNode->keys.set_pointer_value(i, value.get_value());
                    currentNode->keys.set_pointer_value_degree(i, value.get_Degree());
                }
                currentNode->keys.set_pointer_value(i, value.get_value());
                currentNode->keys.set_pointer_value_degree(i, value.get_Degree());
                currentNode->size++;
                currentNode->pointer[currentNode->size] = currentNode->pointer[currentNode->size - 1];
                currentNode->pointer[currentNode->size - 1] = NULL;
            }
            else
            {
                t_bplus_tree_node *newNode = new t_bplus_tree_node;
                tarray_int tempKeys(ORDER + 1, L);
                for (int i = 0; i < ORDER; i++)
                {
                    tempKeys.s_indexD(i, T);
                    tempKeys.set_pointer_value(i, currentNode->keys.get_pointer_value(i));
                    tempKeys.set_pointer_value_degree(i, currentNode->keys.get_pointer_value_degree(i));
                }
                int i = 0, j;
                while (value.get_value() > tempKeys.get_pointer_value(i) && i < ORDER)
                    i++;
                for (int j = ORDER + 1; j > i; j--)
                {
                    int lo = j - 1;
                    int loc = lo - 1;
                    if (tempKeys.g_indexD(lo) == L)
                    {
                        tempKeys.s_indexD(lo, T);
                        tempKeys.set_pointer_value(lo, -1);
                        tempKeys.set_pointer_value_degree(lo, T);
                    }
                    tempKeys.set_pointer_value(lo, tempKeys.get_pointer_value(loc));
                    tempKeys.set_pointer_value_degree(lo, tempKeys.get_pointer_value_degree(loc));
                }
                tempKeys.set_pointer_value(i, value.get_value());
                tempKeys.set_pointer_value_degree(i, value.get_Degree());
                newNode->isLeaf = true;
                currentNode->size = (ORDER + 1) / 2;
                newNode->size = (ORDER + 1) - (ORDER + 1) / 2;
                currentNode->pointer[currentNode->size] = newNode;
                newNode->pointer[newNode->size] = currentNode->pointer[ORDER];
                currentNode->pointer[newNode->size] = currentNode->pointer[ORDER];
                currentNode->pointer[ORDER] = NULL;
                for (int i = 0; i < currentNode->size; i++)
                {
                    if (currentNode->keys.g_indexD(i) == L)
                    {
                        currentNode->keys.s_indexD(i, T);
                        currentNode->keys.set_pointer_value(i, tempKeys.get_pointer_value(i));
                        currentNode->keys.set_pointer_value_degree(i, tempKeys.get_pointer_value_degree(i));
                    }
                    currentNode->keys.set_pointer_value(i, tempKeys.get_pointer_value(i));
                    currentNode->keys.set_pointer_value_degree(i, tempKeys.get_pointer_value_degree(i));
                }
                for (int i = 0, j = currentNode->size; i < newNode->size; i++, j++)
                {
                    if (newNode->keys.g_indexD(i) == L)
                    {
                        newNode->keys.s_indexD(i, T);
                        newNode->keys.set_pointer_value(i, tempKeys.get_pointer_value(j));
                        newNode->keys.set_pointer_value_degree(i, tempKeys.get_pointer_value_degree(j));
                    }
                    newNode->keys.set_pointer_value(i, tempKeys.get_pointer_value(j));
                    newNode->keys.set_pointer_value_degree(i, tempKeys.get_pointer_value_degree(j));
                }
                if (currentNode == Root)
                {
                    int loc = 0;
                    t_bplus_tree_node *newRoot = new t_bplus_tree_node;
                    if (newRoot->keys.g_indexD(0) == L)
                    {
                        newRoot->keys.s_indexD(0, T);
                        newRoot->keys.set_pointer_value(loc, -1);
                        newRoot->keys.set_pointer_value_degree(loc, T);
                    }
                    newRoot->keys.set_pointer_value(loc, newNode->keys.get_pointer_value(loc));
                    newRoot->keys.set_pointer_value_degree(loc, newNode->keys.get_pointer_value_degree(loc));
                    newRoot->pointer[0] = currentNode;
                    newRoot->pointer[1] = newNode;
                    newRoot->isLeaf = false;
                    newRoot->size = 1;
                    Root = newRoot;
                }
                else
                {
                    int loc = 0;
                    t_int Val(newNode->keys.get_pointer_value(loc), newNode->keys.get_pointer_value_degree(loc));
                    shiftLevel(Val, Parent, newNode);
                }
            }
        }
    }
    void shiftLevel(t_int value, t_bplus_tree_node *currentNode, t_bplus_tree_node *childNode)
    {
        // If The Value Can Be Inserted On The Current Level, Do It
        if (currentNode->size < ORDER)
        {
            int i = 0;
            while (value.get_value() > currentNode->keys.get_pointer_value(i) && i < currentNode->size)
            {
                i++;
            }
            for (int j = currentNode->size; j > i; j--)
            {
                int l = j - 1;
                if (currentNode->keys.g_indexD(j) == L)
                {
                    currentNode->keys.s_indexD(j, T);
                    currentNode->keys.set_pointer_value(j, -1);
                    currentNode->keys.set_pointer_value_degree(j, T);
                }
                currentNode->keys.set_pointer_value(j, currentNode->keys.get_pointer_value(l));
                currentNode->keys.set_pointer_value_degree(j, currentNode->keys.get_pointer_value_degree(l));
            }
            for (int j = currentNode->size + 1; j > i; j--)
            {
                currentNode->pointer[j] = currentNode->pointer[j - 1];
            }
            if (currentNode->keys.g_indexD(i) == L)
            {
                currentNode->keys.s_indexD(i, T);
                currentNode->keys.set_pointer_value(i, -1);
                currentNode->keys.set_pointer_value_degree(i, T);
            }
            currentNode->keys.set_pointer_value(i, value.get_value());
            currentNode->keys.set_pointer_value_degree(i, value.get_Degree());
            currentNode->size++;
            currentNode->pointer[i + 1] = childNode;
        }
        // Shifting Upward
        else
        {
            t_bplus_tree_node *newNode = new t_bplus_tree_node;
            tarray_int tempKeys(ORDER + 1, L);
            t_bplus_tree_node *tempPointers[ORDER + 2];
            for (int i = 0; i < ORDER; i++)
            {
                tempKeys.s_indexD(i, T);
                tempKeys.set_pointer_value(i, currentNode->keys.get_pointer_value(i));
                tempKeys.set_pointer_value_degree(i, currentNode->keys.get_pointer_value_degree(i));
            }
            for (int i = 0; i < ORDER + 1; i++)
            {
                tempPointers[i] = currentNode->pointer[i];
            }
            int i = 0, j;
            while (value.get_value() > tempKeys.get_pointer_value(i) && i < ORDER)
                i++;
            for (int j = ORDER + 1; j > i; j--)
            {
                int lo = j - 1;
                if (tempKeys.g_indexD(j) == L)
                {
                    tempKeys.s_indexD(j, T);
                    tempKeys.set_pointer_value(j, -1);
                    tempKeys.set_pointer_value_degree(j, T);
                }
                tempKeys.set_pointer_value(j, tempKeys.get_pointer_value(lo));
                tempKeys.set_pointer_value_degree(j, tempKeys.get_pointer_value_degree(lo));
            }
            tempKeys.set_pointer_value(i, value.get_value());
            tempKeys.set_pointer_value_degree(i, value.get_Degree());
            for (int j = ORDER + 2; j > i + 1; j--)
                tempPointers[j] = tempPointers[j - 1];
            tempPointers[i + 1] = childNode;
            newNode->isLeaf = false;
            currentNode->size = (ORDER + 1) / 2;
            newNode->size = ORDER - (ORDER + 1) / 2;
            for (int i = 0, j = currentNode->size + 1; i < newNode->size; i++, j++)
            {
                if (newNode->keys.g_indexD(i) == L)
                {
                    newNode->keys.s_indexD(i, T);
                    newNode->keys.set_pointer_value(i, -1);
                    newNode->keys.set_pointer_value_degree(i, T);
                }
                newNode->keys.set_pointer_value(i, tempKeys.get_pointer_value(j));
                newNode->keys.set_pointer_value_degree(i, tempKeys.get_pointer_value_degree(j));
            }
            for (int i = 0, j = currentNode->size + 1; i < newNode->size + 1; i++, j++)
            {
                newNode->pointer[i] = tempPointers[j];
            }
            if (currentNode == Root)
            {
                int loc = 0;
                t_bplus_tree_node *newRoot = new t_bplus_tree_node;
                if (newRoot->keys.g_indexD(0) == L)
                {
                    newRoot->keys.s_indexD(0, T);
                    newRoot->keys.set_pointer_value(loc, -1);
                    newRoot->keys.set_pointer_value_degree(loc, T);
                }
                newRoot->keys.set_pointer_value(loc, currentNode->keys.get_pointer_value(currentNode->size));
                newRoot->keys.set_pointer_value_degree(loc, currentNode->keys.get_pointer_value_degree(currentNode->size));
                newRoot->pointer[0] = currentNode;
                newRoot->pointer[1] = newNode;
                newRoot->isLeaf = false;
                newRoot->size = 1;
                Root = newRoot;
            }
            else
            {
                t_int Val(currentNode->keys.get_pointer_value(currentNode->size), currentNode->keys.get_pointer_value_degree(currentNode->size));
                shiftLevel(Val, findParent(Root, currentNode), newNode);
            }
        }
    }
    void search(t_int val)
    {
        if (Root == NULL)
        {
            cout << "Node Is Empty" << endl;
            return;
        }
        else
        {
            t_bplus_tree_node *currentNode = Root;
            while (currentNode->isLeaf == false)
            {
                for (int i = 0; i < currentNode->size; i++)
                {
                    if (val.get_value() == currentNode->keys.get_pointer_value(i))
                    {
                        currentNode = currentNode->pointer[i];
                        break;
                    }
                    if (i == currentNode->size - 1)
                    {
                        currentNode = currentNode->pointer[i + 1];
                        break;
                    }
                }
            }
            for (int i = 0; i < currentNode->size; i++)
            {
                if (currentNode->keys.get_pointer_value(i) == val.get_value())
                {
                    cout << "Key Found" << endl;
                    return;
                }
            }
            cout << "Key Not Found" << endl;
        }
    }
    void display(t_bplus_tree_node *currentNode)
    {
        if (currentNode == NULL)
        {
            cout << "Node Is Empty" << endl;
            return;
        }
        queue<t_bplus_tree_node *> Q;
        Q.push(currentNode);
        while (!Q.empty())
        {
            int length;
            length = Q.size();
            for (int i = 0; i < length; i++)
            {
                t_bplus_tree_node *tempNode = Q.front();
                Q.pop();
                for (int j = 0; j < tempNode->size; j++)
                {
                    if (tempNode != NULL)
                        cout << tempNode->keys.get_pointer_value(j) << " ";
                }
                for (int j = 0; j < tempNode->size + 1; j++)
                {
                    if (tempNode->pointer[j] != NULL)
                        Q.push(tempNode->pointer[j]);
                }
                cout << "\t";
            }
            cout << endl;
        }
    }
    t_bplus_tree_node *findParent(t_bplus_tree_node *currentNode, t_bplus_tree_node *child)
    {
        t_bplus_tree_node *Parent;
        if (currentNode->isLeaf || (currentNode->pointer[0]->isLeaf))
        {
            return NULL;
        }
        for (int i = 0; i < currentNode->size + 1; i++)
        {
            if (currentNode->pointer[i] == child)
            {
                Parent = currentNode;
                return Parent;
            }
            else
            {
                Parent = findParent(currentNode->pointer[i], child);
                if (Parent != NULL)
                    return Parent;
            }
        }
        return Parent;
    }
    int getMaxKeyValue(t_bplus_tree_node *Node)
    {
        while (!Node->isLeaf)
        {
            Node = Node->pointer[Node->size];
        }
        return Node->keys.get_pointer_value(Node->size - 1);
    }
    void Remove(t_int Value)
    {
        if (Root == NULL)
        {
            cout << "Tree Is Empty" << endl;
            return;
        }
        else
        {
            t_bplus_tree_node *currentNode = Root;
            t_bplus_tree_node *Parent;
            int leftSibling, rightSibling;
            while (currentNode->isLeaf == false)
            {
                for (int i = 0; i < currentNode->size; i++)
                {
                    Parent = currentNode;
                    leftSibling = i - 1;
                    rightSibling = i + 1;
                    if (Value.get_value() <= currentNode->keys.get_pointer_value(i))
                    {
                        currentNode = currentNode->pointer[i];
                        break;
                    }
                    if (i == currentNode->size - 1)
                    {
                        leftSibling = i;
                        rightSibling = i + 2;
                        currentNode = currentNode->pointer[i + 1];
                        break;
                    }
                }
            }
            bool found = false;
            int position;
            for (position = 0; position <= currentNode->size; position++)
            {
                if (currentNode->keys.get_pointer_value(position) == Value.get_value())
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Value Not Found" << endl;
                return;
            }
            for (int j = position; j < currentNode->size; j++)
            {
                int location = j + 1;
                currentNode->keys.set_pointer_value(j, currentNode->keys.get_pointer_value(location));
                currentNode->keys.set_pointer_value_degree(j, currentNode->keys.get_pointer_value_degree(location));
            }
            currentNode->size--;
            if (currentNode == Root)
            {
                for (int i = 0; i < ORDER + 1; i++)
                {
                    currentNode->pointer[i] = NULL;
                }
                if (currentNode->size == 0)
                {
                    cout << "Tree Is Dead" << endl;
                    delete[] currentNode->pointer;
                    delete currentNode;
                    Root = NULL;
                }
                return;
            }
            currentNode->pointer[currentNode->size] = currentNode->pointer[currentNode->size + 1];
            currentNode->pointer[currentNode->size + 1] = NULL;
            if (currentNode->size >= (ORDER + 1) / 2)
                return;
            if (leftSibling >= 0)
            {
                t_bplus_tree_node *leftNode = Parent->pointer[leftSibling];
                if (leftNode->size >= ((ORDER + 1) / 2) + 1)
                {
                    for (int j = currentNode->size; j > 0; j--)
                    {
                        int loc = j - 1;
                        if (currentNode->keys.g_indexD(j) == L)
                        {
                            currentNode->keys.s_indexD(j, T);
                            currentNode->keys.set_pointer_value(j, -1);
                            currentNode->keys.set_pointer_value_degree(j, T);
                        }
                        currentNode->keys.set_pointer_value(j, currentNode->keys.get_pointer_value(loc));
                        currentNode->keys.set_pointer_value_degree(j, currentNode->keys.get_pointer_value_degree(loc));
                    }
                    currentNode->size++;
                    currentNode->pointer[currentNode->size] = currentNode->pointer[currentNode->size - 1];
                    currentNode->pointer[currentNode->size - 1] = NULL;
                    int l = 0;
                    int lo = leftNode->size - 1;
                    if (currentNode->keys.g_indexD(0) == L)
                    {
                        currentNode->keys.s_indexD(0, T);
                        currentNode->keys.set_pointer_value(l, -1);
                        currentNode->keys.set_pointer_value_degree(l, T);
                    }
                    currentNode->keys.set_pointer_value(l, leftNode->keys.get_pointer_value(lo));
                    currentNode->keys.set_pointer_value_degree(l, leftNode->keys.get_pointer_value_degree(lo));
                    leftNode->size--;
                    leftNode->pointer[leftNode->size] = currentNode;
                    leftNode->pointer[leftNode->size + 1] = NULL;
                    if (Parent->keys.g_indexD(leftSibling) == L)
                    {
                        Parent->keys.s_indexD(leftSibling, T);
                        Parent->keys.set_pointer_value(leftSibling, -1);
                        Parent->keys.set_pointer_value_degree(leftSibling, T);
                    }
                    Parent->keys.set_pointer_value(leftSibling, currentNode->keys.get_pointer_value(l));
                    Parent->keys.set_pointer_value_degree(leftSibling, currentNode->keys.get_pointer_value_degree(l));
                    return;
                }
            }
            if (rightSibling <= Parent->size)
            {
                t_bplus_tree_node *rightNode = Parent->pointer[rightSibling];
                if (rightNode->size >= ((ORDER + 1) / 2) + 1)
                {
                    currentNode->size++;
                    currentNode->pointer[currentNode->size] = currentNode->pointer[currentNode->size - 1];
                    currentNode->pointer[currentNode->size - 1] = NULL;
                    int Lo = currentNode->size - 1;
                    int l = 0;
                    if (currentNode->keys.g_indexD(currentNode->size - 1) == L)
                    {
                        currentNode->keys.s_indexD(currentNode->size - 1, T);
                        currentNode->keys.set_pointer_value(Lo, -1);
                        currentNode->keys.set_pointer_value_degree(Lo, T);
                    }
                    currentNode->keys.set_pointer_value(Lo, rightNode->keys.get_pointer_value(l));
                    currentNode->keys.set_pointer_value_degree(Lo, rightNode->keys.get_pointer_value_degree(l));
                    rightNode->size--;
                    rightNode->pointer[rightNode->size] = rightNode->pointer[rightNode->size + 1];
                    rightNode->pointer[rightNode->size + 1] = NULL;
                    for (int i = 0; i < rightNode->size; i++)
                    {
                        int loca = i + 1;
                        rightNode->keys.set_pointer_value(i, rightNode->keys.get_pointer_value(loca));
                        rightNode->keys.set_pointer_value(i, rightNode->keys.get_pointer_value_degree(loca));
                    }
                    int location = rightSibling - 1;
                    int x = 0;
                    if (Parent->keys.g_indexD(rightSibling - 1) == L)
                    {
                        Parent->keys.s_indexD(rightSibling - 1, T);
                        Parent->keys.set_pointer_value(location, -1);
                        Parent->keys.set_pointer_value_degree(location, T);
                    }
                    Parent->keys.set_pointer_value(location, rightNode->keys.get_pointer_value(x));
                    Parent->keys.set_pointer_value_degree(location, rightNode->keys.get_pointer_value_degree(x));
                    return;
                }
            }
            if (leftSibling >= 0)
            {
                t_bplus_tree_node *leftNode = Parent->pointer[leftSibling];
                for (int k = leftNode->size, j = 0; j < currentNode->size; j++, k++)
                {
                    if (leftNode->keys.g_indexD(k) == L)
                    {
                        leftNode->keys.s_indexD(k, T);
                        leftNode->keys.set_pointer_value(k, -1);
                        leftNode->keys.set_pointer_value_degree(k, T);
                    }
                    leftNode->keys.set_pointer_value(k, currentNode->keys.get_pointer_value(j));
                    leftNode->keys.set_pointer_value_degree(k, currentNode->keys.get_pointer_value_degree(j));
                }
                leftNode->pointer[leftNode->size] = NULL;
                leftNode->size += currentNode->size;
                leftNode->pointer[leftNode->size] = currentNode->pointer[currentNode->size];
                Merge(Parent->keys.get_pointer_value(leftSibling), Parent, currentNode);
                delete[] currentNode->pointer;
                delete currentNode;
            }
            else if (rightSibling <= Parent->size)
            {
                t_bplus_tree_node *rightNode = Parent->pointer[rightSibling];
                for (int k = currentNode->size, j = 0; j < rightNode->size; j++, k++)
                {
                    if (currentNode->keys.g_indexD(k) == L)
                    {
                        currentNode->keys.s_indexD(k, T);
                        currentNode->keys.set_pointer_value(k, -1);
                        currentNode->keys.set_pointer_value_degree(k, T);
                    }
                    currentNode->keys.set_pointer_value(k, rightNode->keys.get_pointer_value(j));
                    currentNode->keys.set_pointer_value_degree(k, rightNode->keys.get_pointer_value_degree(j));
                }
                currentNode->pointer[currentNode->size] = NULL;
                currentNode->size += rightNode->size;
                currentNode->pointer[currentNode->size] = rightNode->pointer[rightNode->size];
                Merge(Parent->keys.get_pointer_value(rightSibling - 1) , Parent , rightNode);
                delete[] rightNode->pointer;
                delete rightNode;
            }
        }
    }
    void Merge(int value, t_bplus_tree_node *currentNode, t_bplus_tree_node *childNode)
    {
        if (currentNode == Root)
        {
            if (currentNode->size == 1)
            {
                if (currentNode->pointer[1] == childNode)
                {
                    delete[] childNode->pointer;
                    delete childNode;
                    Root = currentNode->pointer[0];
                    delete[] currentNode->pointer;
                    delete currentNode;
                }
                else if (currentNode->pointer[0] == childNode)
                {
                    delete[] childNode->pointer;
                    delete childNode;
                    Root = currentNode->pointer[1];
                    delete[] currentNode->pointer;
                    delete currentNode;
                    return;
                }
            }
        }
        int position;
        for (position = 0; position < currentNode->size; position++)
        {
            if (currentNode->keys.get_pointer_value(position) == value)
                break;
        }
        for (int i = 0; i < position; i++)
        {
            int location = i + 1;
            currentNode->keys.set_pointer_value(i, currentNode->keys.get_pointer_value(location));
            currentNode->keys.set_pointer_value_degree(i, currentNode->keys.get_pointer_value_degree(location));
        }
        for (position = 0; position < currentNode->size + 1; position++)
        {
            if (currentNode->pointer[position] == childNode)
                break;
        }
        for (int i = position; i < currentNode->size + 1; i++)
        {
            currentNode->pointer[i] = currentNode->pointer[i + 1];
        }
        currentNode->size--;
        if (currentNode->size >= ((ORDER + 1) / 2) - 1)
        {
            return;
        }
        if (currentNode == Root)
            return;
        t_bplus_tree_node *Parent = findParent(Root, currentNode);
        int rightSibling, leftSibling;
        for (position = 0; position < Parent->size + 1; position++)
        {
            if (Parent->pointer[position] == currentNode)
            {
                leftSibling = position - 1;
                rightSibling = position + 1;
                break;
            }
        }
        if (leftSibling >= 0)
        {
            t_bplus_tree_node *leftNode = Parent->pointer[leftSibling];
            if (leftNode->size >= ((ORDER + 1) / 2))
            {
                for (int i = currentNode->size; i > 0; i--)
                {
                    int locatio = i - 1;
                    if (currentNode->keys.g_indexD(i) == L)
                    {
                        currentNode->keys.s_indexD(i, T);
                        currentNode->keys.set_pointer_value(i, -1);
                        currentNode->keys.set_pointer_value_degree(i, T);
                    }
                    currentNode->keys.set_pointer_value(i, currentNode->keys.get_pointer_value(locatio));
                    currentNode->keys.set_pointer_value_degree(i, currentNode->keys.get_pointer_value_degree(locatio));
                }
                int locati = 0;
                if (currentNode->keys.g_indexD(0) == L)
                {
                    currentNode->keys.s_indexD(0, T);
                    currentNode->keys.set_pointer_value(locati, -1);
                    currentNode->keys.set_pointer_value_degree(locati, T);
                }
                currentNode->keys.set_pointer_value(locati, Parent->keys.get_pointer_value(leftSibling));
                currentNode->keys.set_pointer_value_degree(locati, Parent->keys.get_pointer_value_degree(leftSibling));
                int locat = leftNode->size - 1;
                Parent->keys.set_pointer_value(leftSibling, leftNode->keys.get_pointer_value(locat));
                Parent->keys.set_pointer_value_degree(leftSibling, leftNode->keys.get_pointer_value_degree(locat));
                for (int i = currentNode->size + 1; i > 0; i--)
                    currentNode->pointer[i] = currentNode->pointer[i - 1];
                currentNode->pointer[0] = leftNode->pointer[leftNode->size];
                currentNode->size++;
                leftNode->size--;
                return;
            }
        }
        if (rightSibling <= Parent->size)
        {
            t_bplus_tree_node *rightNode = Parent->pointer[rightSibling];
            if (rightNode->size >= ((ORDER + 1) / 2))
            {
                if (currentNode->keys.g_indexD(currentNode->size) == L)
                {
                    currentNode->keys.s_indexD(currentNode->size, T);
                    currentNode->keys.set_pointer_value(currentNode->size, -1);
                    currentNode->keys.set_pointer_value_degree(currentNode->size, T);
                }
                currentNode->keys.set_pointer_value(currentNode->size, Parent->keys.get_pointer_value(position));
                currentNode->keys.set_pointer_value_degree(currentNode->size, Parent->keys.get_pointer_value_degree(position));
                int location = 0;
                Parent->keys.set_pointer_value(position, rightNode->keys.get_pointer_value(location));
                Parent->keys.set_pointer_value_degree(position, rightNode->keys.get_pointer_value_degree(location));
                for (int j = 0; j < rightNode->size - 1; j++)
                {
                    int locatio = j + 1;
                    rightNode->keys.set_pointer_value(j, rightNode->keys.get_pointer_value(locatio));
                    rightNode->keys.set_pointer_value_degree(j, rightNode->keys.get_pointer_value_degree(locatio));
                }
                currentNode->pointer[currentNode->size + 1] = rightNode->pointer[0];
                for (int j = 0; j < rightNode->size; j++)
                    rightNode->pointer[j] = rightNode->pointer[j + 1];
                currentNode->size++;
                rightNode->size--;
                return;
            }
        }
        if (leftSibling >= 0)
        {
            t_bplus_tree_node *leftNode = Parent->pointer[leftSibling];
            if (leftNode->keys.g_indexD(leftNode->size) == L)
            {
                leftNode->keys.s_indexD(leftNode->size, T);
                leftNode->keys.set_pointer_value(leftNode->size, -1);
                leftNode->keys.set_pointer_value_degree(leftNode->size, T);
            }
            leftNode->keys.set_pointer_value(leftNode->size, Parent->keys.get_pointer_value(leftSibling));
            leftNode->keys.set_pointer_value_degree(leftNode->size, Parent->keys.get_pointer_value_degree(leftSibling));
            for (int k = leftNode->size + 1, j = 0; j < currentNode->size + 1; j++, k++)
            {
                leftNode->pointer[k] = currentNode->pointer[j];
                currentNode->pointer[j] = NULL;
            }
            leftNode->size += currentNode->size + 1;
            currentNode->size = 0;
            Merge(Parent->keys.get_pointer_value(leftSibling), Parent, currentNode);
        }
        else if (rightSibling <= Parent->size)
        {
            t_bplus_tree_node *rightNode = Parent->pointer[rightSibling];
            if (currentNode->keys.g_indexD(currentNode->size) == L)
            {
                currentNode->keys.s_indexD(currentNode->size, T);
                currentNode->keys.set_pointer_value(currentNode->size, -1);
                currentNode->keys.set_pointer_value_degree(currentNode->size, T);
            }
            int location = rightSibling - 1;
            currentNode->keys.set_pointer_value(currentNode->size, Parent->keys.get_pointer_value(location));
            currentNode->keys.set_pointer_value_degree(currentNode->size, Parent->keys.get_pointer_value_degree(location));
            for (int k = currentNode->size + 1, j = 0; j < rightNode->size; j++, k++)
            {
                if (currentNode->keys.g_indexD(k) == L)
                {
                    currentNode->keys.s_indexD(k, T);
                    currentNode->keys.set_pointer_value(k, -1);
                    currentNode->keys.set_pointer_value_degree(k, T);
                }
                currentNode->keys.set_pointer_value(k, rightNode->keys.get_pointer_value(j));
                currentNode->keys.set_pointer_value_degree(k, rightNode->keys.get_pointer_value_degree(j));
            }
            for (int k = currentNode->size + 1, j = 0; j < rightNode->size + 1; j++, k++)
            {
                currentNode->pointer[k] = rightNode->pointer[j];
                rightNode->pointer[j] = NULL;
            }
            currentNode->size += rightNode->size + 1;
            rightNode->size = 0;
            Merge(Parent->keys.get_pointer_value(rightSibling - 1), Parent, rightNode);
        }
    }
};