// This file enumerates (defines) three triadic truth-values: true (T), false (F), and limit (L). 


#ifndef t_enum_h		// file is defined once to avoid duplication of obj file. 
#define t_enum_h
#include <iostream>
#include <fstream>
using namespace std;
enum Degree
{
    T = 'T',
    F = 'F',
    L = 'L'
};

// Function to convert input Double into triadic degrees. 

Degree enum_convert(char t)
{
    switch (t)
    {
    case 'T':
    case 't':
        return T;
        break;
    case 'F':
    case 'f':
        return F;
        break;
    case 'L':
    case 'l':
        return L;
        break;
    default:
        return L;
    }
}

// Function to convert input Double into triadic degrees when the input is read from file. 

Degree enum_convert(int tm)
{
   const int t=T,f=F,l=L;
    switch (tm)
    {
    case t:
        return T;
        break;
    case f:
        return F;
        break;
    case l:
        return L;
        break;
    default:
        return L;
    }
}

// Function to scan (or read) input degree from console 

void t_scan(Degree &temp_input_Degree)
{
    char intput_Double_Degree;
    cout << "Degree:";
    cin >> intput_Double_Degree;
    temp_input_Degree = enum_convert(intput_Double_Degree); 	// convert input Double into triadic degree
}

// Function to print output degree via console

void t_print(Degree d)
{
    switch (d)
    {
    case T:
        cout << "True" << endl;
        break;
    case F:
        cout << "False" << endl;
        break;
    case L:
        cout << "Limit" << endl;
        break;
    }
}

#endif 			/* t_enum.h */