#include "tdnode_bool.h"
tdnode_bool *dlinklist_insert(tdnode_bool *head, tdnode_bool &obj);
tdnode_bool *dlinklist_delete(tdnode_bool *head, int i);
tdnode_bool *dlinklist_insert(tdnode_bool *head, Degree degree, bool value, Degree value_degree);
class tdlinklist_bool
{
    tdnode_bool *head = NULL;

public:
    void insert_node(tdnode_bool &obj)
    {
        head = dlinklist_insert(head, obj);
    }
    void insert_node(Degree degree, bool value, Degree value_degree)
    {
        head = dlinklist_insert(head, degree, value, value_degree);
    }
    void linklist_print()
    {
        tdnode_bool *temp = head;
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
        tdnode_bool input;
        t_scan(input);
        head = dlinklist_insert(head, input);
    }
};
void t_scan(tdlinklist_bool &obj)
{
    obj.linklist_scan();
}
tdnode_bool *dlinklist_insert(tdnode_bool *head, tdnode_bool &obj)
{
    tdnode_bool *newNode = new tdnode_bool(obj);
    newNode->next = NULL;
    tdnode_bool *temp = head;
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
tdnode_bool *dlinklist_insert(tdnode_bool *head, Degree degree, bool value, Degree value_degree)
{
    tdnode_bool *newNode = new tdnode_bool(degree, value, value_degree);
    newNode->next = NULL;
    tdnode_bool *temp = head;
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
tdnode_bool *dlinklist_delete(tdnode_bool *head, int i)
{
    if (head == NULL)
    {
        cout << "Link List Is Empty" << endl;
        return head;
    }
    if (i == 0)
    {
        tdnode_bool *temp = head->next;
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
void t_print(tdlinklist_bool &obj)
{
    obj.linklist_print();
}