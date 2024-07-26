#include "tnode_int.h"
tnode_int *clinklist_insert(tnode_int *head, tnode_int &obj);
tnode_int *clinklist_delete(tnode_int *head, int i);
tnode_int *clinklist_insert(tnode_int *head, Degree degree, int value, Degree value_degree);
class tclinklist_int
{
    tnode_int *head = NULL;

public:
    void insert_node(tnode_int &obj)
    {
        head = clinklist_insert(head, obj);
    }
    void insert_node(Degree degree, int value, Degree value_degree)
    {
        head = clinklist_insert(head, degree, value, value_degree);
    }
    void delete_node(int i)
    {
        head = clinklist_delete(head, i);
    }
    void linklist_scan()
    {
        tnode_int input;
        t_scan(input);
        head = clinklist_insert(head, input);
    }
    void linklist_print()
    {
        tnode_int *temp;
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
void t_scan(tclinklist_int &obj)
{
    obj.linklist_scan();
}
tnode_int *clinklist_insert(tnode_int *head, tnode_int &obj)
{
    if (head == NULL)
    {
        tnode_int *newNode = new tnode_int(obj);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_int *newNode = new tnode_int(obj);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_int *clinklist_insert(tnode_int *head, Degree degree, int value, Degree value_degree)
{
    if (head == NULL)
    {
        tnode_int *newNode = new tnode_int(degree, value, value_degree);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_int *newNode = new tnode_int(degree, value, value_degree);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_int *clinklist_delete(tnode_int *head, int i)
{
    if (i == 0)
    {
        tnode_int *temp = head->next;
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
void t_print(tclinklist_int &obj)
{
    obj.linklist_print();
}