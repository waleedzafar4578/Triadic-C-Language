#include "tnode_uint.h"
tnode_uint *clinklist_insert(tnode_uint *head, tnode_uint &obj);
tnode_uint *clinklist_delete(tnode_uint *head, int i);
tnode_uint *clinklist_insert(tnode_uint *head, Degree degree, unsigned int value, Degree value_degree);
class tclinklist_uint
{
    tnode_uint *head = NULL;

public:
    void insert_node(tnode_uint &obj)
    {
        head = clinklist_insert(head, obj);
    }
    void insert_node(Degree degree, unsigned int value, Degree value_degree)
    {
        head = clinklist_insert(head, degree, value, value_degree);
    }
    void delete_node(int i)
    {
        head = clinklist_delete(head , i);
    }
     void linklist_scan()
    {
        tnode_uint input;
        t_scan(input);
        head = clinklist_insert(head, input);
    }
    void linklist_print()
    {
        tnode_uint *temp;
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
void t_scan(tclinklist_uint &obj)
{
    obj.linklist_scan();
}
tnode_uint *clinklist_insert(tnode_uint *head, tnode_uint &obj)
{
    if (head == NULL)
    {
        tnode_uint *newNode = new tnode_uint(obj);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_uint *newNode = new tnode_uint(obj);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_uint *clinklist_insert(tnode_uint *head, Degree degree, unsigned int value, Degree value_degree)
{
    if (head == NULL)
    {
        tnode_uint *newNode = new tnode_uint(degree, value, value_degree);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_uint *newNode = new tnode_uint(degree, value, value_degree);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_uint *clinklist_delete(tnode_uint *head, int i)
{
    if (i == 0)
    {
        tnode_uint *temp = head->next;
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
void t_print(tclinklist_uint &obj)
{
    obj.linklist_print();
}