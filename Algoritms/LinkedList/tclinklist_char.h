#include "tnode_char.h"
tnode_char *clinklist_insert(tnode_char *head, tnode_char &obj);
tnode_char *clinklist_delete(tnode_char *head, int i);
tnode_char *clinklist_insert(tnode_char *head, Degree degree, char value, Degree value_degree);
class tclinklist_char
{
    tnode_char *head = NULL;

public:
    void insert_node(tnode_char &obj)
    {
        head = clinklist_insert(head, obj);
    }
    void insert_node(Degree degree, char value, Degree value_degree)
    {
        head = clinklist_insert(head, degree, value, value_degree);
    }
    void delete_node(int i)
    {
        head = clinklist_delete(head , i);
    }
     void linklist_scan()
    {
        tnode_char input;
        t_scan(input);
        head = clinklist_insert(head, input);
    }
    void linklist_print()
    {
        tnode_char *temp;
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
void t_scan(tclinklist_char &obj)
{
    obj.linklist_scan();
}
tnode_char *clinklist_insert(tnode_char *head, tnode_char &obj)
{
    if (head == NULL)
    {
        tnode_char *newNode = new tnode_char(obj);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_char *newNode = new tnode_char(obj);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_char *clinklist_insert(tnode_char *head, Degree degree, char value, Degree value_degree)
{
    if (head == NULL)
    {
        tnode_char *newNode = new tnode_char(degree, value, value_degree);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_char *newNode = new tnode_char(degree, value, value_degree);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_char *clinklist_delete(tnode_char *head, int i)
{
    if (i == 0)
    {
        tnode_char *temp = head->next;
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
void t_print(tclinklist_char &obj)
{
    obj.linklist_print();
}