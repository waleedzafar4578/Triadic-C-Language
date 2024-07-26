#include "../Array/tarray_int.h"
bool linear_Checking(tarray_int &obj , int start , int end)
{
    bool check = true;
    //Checking For Assending Order
    for(int i = start; i < end -1; i++)
    {
        if(obj.get_pointer_value(i) > obj.get_pointer_value(i + 1))
        {
            check = false;
            break;
        }
    }
    return check;
}
bool linear_Checking(tarray_int &obj)
{
    bool check = true;
    //Checking For Assending Order
    for(int i = 0; i < obj.get_size() - 1; i++)
    {
        if(obj.get_pointer_value(i) > obj.get_pointer_value(i + 1))
        {
            check = false;
            break;
        }
    }
    return check;
}
int t_linearsearch_int(tarray_int &obj , int value)
{
    bool check = linear_Checking(obj);
    if(check)
    {
        for(int i = 0; i < obj.get_size(); i++)
        {
            if(obj.get_pointer_value(i) == value)
                return i;
        }
        return -1;
    }
    else
    {
        cout<<"Data Is Not Sorted"<<endl;
        return -2;
    }
}