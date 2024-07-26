#include "tnode_bool.h"
tnode_bool *clinklist_insert(tnode_bool *head, tnode_bool &obj);
tnode_bool *clinklist_delete(tnode_bool *head, int i);
tnode_bool *clinklist_insert(tnode_bool *head, Degree degree, bool value, Degree value_degree);
class tclinklist_bool
{
    tnode_bool *head = NULL;

public:
    void insert_node(tnode_bool &obj)
    {
        head = clinklist_insert(head, obj);
    }
    void insert_node(Degree degree, bool value, Degree value_degree)
    {
        head = clinklist_insert(head, degree, value, value_degree);
    }
    void delete_node(int i)
    {
        head = clinklist_delete(head , i);
    }
     void linklist_scan()
    {
        tnode_bool input;
        t_scan(input);
        head = clinklist_insert(head, input);
    }
    void linklist_print()
    {
        tnode_bool *temp;
        if (head == NULL)
        {
            cout << "Link List Is Empty" << endl;
            return;
        }
        temp = head;
        do
        {
            t_print(*temp);
            temp = temp->next;
        } while (temp != head);
    }
};
void t_scan(tclinklist_bool &obj)
{
    obj.linklist_scan();
}
tnode_bool *clinklist_insert(tnode_bool *head, tnode_bool &obj)
{
    if (head == NULL)
    {
        tnode_bool *newNode = new tnode_bool(obj);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_bool *newNode = new tnode_bool(obj);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_bool *clinklist_insert(tnode_bool *head, Degree degree, bool value, Degree value_degree)
{
    if (head == NULL)
    {
        tnode_bool *newNode = new tnode_bool(degree, value, value_degree);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_bool *newNode = new tnode_bool(degree, value, value_degree);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_bool *clinklist_delete(tnode_bool *head, int i)
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
    head->next = clinklist_delete(head->next, --i);
    return head;
}
void t_print(tclinklist_bool &obj)
{
    obj.linklist_print();
}