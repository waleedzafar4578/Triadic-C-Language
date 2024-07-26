#include "tnode_double.h"
tnode_double *clinklist_insert(tnode_double *head, tnode_double &obj);
tnode_double *clinklist_delete(tnode_double *head, int i);
tnode_double *clinklist_insert(tnode_double *head, Degree degree, double value, Degree value_degree);
class tclinklist_double
{
    tnode_double *head = NULL;

public:
    void insert_node(tnode_double &obj)
    {
        head = clinklist_insert(head, obj);
    }
    void insert_node(Degree degree, double value, Degree value_degree)
    {
        head = clinklist_insert(head, degree, value, value_degree);
    }
    void delete_node(int i)
    {
        head = clinklist_delete(head , i);
    }
     void linklist_scan()
    {
        tnode_double input;
        t_scan(input);
        head = clinklist_insert(head, input);
    }
    void linklist_print()
    {
        tnode_double *temp;
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
void t_scan(tclinklist_double &obj)
{
    obj.linklist_scan();
}
tnode_double *clinklist_insert(tnode_double *head, tnode_double &obj)
{
    if (head == NULL)
    {
        tnode_double *newNode = new tnode_double(obj);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_double *newNode = new tnode_double(obj);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_double *clinklist_insert(tnode_double *head, Degree degree, double value, Degree value_degree)
{
    if (head == NULL)
    {
        tnode_double *newNode = new tnode_double(degree, value, value_degree);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_double *newNode = new tnode_double(degree, value, value_degree);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_double *clinklist_delete(tnode_double *head, int i)
{
    if (i == 0)
    {
        tnode_double *temp = head->next;
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
void t_print(tclinklist_double &obj)
{
    obj.linklist_print();
}