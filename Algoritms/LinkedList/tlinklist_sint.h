#include "tnode_sint.h"
tnode_sint *linklist_insert(tnode_sint *head, tnode_sint &obj);
tnode_sint *linklist_delete(tnode_sint *head, int i);
tnode_sint *linklist_insert(tnode_sint *head, Degree degree, short int value, Degree value_degree);
class tlinklist_sint
{
    tnode_sint *head = NULL;

public:
    // tlink_int(Degree pd, int d, Degree de)
    // {
    //     dlist = new tnode_int(pd, d, de);
    //     dlist->next = nullptr;
    // }
    // tlink_int(tnode_int &obj)
    // {
    //     dlist = new tnode_int(obj);
    //     dlist->next = nullptr;
    // }
    void insert_node(tnode_sint &obj)
    {
        head = linklist_insert(head, obj);
    }
    void insert_node(Degree degree, short int value, Degree value_degree)
    {
        head = linklist_insert(head, degree, value, value_degree);
    }

    void linklist_print()
    {
        tnode_sint *temp = head;
        for (; temp != NULL; temp = temp->next)
        {
            t_print(*temp);
        }
    }
    void linklist_scan()
    {
        tnode_sint input;
        t_scan(input);
        head = linklist_insert(head, input);
    }
    void delete_node(int i)
    {
        head = linklist_delete(head, i);
    }
};
void t_scan(tlinklist_sint &obj)
{
    obj.linklist_scan();
}
void t_print(tlinklist_sint &obj)
{
    obj.linklist_print();
}
tnode_sint *linklist_insert(tnode_sint *head, tnode_sint &obj)
{
    if (head == NULL)
    {
        return new tnode_sint(obj);
    }
    head->next = linklist_insert(head->next, obj);
    return head;
}
tnode_sint *linklist_insert(tnode_sint *head, Degree degree, short int value, Degree value_degree)
{
    if (head == NULL)
    {
        return new tnode_sint(degree, value, value_degree);
    }
    head->next = linklist_insert(head->next, degree, value, value_degree);
    return head;
}
tnode_sint *linklist_delete(tnode_sint *head, int i)
{
    if (i == 0)
    {
        tnode_sint *temp = head->next;
        delete head;
        return temp;
    }
    else if (head->next == NULL)
    {
        return head;
    }
    head->next = linklist_delete(head->next, --i);
    return head;
}