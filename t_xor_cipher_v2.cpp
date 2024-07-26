#include "Triadic.h"
#include <fstream>
t_bool send_data[4];

void dg(t_bool obj, ofstream &cyper_file)
{
    if (obj.get_Degree() == T)
    {
        cyper_file << "T";
    }
    else if (obj.get_Degree() == F)
    {
        cyper_file << "F";
    }
    else
    {
        cyper_file << "L";
    }
}

void p_key_val(t_bool data[4], t_bool key[4], ofstream &cyper_file)
{
    cyper_file << "DATA:" << endl;
    cyper_file << "value:";
    cyper_file << data[0].get_value();
    cyper_file << data[1].get_value();
    cyper_file << data[2].get_value();
    cyper_file << data[3].get_value();
    cyper_file << endl
               << "Degree:";
    dg(data[0], cyper_file);
    dg(data[1], cyper_file);
    dg(data[2], cyper_file);
    dg(data[3], cyper_file);
    // write key on file
    cyper_file << endl
               << "KEY:" << endl;
    cyper_file << "value:";
    cyper_file << key[0].get_value();
    cyper_file << key[1].get_value();
    cyper_file << key[2].get_value();
    cyper_file << key[3].get_value();
    cyper_file << endl
               << "Degree:";
    dg(key[0], cyper_file);
    dg(key[1], cyper_file);
    dg(key[2], cyper_file);
    dg(key[3], cyper_file);
}
void p_val(t_bool data[4], ofstream &cyper_file)
{
    cyper_file << "DATA:" << endl;
    cyper_file << "value:";
    cyper_file << data[0].get_value();
    cyper_file << data[1].get_value();
    cyper_file << data[2].get_value();
    cyper_file << data[3].get_value();
    cyper_file << endl
               << "Degree:";
    dg(data[0], cyper_file);
    dg(data[1], cyper_file);
    dg(data[2], cyper_file);
    dg(data[3], cyper_file);
    // write key on file
}
void encode1(t_bool _data[4], t_bool key[4], ofstream &cyper_file)
{
    for (int i = 0; i < 4; i++)
    {
        t_bool ans = tand_1(_data[i], key[i]);
        if (ans.get_Degree() == T)
        {
            if (_data[i].get_value() == key[i].get_value())
            {
                send_data[i].set_value(0);
                send_data[i].set_Degree(_data[i].get_Degree());
            }
            else
            {
                send_data[i].set_value(1);
                send_data[i].set_Degree(_data[i].get_Degree());
            }
        }
    }
    cyper_file << "After Encode:" << endl;
    p_val(send_data, cyper_file);
}
void encode2(t_bool _data[4], t_bool key[4], ofstream &cyper_file)
{
    for (int i = 0; i < 4; i++)
    {
        t_bool ans = tand_2(_data[i], key[i]);
        if (ans.get_Degree() == T)
        {
            if (_data[i].get_value() == key[i].get_value())
            {
                send_data[i].set_value(0);
                send_data[i].set_Degree(_data[i].get_Degree());
            }
            else
            {
                send_data[i].set_value(1);
                send_data[i].set_Degree(_data[i].get_Degree());
            }
        }
    }
    cyper_file << "After Encode:" << endl;
    p_val(send_data, cyper_file);
}
void encode3(t_bool _data[4], t_bool key[4], ofstream &cyper_file)
{
    for (int i = 0; i < 4; i++)
    {
        t_bool ans = tand_3(_data[i], key[i]);
        if (ans.get_Degree() == T)
        {
            if (_data[i].get_value() == key[i].get_value())
            {
                send_data[i].set_value(0);
                send_data[i].set_Degree(_data[i].get_Degree());
            }
            else
            {
                send_data[i].set_value(1);
                send_data[i].set_Degree(_data[i].get_Degree());
            }
        }
    }
    cyper_file << "After Encode:" << endl;
    p_val(send_data, cyper_file);
}
void encode4(t_bool _data[4], t_bool key[4], ofstream &cyper_file)
{
    for (int i = 0; i < 4; i++)
    {
        t_bool ans = tand(_data[i], key[i]);
        if (ans.get_Degree() == T)
        {
            if (_data[i].get_value() == key[i].get_value())
            {
                send_data[i].set_value(0);
                send_data[i].set_Degree(_data[i].get_Degree());
            }
            else
            {
                send_data[i].set_value(1);
                send_data[i].set_Degree(_data[i].get_Degree());
            }
        }
    }
    cyper_file << "After Encode:" << endl;
    p_val(send_data, cyper_file);
}
void decode1(t_bool data[4], t_bool key[4], ofstream &cyper_file)
{
    for (int i = 0; i < 4; i++)
    {
        t_bool ans = tand_1(send_data[i], key[i]);
        if (ans.get_Degree() == T)
        {
            if (send_data[i].get_value() == key[i].get_value())
            {
                data[i].set_value(0);
                data[i].set_Degree(send_data[i].get_Degree());
            }
            else
            {
                data[i].set_value(1);
                data[i].set_Degree(send_data[i].get_Degree());
            }
        }
    }
    cyper_file<<"After Decode:"<<endl;
    p_val(data,cyper_file);
}
void decode2(t_bool data[4], t_bool key[4], ofstream &cyper_file)
{
    for (int i = 0; i < 4; i++)
    {
        t_bool ans = tand_2(send_data[i], key[i]);
        if (ans.get_Degree() == T)
        {
            if (send_data[i].get_value() == key[i].get_value())
            {
                data[i].set_value(0);
                data[i].set_Degree(send_data[i].get_Degree());
            }
            else
            {
                data[i].set_value(1);
                data[i].set_Degree(send_data[i].get_Degree());
            }
        }
    }
    cyper_file<<"After Decode:"<<endl;
    p_val(data,cyper_file);
}
void decode3(t_bool data[4], t_bool key[4], ofstream &cyper_file)
{
    for (int i = 0; i < 4; i++)
    {
        t_bool ans = tand_3(send_data[i], key[i]);
        if (ans.get_Degree() == T)
        {
            if (send_data[i].get_value() == key[i].get_value())
            {
                data[i].set_value(0);
                data[i].set_Degree(send_data[i].get_Degree());
            }
            else
            {
                data[i].set_value(1);
                data[i].set_Degree(send_data[i].get_Degree());
            }
        }
    }
    cyper_file<<"After Decode:"<<endl;
    p_val(data,cyper_file);
}
void decode4(t_bool data[4], t_bool key[4], ofstream &cyper_file)
{
    for (int i = 0; i < 4; i++)
    {
        t_bool ans = tand(send_data[i], key[i]);
        if (ans.get_Degree() == T)
        {
            if (send_data[i].get_value() == key[i].get_value())
            {
                data[i].set_value(0);
                data[i].set_Degree(send_data[i].get_Degree());
            }
            else
            {
                data[i].set_value(1);
                data[i].set_Degree(send_data[i].get_Degree());
            }
        }
    }
    cyper_file<<"After Decode:"<<endl;
    p_val(data,cyper_file);
}
int main()
{
    ofstream cyper_file("da_xor.txt");
    t_bool data[4];
    t_bool key[4];
    // data
    data[0].set_value(0);
    data[0].set_Degree(T);

    data[1].set_value(0);
    data[1].set_Degree(L);

    data[2].set_value(1);
    data[2].set_Degree(F);

    data[3].set_value(1);
    data[3].set_Degree(T);

    // key
    key[0].set_value(1);
    key[0].set_Degree(T);

    key[1].set_value(0);
    key[1].set_Degree(T);

    key[2].set_value(0);
    key[2].set_Degree(L);

    key[3].set_value(1);
    key[3].set_Degree(L);

    cyper_file << "Version 2" << endl;
    p_key_val(data, key, cyper_file);

     cyper_file << endl
               << "Encoding with e1...." << endl;
    encode1(data,key,cyper_file);
    cyper_file << endl
               << "Decoding with d1...." << endl;
    decode1(data,key,cyper_file);

     cyper_file << endl
               << "Encoding with e1...." << endl;
    encode1(data,key,cyper_file);
    cyper_file << endl
               << "Decoding with d2...." << endl;
    decode2(data,key,cyper_file);
     cyper_file << endl
               << "Encoding with e1...." << endl;
    encode1(data,key,cyper_file);
    cyper_file << endl
               << "Decoding with d3...." << endl;
    decode3(data,key,cyper_file);
     cyper_file << endl
               << "Encoding with e1...." << endl;
    encode1(data,key,cyper_file);
    cyper_file << endl
               << "Decoding with d4...." << endl;
    decode4(data,key,cyper_file);
     cyper_file << endl
               << "Encoding with e2...." << endl;
    encode2(data,key,cyper_file);
    cyper_file << endl
               << "Decoding with d1...." << endl;
    decode1(data,key,cyper_file);
     cyper_file << endl
               << "Encoding with e2...." << endl;
    encode2(data,key,cyper_file);
    cyper_file << endl
               << "Decoding with d2...." << endl;
    decode2(data,key,cyper_file);
     cyper_file << endl
               << "Encoding with e2...." << endl;
    encode2(data,key,cyper_file);
    cyper_file << endl
               << "Decoding with d3...." << endl;
    decode3(data,key,cyper_file);
     cyper_file << endl
               << "Encoding with e2...." << endl;
    encode2(data,key,cyper_file);
    cyper_file << endl
               << "Decoding with d4...." << endl;
    decode4(data,key,cyper_file);
     cyper_file << endl
               << "Encoding with e3...." << endl;
    encode3(data,key,cyper_file);
    cyper_file << endl
               << "Decoding with d1...." << endl;
    decode1(data,key,cyper_file);
     cyper_file << endl
               << "Encoding with e3...." << endl;
    encode3(data,key,cyper_file);
    cyper_file << endl
               << "Decoding with d2...." << endl;
    decode2(data,key,cyper_file);
     cyper_file << endl
               << "Encoding with e3...." << endl;
    encode3(data,key,cyper_file);
    cyper_file << endl
               << "Decoding with d3...." << endl;
    decode3(data,key,cyper_file);
     cyper_file << endl
               << "Encoding with e3...." << endl;
    encode3(data,key,cyper_file);
    cyper_file << endl
               << "Decoding with d4...." << endl;
    decode4(data,key,cyper_file);
     cyper_file << endl
               << "Encoding with e4...." << endl;
    encode4(data,key,cyper_file);
    cyper_file << endl
               << "Decoding with d1...." << endl;
    decode1(data,key,cyper_file);
     cyper_file << endl
               << "Encoding with e4...." << endl;
    encode4(data,key,cyper_file);
    cyper_file << endl
               << "Decoding with d2...." << endl;
    decode2(data,key,cyper_file);
     cyper_file << endl
               << "Encoding with e4...." << endl;
    encode4(data,key,cyper_file);
    cyper_file << endl
               << "Decoding with d3...." << endl;
    decode3(data,key,cyper_file);
     cyper_file << endl
               << "Encoding with e4...." << endl;
    encode4(data,key,cyper_file);
    cyper_file << endl
               << "Decoding with d4...." << endl;
    decode4(data,key,cyper_file);
    return 0;
}