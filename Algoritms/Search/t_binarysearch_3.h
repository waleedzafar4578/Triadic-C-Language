#include "t_binarysearch.h"
#include "t_binarysearch_2.h"

bool Checking_p(tarray_int &obj, int _start, int _end)
{
    bool flag = true;
    int start = _start;
    int end = _end;
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
int t_binarysearch_int_3(tarray_int &obj, t_int value)
{
    bool check2 = Checking_2(obj);
    if (check2)
    {
        int startingPoint = -1;
        int endingPoint = -1;
        t_binarysearch_int_2(obj, value.get_Degree() , startingPoint , endingPoint);
        bool check1 = Checking_p(obj, startingPoint, endingPoint);
        if (check1)
        {
            int start = startingPoint;
            int end = endingPoint;
            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                if (obj.get_pointer_value(mid) == value.get_value())
                {
                    return mid;
                }
                else if (obj.get_pointer_value(mid) < value.get_value())
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
            cout << "Data Is Not Sorted Value Wise" << endl;
            return -2;
        }
    }
    else
    {
        cout << "Data Is Not Sorted Degree Wise" << endl;
        return -3;
    }
}