#pragma once
#include"TableNode.h"
class TableRow
{
    
public:
    TableNode* head;
    TableRow()
    {
        head = NULL;
    }
    void insert(string data)
    {
        TableNode* newNode = new TableNode(data);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        TableNode* temp = head;
        while(temp->next !=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void printRow()
    {
        TableNode* temp = head;
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        while(temp != NULL)
        {
            cout<<temp->value<<" ";
            temp = temp->next;
        }
    }
};