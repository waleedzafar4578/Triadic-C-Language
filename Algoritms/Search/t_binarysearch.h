#include "../Array/tarray_int.h"
bool Checking(tarray_int &obj)
{
    bool flag = true;
    int start = 0;
    int end = obj.get_size();
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (obj.get_pointer_value(mid) >= obj.get_pointer_value(start) && obj.get_pointer_value(mid) <= obj.get_pointer_value(end))
        {
            end = mid - 1;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}
int t_binarysearch_int(tarray_int &obj, int value)
{
    bool check = Checking(obj);
    if (check)
    {
        int start = 0;
        int end = obj.get_size();
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (obj.get_pointer_value(mid) == value)
            {
                return mid;
            }
            else if (obj.get_pointer_value(mid) < value)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }
    else
    {
        cout<<"Data Is Not Sorted"<<endl;
        return -2;
    }
}