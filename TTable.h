#pragma once
#include "TableRow.h"
#include <vector>
#include <fstream>
//these are for c++ tables
class TTable
{

public:
    int numberOfColumns;
    int numberOfRecords;
    string tableName;
    TableRow Header;
    TTable()
    {
        numberOfColumns = 0;
        numberOfRecords = 0;
    }
    void defineColumns(vector<string> l)
    {
        for (auto i = l.begin(); i != l.end(); i++)
        {
            Header.insert(*i);
            numberOfColumns++;
        }
    }
    // void addColumn(string Col)
    // {
    //     Header.insert(Col);
    //     TableNode *temp = Header.head;
    //     while (temp->next != NULL)
    //     {
    //         temp = temp->next;
    //     }
    //     TableNode *temp2 = Header.head;
    //     while (temp2->next->value.compare(Col) != 0)
    //     {
    //         temp2 = temp2->next;
    //     }
    //     temp = temp->down;
    //     temp2 = temp2->down;
    //     for (int i = 1; i <= numberOfRecords; i++)
    //     {
    //         temp = new TableNode("NULL");
    //         temp2->next = temp;
    //         temp = temp->down;
    //         temp2 = temp2->down;
    //     }
    //     numberOfColumns++;
    // }
    void addColumn(string Col, vector<string> l = {"NULL"})
    {
        int difference = 0;
        if (l.size() < numberOfRecords)
        {
            difference = numberOfRecords - l.size();
        }
        Header.insert(Col);
        TableNode *temp = Header.head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        TableNode *temp2 = Header.head;
        while (temp2->next->value.compare(Col) != 0)
        {
            temp2 = temp2->next;
        }
        temp = temp->down;
        temp2 = temp2->down;
        for (int i = 1; i <= numberOfRecords; i++)
        {
            if (i + difference == numberOfRecords && difference > 0)
            {
                temp = new TableNode("NULL");
                temp2->next = temp;
                temp = temp->down;
                temp2 = temp2->down;
                difference--;
            }
            temp = new TableNode(l[i - 1]);
            temp2->next = temp;
            temp = temp->down;
            temp2 = temp2->down;
        }
        numberOfColumns++;
    }
    void addRow(vector<string> l)
    {
        TableNode *previous;
        TableRow temp;
        // while (temp != NULL)
        // {
        //     temp = temp->down;
        // }
        TableNode *temp2 = Header.head;

        while (temp2->down != NULL)
        {
            temp2 = temp2->down;
        }
        int b = 0;
        for (auto i = l.begin(); i != l.end() && b < numberOfColumns; i++, b++)
        {
            // temp = new TableNode(*i);
            // temp2->down = temp;
            // temp = temp->next;
            // temp2 = temp2->next;
            temp.insert(*i);
        }
        previous = temp.head;
        for (int i = 0; i < numberOfColumns; i++)
        {
            temp2->down = previous;
            previous = previous->next;
            temp2 = temp2->next;
        }
        numberOfRecords++;
    }
    void print()
    {
        TableNode *temp = Header.head;
        TableNode *temp2 = Header.head;
        if (temp == NULL)
        {
            cout << "Table is Empty" << endl;
            return;
        }
        for (int i = 0; i <= numberOfRecords; i++)
        {
            while (temp != NULL)
            {
                cout << temp->value << "\t";
                temp = temp->next;
            }
            cout << endl;
            temp2 = temp2->down;
            temp = temp2;
        }
    }
    void printOnFile(ofstream &dumFile, string fileName)
    {
        dumFile.open(fileName.c_str());
        if (dumFile.fail())
        {
            cout << "File Cannot Be Open" << endl;
            return;
        }
        else
        {
            dumFile << numberOfColumns << endl;
            dumFile << numberOfRecords << endl;
            TableNode *temp = Header.head;
            TableNode *temp2 = Header.head;
            if (temp == NULL)
            {
                cout << "Table is Empty" << endl;
                return;
            }
            for (int i = 0; i <= numberOfRecords; i++)
            {

                while (temp != NULL)
                {
                    dumFile << temp->value << "\t";
                    temp = temp->next;
                }
                dumFile << endl;
                temp2 = temp2->down;
                temp = temp2;
            }
        }
    }
    void readFromFile(ifstream &dumFile, string fileName)
    {
        int records = 0;
        int columns = 0;
        dumFile.open(fileName.c_str());
        if (dumFile.fail())
        {
            cout << "File Cannot Be Open" << endl;
            return;
        }
        else
        {
            while (dumFile)
            {
                char data;
                data = dumFile.get();
                if (data == '\n')
                {
                    records++;
                }
                else if (data == '\t')
                {
                    columns++;
                }
            }
            columns = columns / records;
        }
        TTable table;
        ifstream inFile;
        inFile.open(fileName.c_str());
        if (inFile.fail())
        {
            cout << "File Cannot Be Open" << endl;
            return;
        }
        else
        {
            vector<string> readData;
            readData.resize(columns);
            for (int i = 0; i < records; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    getline(inFile, readData[j], '\t');
                }
                if (i > 0)
                {
                    table.addRow(readData);
                }
                else if (i == 0)
                {
                    table.defineColumns(readData);
                }
            }
            table.print();
        }
    }
};