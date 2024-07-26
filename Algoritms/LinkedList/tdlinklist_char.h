#include "tdnode_char.h"
tdnode_char *dlinklist_insert(tdnode_char *head, tdnode_char &obj);
tdnode_char *dlinklist_delete(tdnode_char *head, int i);
tdnode_char *dlinklist_insert(tdnode_char *head, Degree degree, char value, Degree value_degree);
class tdlinklist_char
{
    tdnode_char *head = NULL;

public:
    void insert_node(tdnode_char &obj)
    {
        head = dlinklist_insert(head, obj);
    }
    void insert_node(Degree degree, char value, Degree value_degree)
    {
        head = dlinklist_insert(head, degree, value, value_degree);
    }
    void linklist_print()
    {
        tdnode_char *temp = head;
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
        tdnode_char input;
        t_scan(input);
        head = dlinklist_insert(head, input);
    }
};
void t_scan(tdlinklist_char &obj)
{
    obj.linklist_scan();
}
tdnode_char *dlinklist_insert(tdnode_char *head, tdnode_char &obj)
{
    tdnode_char *newNode = new tdnode_char(obj);
    newNode->next = NULL;
    tdnode_char *temp = head;
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
tdnode_char *dlinklist_insert(tdnode_char *head, Degree degree, char value, Degree value_degree)
{
    tdnode_char *newNode = new tdnode_char(degree, value, value_degree);
    newNode->next = NULL;
    tdnode_char *temp = head;
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
tdnode_char *dlinklist_delete(tdnode_char *head, int i)
{
    if (head == NULL)
    {
        cout << "Link List Is Empty" << endl;
        return head;
    }
    if (i == 0)
    {
        tdnode_char *temp = head->next;
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
void t_print(tdlinklist_char &obj)
{
    obj.linklist_print();
}