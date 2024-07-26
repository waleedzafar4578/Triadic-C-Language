#include "tdnode_double.h"
tdnode_double *dlinklist_insert(tdnode_double *head, tdnode_double &obj);
tdnode_double *dlinklist_delete(tdnode_double *head, int i);
tdnode_double *dlinklist_insert(tdnode_double *head, Degree degree, double value, Degree value_degree);
class tdlinklist_double
{
    tdnode_double *head = NULL;

public:
    void insert_node(tdnode_double &obj)
    {
        head = dlinklist_insert(head, obj);
    }
    void insert_node(Degree degree, double value, Degree value_degree)
    {
        head = dlinklist_insert(head, degree, value, value_degree);
    }
    void linklist_print()
    {
        tdnode_double *temp = head;
        if (head == NULL)
        {
            cout << "The Link List Is Empty" << endl;
        }
        while (temp != NULL)
        {
            t_print(*temp);
            temp = temp->next;
        }
    }
    void delete_node(int i)
    {
        head = dlinklist_delete(head, i);
    }
    void linklist_scan()
    {
        tdnode_double input;
        t_scan(input);
        head = dlinklist_insert(head, input);
    }
};
void t_scan(tdlinklist_double &obj)
{
    obj.linklist_scan();
}
tdnode_double *dlinklist_insert(tdnode_double *head, tdnode_double &obj)
{
    tdnode_double *newNode = new tdnode_double(obj);
    newNode->next = NULL;
    tdnode_double *temp = head;
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return head;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
tdnode_double *dlinklist_insert(tdnode_double *head, Degree degree, double value, Degree value_degree)
{
    tdnode_double *newNode = new tdnode_double(degree, value, value_degree);
    newNode->next = NULL;
    tdnode_double *temp = head;
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return head;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
tdnode_double *dlinklist_delete(tdnode_double *head, int i)
{
    if (head == NULL)
    {
        cout << "Link List Is Empty" << endl;
        return head;
    }
    if (i == 0)
    {
        tdnode_double *temp = head->next;
        delete head;
        return temp;
    }
    else if (head->next == NULL)
    {
        return head;
    }
    head->next = dlinklist_delete(head->next, --i);
    return head;
}
void t_print(tdlinklist_double &obj)
{
    obj.linklist_print();
}