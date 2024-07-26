#include "Triadic.h"
#include <fstream>
int operater_menu();
//---------------------------------
const int sz = 2;
ofstream cyper_file("dtt.txt");
t_char shift(3, L);
t_char given_data[sz];
t_char temp('a', T);

//----------------------------------------
bool encoder()
{
    t_char _data[sz];
    // cout << "String:";
    // for (int i = 0; i < 5; i++)
    //{
    //   t_scan(given_data[i]);
    //}
    //-----here taking operator intput

    switch (operater_menu())
    {
    case 1:
        //------------------
        for (int i = 0; i < sz; i++)
        {
            temp = tplus_1(given_data[i], shift);
            _data[i] = tplus_1(given_data[i] , shift);
            if (temp.get_Degree() == T)
            {
                if (temp.get_value() > 'z')
                {
                    int cnt = 0;
                    while (true)
                    {
                        cnt++;
                        temp.set_value(temp.get_value() - 1);
                        // t_print(temp);
                        if (temp.get_value() == 'z' || temp.get_value() == 'Z')
                        {
                            break;
                        }
                    }
                    if (temp.get_value() == 'z')
                    {
                        temp.set_value('a');
                    }
                    else if (temp.get_value() == 'Z')
                    {
                        temp.set_value('A');
                    }
                    cnt--;
                    for (int i = 0; i < cnt; i++)
                    {
                        temp.set_value(temp.get_value() + 1);
                    }
                }
                given_data[i] = temp;
            }
        }
        cyper_file << "Using Plus 1\n";
        //------------------
        break;
    case 2:
        //------------------
        for (int i = 0; i < sz; i++)
        {
            temp = tplus_2(given_data[i], shift);
            _data[i] = tplus_2(given_data[i] , shift);
            if (temp.get_Degree() == T)
            {
                if (temp.get_value() > 'z')
                {
                    int cnt = 0;
                    while (true)
                    {
                        cnt++;
                        temp.set_value(temp.get_value() - 1);
                        // t_print(temp);
                        if (temp.get_value() == 'z' || temp.get_value() == 'Z')
                        {
                            break;
                        }
                    }
                    if (temp.get_value() == 'z')
                    {
                        temp.set_value('a');
                    }
                    else if (temp.get_value() == 'Z')
                    {
                        temp.set_value('A');
                    }
                    cnt--;
                    for (int i = 0; i < cnt; i++)
                    {
                        temp.set_value(temp.get_value() + 1);
                    }
                }
                given_data[i] = temp;
            }
        }
        cyper_file << "Using Plus 2\n";
        break;
    case 3:
        //------------------
        for (int i = 0; i < sz; i++)
        {
            temp = tplus_3(given_data[i], shift);
            _data[i] = tplus_3(given_data[i] , shift);
            if (temp.get_Degree() == T)
            {
                if (temp.get_value() > 'z')
                {
                    int cnt = 0;
                    while (true)
                    {
                        cnt++;
                        temp.set_value(temp.get_value() - 1);
                        // t_print(temp);
                        if (temp.get_value() == 'z' || temp.get_value() == 'Z')
                        {
                            break;
                        }
                    }
                    if (temp.get_value() == 'z')
                    {
                        temp.set_value('a');
                    }
                    else if (temp.get_value() == 'Z')
                    {
                        temp.set_value('A');
                    }
                    cnt--;
                    for (int i = 0; i < cnt; i++)
                    {
                        temp.set_value(temp.get_value() + 1);
                    }
                }
                given_data[i].set_value(temp.get_value());
            }
        }
        cyper_file << "Using Plus 3\n";
        break;
    default:
        //------------------
        for (int i = 0; i < sz; i++)
        {
            temp = tplus(given_data[i], shift);
            _data[i] = tplus(given_data[i] , shift);
            if (temp.get_Degree() == T)
            {
                if (temp.get_value() > 'z')
                {
                    int cnt = 0;
                    while (true)
                    {
                        cnt++;
                        temp.set_value(temp.get_value() - 1);
                        // t_print(temp);
                        if (temp.get_value() == 'z' || temp.get_value() == 'Z')
                        {
                            break;
                        }
                    }
                    if (temp.get_value() == 'z')
                    {
                        temp.set_value('a');
                    }
                    else if (temp.get_value() == 'Z')
                    {
                        temp.set_value('A');
                    }
                    cnt--;
                    for (int i = 0; i < cnt; i++)
                    {
                        temp.set_value(temp.get_value() + 1);
                    }
                }
                given_data[i].set_value(temp.get_value());
            }
        }
        cyper_file << "Using Plus 4\n";
        break;
    }
    return true;
}
//-------------------------------------
bool decoder()
{
    t_char _data[sz];
    switch (operater_menu())
    {
    case 1:
        //------------------
        for (int i = 0; i < sz; i++)
        {
            temp = tsub_1(given_data[i], shift);
            _data[i] = tsub_1(given_data[i] , shift);
            if (temp.get_Degree() == T)
            {
                if (temp.get_value() < 'a')
                {
                    int cnt = 0;
                    while (true)
                    {
                        cnt++;
                        temp.set_value(temp.get_value() + 1);
                        // t_print(temp);
                        if (temp.get_value() == 'a')
                        {
                            break;
                        }
                    }
                    if (temp.get_value() == 'a')
                    {
                        temp.set_value('z');
                    }
                    cnt--;
                    for (int i = 0; i < cnt; i++)
                    {
                        temp.set_value(temp.get_value() - 1);
                    }
                }
                given_data[i] = temp;
            }
        }
        cyper_file << "Using Sub 1\n";
        //------------------
        break;
    case 2:
        //------------------
        for (int i = 0; i < sz; i++)
        {
            temp = tsub_2(given_data[i], shift);
            _data[i] = tsub_2(given_data[i] , shift);
            if (temp.get_Degree() == T)
            {
                if (temp.get_value() < 'a')
                {
                    int cnt = 0;
                    while (true)
                    {
                        cnt++;
                        temp.set_value(temp.get_value() + 1);
                        // t_print(temp);
                        if (temp.get_value() == 'a')
                        {
                            break;
                        }
                    }
                    if (temp.get_value() == 'a')
                    {
                        temp.set_value('z');
                    }
                    cnt--;
                    for (int i = 0; i < cnt; i++)
                    {
                        temp.set_value(temp.get_value() - 1);
                    }
                }
                given_data[i] = temp;
            }
        }
        cyper_file << "Using Sub 2\n";
        //------------------
        break;
    case 3:
        //------------------
        for (int i = 0; i < sz; i++)
        {
            temp = tsub_3(given_data[i], shift);
            _data[i] = tsub_3(given_data[i] , shift);
            if (temp.get_Degree() == T)
            {
                if (temp.get_value() < 'a')
                {
                    int cnt = 0;
                    while (true)
                    {
                        cnt++;
                        temp.set_value(temp.get_value() + 1);
                        // t_print(temp);
                        if (temp.get_value() == 'a')
                        {
                            break;
                        }
                    }
                    if (temp.get_value() == 'a')
                    {
                        temp.set_value('z');
                    }
                    cnt--;
                    for (int i = 0; i < cnt; i++)
                    {
                        temp.set_value(temp.get_value() - 1);
                    }
                }
                given_data[i].set_value(temp.get_value());
            }
        }
        cyper_file << "Using Sub 3\n";
        //------------------
        break;
    default:
    //------------------
        for (int i = 0; i < sz; i++)
        {
            temp = tsub(given_data[i], shift);
            _data[i] = tsub(given_data[i] , shift);
            if (temp.get_Degree() == T)
            {
                if (temp.get_value() < 'a')
                {
                    int cnt = 0;
                    while (true)
                    {
                        cnt++;
                        temp.set_value(temp.get_value() + 1);
                        // t_print(temp);
                        if (temp.get_value() == 'a')
                        {
                            break;
                        }
                    }
                    if (temp.get_value() == 'a')
                    {
                        temp.set_value('z');
                    }
                    cnt--;
                    for (int i = 0; i < cnt; i++)
                    {
                        temp.set_value(temp.get_value() - 1);
                    }
                }
                given_data[i].set_value(temp.get_value());
            }
        }
        cyper_file << "Using Sub 4\n";
        //------------------
        break;
    }
    return true;
}
//--------------------------------------
int main()
{
    given_data[0].set_value('h');
    given_data[0].set_Degree(T);

    given_data[1].set_value('e');
    given_data[1].set_Degree(T);

    

    cyper_file << "String\n";
    for (int i = 0; i < sz; i++)
    {
        t_printfile(cyper_file, given_data[i]);
    }

    for (int i = 0; i < 2; i++)
    {
        char ct;
        cout << "Press E for encoder.\n";
        cout << "Press D for decoder.\n";
        cin >> ct;
        if (ct == 'E' || ct == 'e')
        {
            encoder();
            cyper_file << "After encode:\n";
            for (int i = 0; i < sz; i++)
            {
                t_printfile(cyper_file, given_data[i]);
            }
        }
        else if (ct == 'D' || ct == 'd')
        {
            decoder();
            cyper_file << "After decode:\n";
            for (int i = 0; i < sz; i++)
            {
                t_printfile(cyper_file, given_data[i]);
            }
        }
        else
        {
            cout << "Wrong Input." << endl;
        }
    }
}
int operater_menu()
{
    cout << "Press 1 for operater 1\nPress 2 for operater 2\nPress 3 for operater 3\nPress 4 for operater 4\n";
    int val;
    cin >> val;
    return val;
}