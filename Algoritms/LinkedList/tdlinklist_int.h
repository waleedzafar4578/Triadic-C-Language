#include "tdnode_int.h"
tdnode_int *dlinklist_insert(tdnode_int *head, tdnode_int &obj);
tdnode_int *dlinklist_delete(tdnode_int *head, int i);
tdnode_int *dlinklist_insert(tdnode_int *head, Degree degree, int value, Degree value_degree);
class tdlinklist_int
{
    tdnode_int *head = NULL;

public:
    void insert_node(tdnode_int &obj)
    {
        head = dlinklist_insert(head, obj);
    }
    void insert_node(Degree degree, int value, Degree value_degree)
    {
        head = dlinklist_insert(head, degree, value, value_degree);
    }
    void linklist_print()
    {
        tdnode_int *temp = head;
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
        tdnode_int input;
        t_scan(input);
        head = dlinklist_insert(head, input);
    }
};
void t_scan(tdlinklist_int &obj)
{
    obj.linklist_scan();
}
tdnode_int *dlinklist_insert(tdnode_int *head, tdnode_int &obj)
{
    tdnode_int *newNode = new tdnode_int(obj);
    newNode->next = NULL;
    tdnode_int *temp = head;
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
tdnode_int *dlinklist_insert(tdnode_int *head, Degree degree, int value, Degree value_degree)
{
    tdnode_int *newNode = new tdnode_int(degree, value, value_degree);
    newNode->next = NULL;
    tdnode_int *temp = head;
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
tdnode_int *dlinklist_delete(tdnode_int *head, int i)
{
    if (head == NULL)
    {
        cout << "Link List Is Empty" << endl;
        return head;
    }
    if (i == 0)
    {
        tdnode_int *temp = head->next;
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
void t_print(tdlinklist_int &obj)
{
    obj.linklist_print();
}