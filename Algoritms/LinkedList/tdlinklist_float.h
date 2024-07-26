#include "tdnode_float.h"
tdnode_float *dlinklist_insert(tdnode_float *head, tdnode_float &obj);
tdnode_float *dlinklist_delete(tdnode_float *head, int i);
tdnode_float *dlinklist_insert(tdnode_float *head, Degree degree, float value, Degree value_degree);
class tdlinklist_float
{
    tdnode_float *head = NULL;

public:
    void insert_node(tdnode_float &obj)
    {
        head = dlinklist_insert(head, obj);
    }
    void insert_node(Degree degree, float value, Degree value_degree)
    {
        head = dlinklist_insert(head, degree, value, value_degree);
    }
    void linklist_print()
    {
        tdnode_float *temp = head;
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
        tdnode_float input;
        t_scan(input);
        head = dlinklist_insert(head, input);
    }
};
void t_scan(tdlinklist_float &obj)
{
    obj.linklist_scan();
}
tdnode_float *dlinklist_insert(tdnode_float *head, tdnode_float &obj)
{
    tdnode_float *newNode = new tdnode_float(obj);
    newNode->next = NULL;
    tdnode_float *temp = head;
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
tdnode_float *dlinklist_insert(tdnode_float *head, Degree degree, float value, Degree value_degree)
{
    tdnode_float *newNode = new tdnode_float(degree, value, value_degree);
    newNode->next = NULL;
    tdnode_float *temp = head;
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
tdnode_float *dlinklist_delete(tdnode_float *head, int i)
{
    if (head == NULL)
    {
        cout << "Link List Is Empty" << endl;
        return head;
    }
    if (i == 0)
    {
        tdnode_float *temp = head->next;
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
void t_print(tdlinklist_float &obj)
{
    obj.linklist_print();
}