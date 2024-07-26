#include "tdnode_lint.h"
tdnode_lint *dlinklist_insert(tdnode_lint *head, tdnode_lint &obj);
tdnode_lint *dlinklist_delete(tdnode_lint *head, int i);
tdnode_lint *dlinklist_insert(tdnode_lint *head, Degree degree, long int value, Degree value_degree);
class tdlinklist_lint
{
    tdnode_lint *head = NULL;

public:
    void insert_node(tdnode_lint &obj)
    {
        head = dlinklist_insert(head, obj);
    }
    void insert_node(Degree degree, long int value, Degree value_degree)
    {
        head = dlinklist_insert(head, degree, value, value_degree);
    }
    void linklist_print()
    {
        tdnode_lint *temp = head;
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
        tdnode_lint input;
        t_scan(input);
        head = dlinklist_insert(head, input);
    }
};
void t_scan(tdlinklist_lint &obj)
{
    obj.linklist_scan();
}
tdnode_lint *dlinklist_insert(tdnode_lint *head, tdnode_lint &obj)
{
    tdnode_lint *newNode = new tdnode_lint(obj);
    newNode->next = NULL;
    tdnode_lint *temp = head;
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
tdnode_lint *dlinklist_insert(tdnode_lint *head, Degree degree, long int value, Degree value_degree)
{
    tdnode_lint *newNode = new tdnode_lint(degree, value, value_degree);
    newNode->next = NULL;
    tdnode_lint *temp = head;
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
tdnode_lint *dlinklist_delete(tdnode_lint *head, int i)
{
    if (head == NULL)
    {
        cout << "Link List Is Empty" << endl;
        return head;
    }
    if (i == 0)
    {
        tdnode_lint *temp = head->next;
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
void t_print(tdlinklist_lint &obj)
{
    obj.linklist_print();
}