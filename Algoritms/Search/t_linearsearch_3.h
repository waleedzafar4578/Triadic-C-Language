#include "t_linearsearch_2.h"
#include "t_linearsearch.h"
int t_linearsearch_int_3(tarray_int &obj, t_int value)
{
    bool check2 = linear_Checking_2(obj);
    if (check2)
    {
        int startingPoint = -1;
        int endingPoint = -1;
        t_linearsearch_int_2(obj, value.get_Degree() , startingPoint , endingPoint);
        bool check1 = linear_Checking(obj, startingPoint, endingPoint);
        if (check1)
        {
            for (int i = 0; i < obj.get_size(); i++)
            {
                if (obj.get_pointer_value(i) == value.get_value())
                    return i;
            }
            return -1;
        }
        else
        {
            cout << "Data Is Not Sorted Valuie Wise" << endl;
            return -2;
        }
    }
    else
    {
        cout << "Data Is Not Sorted Degree Wise" << endl;
        return -3;
    }
}