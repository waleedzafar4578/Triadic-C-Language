#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class TableNode
{
public:
    string value;
    TableNode* next;
    TableNode* down;
    TableNode()
    {
        value = '\0';
        next = NULL;
        down = NULL;
    }
    TableNode(string val)
    {
        value = val;
        next = NULL;
        down = NULL;
    }
};