#include "tdnode_ldouble.h"
tdnode_ldouble *dlinklist_insert(tdnode_ldouble *head, tdnode_ldouble &obj);
tdnode_ldouble *dlinklist_delete(tdnode_ldouble *head, int i);
tdnode_ldouble *dlinklist_insert(tdnode_ldouble *head, Degree degree, long double value, Degree value_degree);
class tdlinklist_ldouble
{
    tdnode_ldouble *head = NULL;

public:
    void insert_node(tdnode_ldouble &obj)
    {
        head = dlinklist_insert(head, obj);
    }
    void insert_node(Degree degree, long double value, Degree value_degree)
    {
        head = dlinklist_insert(head, degree, value, value_degree);
    }
    void linklist_print()
    {
        tdnode_ldouble *temp = head;
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
        tdnode_ldouble input;
        t_scan(input);
        head = dlinklist_insert(head, input);
    }
};
void t_scan(tdlinklist_ldouble &obj)
{
    obj.linklist_scan();
}
tdnode_ldouble *dlinklist_insert(tdnode_ldouble *head, tdnode_ldouble &obj)
{
    tdnode_ldouble *newNode = new tdnode_ldouble(obj);
    newNode->next = NULL;
    tdnode_ldouble *temp = head;
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
tdnode_ldouble *dlinklist_insert(tdnode_ldouble *head, Degree degree, long double value, Degree value_degree)
{
    tdnode_ldouble *newNode = new tdnode_ldouble(degree, value, value_degree);
    newNode->next = NULL;
    tdnode_ldouble *temp = head;
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
tdnode_ldouble *dlinklist_delete(tdnode_ldouble *head, int i)
{
    if (head == NULL)
    {
        cout << "Link List Is Empty" << endl;
        return head;
    }
    if (i == 0)
    {
        tdnode_ldouble *temp = head->next;
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
void t_print(tdlinklist_ldouble &obj)
{
    obj.linklist_print();
}