#include "tnode_bool.h"
tnode_bool *linklist_insert(tnode_bool *head, tnode_bool &obj);
tnode_bool *linklist_delete(tnode_bool *head, int i);
tnode_bool *linklist_insert(tnode_bool *head, Degree degree, bool value, Degree value_degree);
class tlinklist_bool
{
    tnode_bool *head = NULL;

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
    void insert_node(tnode_bool &obj)
    {
        head = linklist_insert(head, obj);
    }
    void insert_node(Degree degree, bool value, Degree value_degree)
    {
        head = linklist_insert(head, degree, value, value_degree);
    }

    void linklist_print()
    {
        tnode_bool *temp = head;
        for (; temp != NULL; temp = temp->next)
        {
            t_print(*temp);
        }
    }
    void linklist_scan()
    {
        tnode_bool input;
        t_scan(input);
        head = linklist_insert(head, input);
    }
    void delete_node(int i)
    {
        head = linklist_delete(head, i);
    }
};
void t_scan(tlinklist_bool &obj)
{
    obj.linklist_scan();
}
void t_print(tlinklist_bool &obj)
{
    obj.linklist_print();
}
tnode_bool *linklist_insert(tnode_bool *head, tnode_bool &obj)
{
    if (head == NULL)
    {
        return new tnode_bool(obj);
    }
    head->next = linklist_insert(head->next, obj);
    return head;
}
tnode_bool *linklist_insert(tnode_bool *head, Degree degree, bool value, Degree value_degree)
{
    if (head == NULL)
    {
        return new tnode_bool(degree, value, value_degree);
    }
    head->next = linklist_insert(head->next, degree, value, value_degree);
    return head;
}
tnode_bool *linklist_delete(tnode_bool *head, int i)
{
    if (i == 0)
    {
        tnode_bool *temp = head->next;
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