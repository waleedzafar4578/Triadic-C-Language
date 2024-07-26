#include "tnode_sint.h"
tnode_sint *clinklist_insert(tnode_sint *head, tnode_sint &obj);
tnode_sint *clinklist_delete(tnode_sint *head, int i);
tnode_sint *clinklist_insert(tnode_sint *head, Degree degree, short int value, Degree value_degree);
class tclinklist_sint
{
    tnode_sint *head = NULL;

public:
    void insert_node(tnode_sint &obj)
    {
        head = clinklist_insert(head, obj);
    }
    void insert_node(Degree degree, short int value, Degree value_degree)
    {
        head = clinklist_insert(head, degree, value, value_degree);
    }
    void delete_node(int i)
    {
        head = clinklist_delete(head , i);
    }
     void linklist_scan()
    {
        tnode_sint input;
        t_scan(input);
        head = clinklist_insert(head, input);
    }
    void linklist_print()
    {
        tnode_sint *temp;
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
void t_scan(tclinklist_sint &obj)
{
    obj.linklist_scan();
}
tnode_sint *clinklist_insert(tnode_sint *head, tnode_sint &obj)
{
    if (head == NULL)
    {
        tnode_sint *newNode = new tnode_sint(obj);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_sint *newNode = new tnode_sint(obj);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_sint *clinklist_insert(tnode_sint *head, Degree degree, short int value, Degree value_degree)
{
    if (head == NULL)
    {
        tnode_sint *newNode = new tnode_sint(degree, value, value_degree);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_sint *newNode = new tnode_sint(degree, value, value_degree);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_sint *clinklist_delete(tnode_sint *head, int i)
{
    if (i == 0)
    {
        tnode_sint *temp = head->next;
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
void t_print(tclinklist_sint &obj)
{
    obj.linklist_print();
}