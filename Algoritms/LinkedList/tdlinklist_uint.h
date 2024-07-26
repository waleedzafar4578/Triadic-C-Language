#include "tdnode_uint.h"
tdnode_uint *dlinklist_insert(tdnode_uint *head, tdnode_uint &obj);
tdnode_uint *dlinklist_delete(tdnode_uint *head, int i);
tdnode_uint *dlinklist_insert(tdnode_uint *head, Degree degree, unsigned int value, Degree value_degree);
class tdlinklist_uint
{
    tdnode_uint *head = NULL;

public:
    void insert_node(tdnode_uint &obj)
    {
        head = dlinklist_insert(head, obj);
    }
    void insert_node(Degree degree, unsigned int value, Degree value_degree)
    {
        head = dlinklist_insert(head, degree, value, value_degree);
    }
    void linklist_print()
    {
        tdnode_uint *temp = head;
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
        tdnode_uint input;
        t_scan(input);
        head = dlinklist_insert(head, input);
    }
};
void t_scan(tdlinklist_uint &obj)
{
    obj.linklist_scan();
}
tdnode_uint *dlinklist_insert(tdnode_uint *head, tdnode_uint &obj)
{
    tdnode_uint *newNode = new tdnode_uint(obj);
    newNode->next = NULL;
    tdnode_uint *temp = head;
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
tdnode_uint *dlinklist_insert(tdnode_uint *head, Degree degree, unsigned int value, Degree value_degree)
{
    tdnode_uint *newNode = new tdnode_uint(degree, value, value_degree);
    newNode->next = NULL;
    tdnode_uint *temp = head;
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
tdnode_uint *dlinklist_delete(tdnode_uint *head, int i)
{
    if (head == NULL)
    {
        cout << "Link List Is Empty" << endl;
        return head;
    }
    if (i == 0)
    {
        tdnode_uint *temp = head->next;
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
void t_print(tdlinklist_uint &obj)
{
    obj.linklist_print();
}