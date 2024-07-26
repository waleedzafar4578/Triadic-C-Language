#include <random>
#include "Triadic.h"
#include <time.h>
t_char *fillTrueKey(t_char *trueKey)
{
    
    trueKey = new t_char[26];
    for (int i = 0; i < 26; i++)
    {
        int value = rand() % 26 + 65;
        trueKey[i].set_Degree(T);
        trueKey[i].set_value(value);
        int j;
        for (j = 0; j < i; j++)
        {
            if (trueKey[i].get_value() == trueKey[j].get_value())
                break;
        }
        if (i != j)
            i--;
    }
    return trueKey;
}
t_char *fillFalseKey(t_char *trueKey)
{
    
    trueKey = new t_char[26];
    for (int i = 0; i < 26; i++)
    {
        int value = rand() % 26 + 65;
        trueKey[i].set_Degree(F);
        trueKey[i].set_value(value);
        int j;
        for (j = 0; j < i; j++)
        {
            if (trueKey[i].get_value() == trueKey[j].get_value())
                break;
        }
        if (i != j)
            i--;
    }
    return trueKey;
}
t_char encodeTrue(t_char val, t_char *trueKey)
{
    int index = val.get_value();
    index = index % 65;
    t_char returning = trueKey[index];
    return returning;
}

t_char encodeFalse(t_char val, t_char *falseKey)
{
    int index = val.get_value();
    index = index % 65;
    t_char returning = falseKey[index];
    return returning;
}
t_char decodeTrue(t_char val, t_char *trueKey)
{
    int i;
    bool found = false;
    for (i = 0; i < 26; i++)
    {
        if (val.get_value() == trueKey[i].get_value())
        {
            found = true;
            break;
        }
    }
    if (found == true)
    {
        int index = i + 65;
        t_char returning(index, T);
        return returning;
    }
    else
    {
        cout << "Value is not present in key" << endl;
        t_char returning(0, L);
        return returning;
    }
}

t_char decodeFalse(t_char val, t_char *falseKey)
{
    int i;
    bool found = false;
    for (i = 0; i < 26; i++)
    {
        if (val.get_value() == falseKey[i].get_value())
        {
            found = true;
            break;
        }
    }
    if (found == true)
    {
        int index = i + 65;
        t_char returning(index, F);
        return returning;
    }
    else
    {
        cout << "Value is not present in key" << endl;
        t_char returning(0, F);
        return returning;
    }
}
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    t_char *trueKeys;
    trueKeys = fillTrueKey(trueKeys);
    t_char *falseKeys;
    falseKeys = fillFalseKey(falseKeys);
    t_char* plainText = new t_char[2];
    cout<<"True Key"<<endl;
    for(int i = 0; i< 26; i++)
    {
        t_print(trueKeys[i]);
    }
    cout<<"False Key"<<endl;
    for(int i = 0; i< 26; i++)
    {
        t_print(falseKeys[i]);
    }
    plainText[0].set_value('H');
    plainText[0].set_Degree(T);
    plainText[1].set_value('E');
    plainText[1].set_Degree(T);
    cout<<"Plain Text"<<endl;
    for(int i = 0; i < 2; i++)
    {
        t_print(plainText[i]);
    }
    t_char* cipherText = new t_char[5];
    for(int i = 0; i < 5; i++)
    {
        if(plainText[i].get_Degree() == T)
        {
            cipherText[i] = encodeTrue(plainText[i] , trueKeys);
        }
        else if(plainText[i].get_Degree() == F)
        {
            cipherText[i] = encodeFalse(plainText[i] , falseKeys);
        }
    }
    cout<<"Cipher Text"<<endl;
    for(int i = 0; i < 5; i++)
    {
        t_print(cipherText[i]);
    }
    t_char* decodedText = new t_char[5];
    for(int i = 0; i< 5; i++)
    {
        if(cipherText[i].get_Degree() == T)
        {
            decodedText[i] = decodeTrue(cipherText[i] , trueKeys);
        }
        else if(plainText[i].get_Degree() == F)
        {
            decodedText[i] = decodeFalse(cipherText[i] , falseKeys);
        }
    }
    cout<<"Decoded Text"<<endl;
    for(int i = 0; i < 2; i++)
    {
        t_print(decodedText[i]);
    }
    return 0;
}