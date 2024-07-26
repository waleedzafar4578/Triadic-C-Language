#include "tnode_float.h"
tnode_float *clinklist_insert(tnode_float *head, tnode_float &obj);
tnode_float *clinklist_delete(tnode_float *head, int i);
tnode_float *clinklist_insert(tnode_float *head, Degree degree, float value, Degree value_degree);
class tclinklist_float
{
    tnode_float *head = NULL;

public:
    void insert_node(tnode_float &obj)
    {
        head = clinklist_insert(head, obj);
    }
    void insert_node(Degree degree, float value, Degree value_degree)
    {
        head = clinklist_insert(head, degree, value, value_degree);
    }
    void delete_node(int i)
    {
        head = clinklist_delete(head , i);
    }
     void linklist_scan()
    {
        tnode_float input;
        t_scan(input);
        head = clinklist_insert(head, input);
    }
    void linklist_print()
    {
        tnode_float *temp;
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
void t_scan(tclinklist_float &obj)
{
    obj.linklist_scan();
}
tnode_float *clinklist_insert(tnode_float *head, tnode_float &obj)
{
    if (head == NULL)
    {
        tnode_float *newNode = new tnode_float(obj);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_float *newNode = new tnode_float(obj);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_float *clinklist_insert(tnode_float *head, Degree degree, float value, Degree value_degree)
{
    if (head == NULL)
    {
        tnode_float *newNode = new tnode_float(degree, value, value_degree);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_float *newNode = new tnode_float(degree, value, value_degree);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_float *clinklist_delete(tnode_float *head, int i)
{
    if (i == 0)
    {
        tnode_float *temp = head->next;
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
void t_print(tclinklist_float &obj)
{
    obj.linklist_print();
}