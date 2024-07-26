#include "Triadic.h"
#include <fstream>
int operater_menu();
//---------------------------------
const int sz = 18;
ofstream cyper_file("dtt.txt");
t_char shift(3, L);
t_char shiftDe(3,L);
t_char given_data[sz];
t_char temp('a', T);

//----------------------------------------
bool encoder()
{

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
            temp = tand_1(given_data[i], shift);
            if (temp.get_Degree() == T)
            {
                given_data[i].set_value(given_data[i].get_value()+3);
            }
            else if (temp.get_Degree() == F)
            {
                given_data[i].set_value(given_data[i].get_value()-3);
            }
            else
            {
                given_data[i].set_value(given_data[i].get_value()+(2 * 3));
            }
        }
        cyper_file << "Using Plus 1\n";
        //------------------
        break;
    case 2:
        //------------------
        //------------------
        for (int i = 0; i < sz; i++)
        {
            temp = tand_2(given_data[i], shift);
            if (temp.get_Degree() == T)
            {
                given_data[i].set_value(given_data[i].get_value()+2);
            }
            else if (temp.get_Degree() == F)
            {
                given_data[i].set_value(given_data[i].get_value()-3);
            }
            else
            {
                given_data[i].set_value(given_data[i].get_value()+(2 * 3));
            }
        }
        cyper_file << "Using Plus 2\n";
        break;
    case 3:
        //------------------
        //------------------
        for (int i = 0; i < sz; i++)
        {
            temp = tand_3(given_data[i], shift);
            if (temp.get_Degree() == T)
            {
                given_data[i].set_value(given_data[i].get_value()+3);
            }
            else if (temp.get_Degree() == F)
            {
                given_data[i].set_value(given_data[i].get_value()-3);
            }
            else
            {
                given_data[i].set_value(given_data[i].get_value()+(2 * 3));
            }
        }
        cyper_file << "Using Plus 3\n";
        break;
    default:
        //------------------
        //------------------
        for (int i = 0; i < sz; i++)
        {
            temp = tand(given_data[i], shift);
            if (temp.get_Degree() == T)
            {
                given_data[i].set_value(given_data[i].get_value()+3);
            }
            else if (temp.get_Degree() == F)
            {
                given_data[i].set_value(given_data[i].get_value()-3);
            }
            else
            {
                given_data[i].set_value(given_data[i].get_value()+(2 * 3));
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
    switch (operater_menu())
    {
    case 1:
        //------------------
        //------------------
        for (int i = 0; i < sz; i++)
        {
            temp = tand_1(given_data[i], shiftDe);
            if (temp.get_Degree() == T)
            {
                given_data[i].set_value(given_data[i].get_value()-3);
            }
            else if (temp.get_Degree() == F)
            {
                given_data[i].set_value(given_data[i].get_value()+3);
            }
            else
            {
                given_data[i].set_value(given_data[i].get_value()-(2 * 3));
            }
        }
        cyper_file << "Using Sub 1\n";
        //------------------
        break;
    case 2:
        //------------------
        for (int i = 0; i < sz; i++)
        {
            temp = tand_2(given_data[i], shiftDe);
            if (temp.get_Degree() == T)
            {
                given_data[i].set_value(given_data[i].get_value()-2);
            }
            else if (temp.get_Degree() == F)
            {
                given_data[i].set_value(given_data[i].get_value()+3);
            }
            else
            {
                given_data[i].set_value(given_data[i].get_value()-(2 * 3));
            }
        }
        cyper_file << "Using Sub 2\n";
        //------------------
        break;
    case 3:
        //------------------
        for (int i = 0; i < sz; i++)
        {
            temp = tand_3(given_data[i], shiftDe);
            if (temp.get_Degree() == T)
            {
                given_data[i].set_value(given_data[i].get_value()-3);
            }
            else if (temp.get_Degree() == F)
            {
                given_data[i].set_value(given_data[i].get_value()+3);
            }
            else
            {
                given_data[i].set_value(given_data[i].get_value()-(2 * 3));
            }
        }
        cyper_file << "Using Sub 3\n";
        //------------------
        break;
    default:
        //------------------
        for (int i = 0; i < sz; i++)
        {
            temp = tand(given_data[i], shiftDe);
            if (temp.get_Degree() == T)
            {
                given_data[i].set_value(given_data[i].get_value()-3);
            }
            else if (temp.get_Degree() == F)
            {
                given_data[i].set_value(given_data[i].get_value()+3);
            }
            else
            {
                given_data[i].set_value(given_data[i].get_value()-(2 * 3));
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
    given_data[0].set_value('H');
    given_data[0].set_Degree(T);

    given_data[1].set_value('E');
    given_data[1].set_Degree(T);

    given_data[2].set_value('H');
    given_data[2].set_Degree(T);

    given_data[3].set_value('E');
    given_data[3].set_Degree(L);

    given_data[4].set_value('H');
    given_data[4].set_Degree(T);

    given_data[5].set_value('E');
    given_data[5].set_Degree(F);

    given_data[6].set_value('H');
    given_data[6].set_Degree(L);

    given_data[7].set_value('E');
    given_data[7].set_Degree(T);

    given_data[8].set_value('H');
    given_data[8].set_Degree(L);

    given_data[9].set_value('E');
    given_data[9].set_Degree(L);

    given_data[10].set_value('H');
    given_data[10].set_Degree(L);

    given_data[11].set_value('E');
    given_data[11].set_Degree(F);

    given_data[12].set_value('H');
    given_data[12].set_Degree(F);

    given_data[13].set_value('E');
    given_data[13].set_Degree(T);

    given_data[14].set_value('H');
    given_data[14].set_Degree(F);

    given_data[15].set_value('E');
    given_data[15].set_Degree(L);

    given_data[16].set_value('H');
    given_data[16].set_Degree(F);

    given_data[17].set_value('E');
    given_data[17].set_Degree(F);

    cyper_file << "String\n";
    for (int i = 0; i < sz; i++)
    {
        t_printfile(cyper_file, given_data[i]);
    }

    for (int i = 0; i < 4; i++)
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