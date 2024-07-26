#include "tnode_ldouble.h"
tnode_ldouble *clinklist_insert(tnode_ldouble *head, tnode_ldouble &obj);
tnode_ldouble *clinklist_delete(tnode_ldouble *head, int i);
tnode_ldouble *clinklist_insert(tnode_ldouble *head, Degree degree, long double value, Degree value_degree);
class tclinklist_ldouble
{
    tnode_ldouble *head = NULL;

public:
    void insert_node(tnode_ldouble &obj)
    {
        head = clinklist_insert(head, obj);
    }
    void insert_node(Degree degree, long double value, Degree value_degree)
    {
        head = clinklist_insert(head, degree, value, value_degree);
    }
    void delete_node(int i)
    {
        head = clinklist_delete(head , i);
    }
     void linklist_scan()
    {
        tnode_ldouble input;
        t_scan(input);
        head = clinklist_insert(head, input);
    }
    void linklist_print()
    {
        tnode_ldouble *temp;
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
void t_scan(tclinklist_ldouble &obj)
{
    obj.linklist_scan();
}
tnode_ldouble *clinklist_insert(tnode_ldouble *head, tnode_ldouble &obj)
{
    if (head == NULL)
    {
        tnode_ldouble *newNode = new tnode_ldouble(obj);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_ldouble *newNode = new tnode_ldouble(obj);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_ldouble *clinklist_insert(tnode_ldouble *head, Degree degree, long double value, Degree value_degree)
{
    if (head == NULL)
    {
        tnode_ldouble *newNode = new tnode_ldouble(degree, value, value_degree);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_ldouble *newNode = new tnode_ldouble(degree, value, value_degree);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_ldouble *clinklist_delete(tnode_ldouble *head, int i)
{
    if (i == 0)
    {
        tnode_ldouble *temp = head->next;
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
void t_print(tclinklist_ldouble &obj)
{
    obj.linklist_print();
}