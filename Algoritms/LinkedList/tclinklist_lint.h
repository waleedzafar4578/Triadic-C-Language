#include "tnode_lint.h"
tnode_lint *clinklist_insert(tnode_lint *head, tnode_lint &obj);
tnode_lint *clinklist_delete(tnode_lint *head, int i);
tnode_lint *clinklist_insert(tnode_lint *head, Degree degree, long int value, Degree value_degree);
class tclinklist_lint
{
    tnode_lint *head = NULL;

public:
    void insert_node(tnode_lint &obj)
    {
        head = clinklist_insert(head, obj);
    }
    void insert_node(Degree degree, long int value, Degree value_degree)
    {
        head = clinklist_insert(head, degree, value, value_degree);
    }
    void delete_node(int i)
    {
        head = clinklist_delete(head , i);
    }
     void linklist_scan()
    {
        tnode_lint input;
        t_scan(input);
        head = clinklist_insert(head, input);
    }
    void linklist_print()
    {
        tnode_lint *temp;
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
void t_scan(tclinklist_lint &obj)
{
    obj.linklist_scan();
}
tnode_lint *clinklist_insert(tnode_lint *head, tnode_lint &obj)
{
    if (head == NULL)
    {
        tnode_lint *newNode = new tnode_lint(obj);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_lint *newNode = new tnode_lint(obj);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_lint *clinklist_insert(tnode_lint *head, Degree degree, long int value, Degree value_degree)
{
    if (head == NULL)
    {
        tnode_lint *newNode = new tnode_lint(degree, value, value_degree);
        head = newNode;
        head->next = head;
        return head;
    }
    tnode_lint *newNode = new tnode_lint(degree, value, value_degree);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}
tnode_lint *clinklist_delete(tnode_lint *head, int i)
{
    if (i == 0)
    {
        tnode_lint *temp = head->next;
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
void t_print(tclinklist_lint &obj)
{
    obj.linklist_print();
}