#include "tdnode_sint.h"
tdnode_sint *dlinklist_insert(tdnode_sint *head, tdnode_sint &obj);
tdnode_sint *dlinklist_delete(tdnode_sint *head, int i);
tdnode_sint *dlinklist_insert(tdnode_sint *head, Degree degree, short int value, Degree value_degree);
class tdlinklist_sint
{
    tdnode_sint *head = NULL;

public:
    void insert_node(tdnode_sint &obj)
    {
        head = dlinklist_insert(head, obj);
    }
    void insert_node(Degree degree, short int value, Degree value_degree)
    {
        head = dlinklist_insert(head, degree, value, value_degree);
    }
    void linklist_print()
    {
        tdnode_sint *temp = head;
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
        tdnode_sint input;
        t_scan(input);
        head = dlinklist_insert(head, input);
    }
};
void t_scan(tdlinklist_sint &obj)
{
    obj.linklist_scan();
}
tdnode_sint *dlinklist_insert(tdnode_sint *head, tdnode_sint &obj)
{
    tdnode_sint *newNode = new tdnode_sint(obj);
    newNode->next = NULL;
    tdnode_sint *temp = head;
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
tdnode_sint *dlinklist_insert(tdnode_sint *head, Degree degree, short int value, Degree value_degree)
{
    tdnode_sint *newNode = new tdnode_sint(degree, value, value_degree);
    newNode->next = NULL;
    tdnode_sint *temp = head;
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
tdnode_sint *dlinklist_delete(tdnode_sint *head, int i)
{
    if (head == NULL)
    {
        cout << "Link List Is Empty" << endl;
        return head;
    }
    if (i == 0)
    {
        tdnode_sint *temp = head->next;
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
void t_print(tdlinklist_sint &obj)
{
    obj.linklist_print();
}