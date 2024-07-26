#include "../Array/tarray_int.h"
#include <utility>
bool linear_Checking_2(tarray_int &obj)
{
    for (int i = 0; i < obj.get_size() - 1; i++)
    {
        if (obj.get_pointer_value_degree(i) == T && obj.get_pointer_value_degree(i + 1) == L)
        {
            return false;
        }
        else if (obj.get_pointer_value_degree(i) == F && obj.get_pointer_value_degree(i + 1) == L)
        {
            return false;
        }
        else if (obj.get_pointer_value_degree(i) == F && obj.get_pointer_value_degree(i + 1) == T)
        {
            return false;
        }
    }
    return true;
}
void t_linearsearch_int_2(tarray_int &obj, Degree D, int &startingIndex, int &endingIndex)
{
    bool check = linear_Checking_2(obj);
    if (check)
    {
        if (D == L)
        {
            if (obj.get_pointer_value_degree(0) != D)
            {
                startingIndex = -1;
                endingIndex = -1;
                return;
            }

            int startingPoint = 0;
            int endingPoint = 0;
            for (int i = 0; i < obj.get_size(); i++)
            {
                if (obj.get_pointer_value_degree(i) == D)
                {
                    endingPoint = i;
                }
                else
                    break;
            }
            // if (startingPoint > endingPoint)
            // {
            //     startingPoint = -1;
            //     endingPoint = -1;
            // }
            return;
        }
        else if (D == F)
        {
            int end = obj.get_size();
            if (obj.get_pointer_value_degree(end - 1) != D)
            {
                startingIndex = -1;
                endingIndex = -1;
                return;
            }
            int startingPoint = 0;
            int endingPoint = end - 1;
            for (int i = obj.get_size() - 1; i >= 0; i--)
            {
                if (obj.get_pointer_value_degree(i) == D)
                {
                    startingPoint = i;
                }
                else
                {
                    break;
                }
            }
            return;
        }
        else
        {
            int startingPoint = -1;
            int endingPoint = -1;
            for (int i = 0; i < obj.get_size(); i++)
            {
                if (obj.get_pointer_value_degree(i) == D)
                {
                    startingPoint = i;
                    break;
                }
            }
            if (startingPoint == -1)
            {
                startingIndex = -1;
                endingIndex = -1;
                return;
            }
            else
            {
                for (int i = startingPoint; i < obj.get_size(); i++)
                {
                    if (obj.get_pointer_value_degree(i) == D)
                    {
                        endingPoint = i;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            return;
        }
    }
    else
    {
        cout << "Data Is Not Sorted" << endl;
        startingIndex = -1;
        endingIndex = -1;
        return;
    }
}