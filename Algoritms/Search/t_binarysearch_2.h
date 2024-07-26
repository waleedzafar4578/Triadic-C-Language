#include "../Array/tarray_int.h"
#include <utility>
bool Checking_2(tarray_int &obj)
{
    bool check = true;
    int end = obj.get_size();
    int start = 0;
    if ((obj.get_pointer_value_degree(start) == T) && (obj.get_pointer_value_degree(end) == L))
    {
        check = false;
        return check;
    }
    else if ((obj.get_pointer_value_degree(start) == F) && (obj.get_pointer_value_degree(end) == L))
    {
        check = false;
        return check;
    }
    else if ((obj.get_pointer_value_degree(start) == F) && (obj.get_pointer_value_degree(end) == T))
    {
        check = false;
        return check;
    }
    else
    {
        return check;
    }
}
void t_binarysearch_int_2(tarray_int &obj, Degree D, int &startingIndex, int &endingIndex)
{
    bool check = Checking_2(obj);
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
            int startingIndex = 0;
            int endingIndex = 0;
            int i = 0;
            int end = obj.get_size();
            while (i <= end)
            {
                int mid = i + (end - i) / 2;
                if (D != obj.get_pointer_value_degree(mid))
                {
                    end = mid - 1;
                }
                else
                {
                    if (obj.get_pointer_value_degree(mid + 1) != D)
                    {
                        end = mid;
                        break;
                    }
                    else
                    {
                        i = mid + 1;
                    }
                }
            }
            endingIndex = end;
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
            int startingIndex = 0;
            int endingIndex = (obj.get_size()) - 1;
            int i = 0;

            while (i <= end)
            {
                int mid = i + (end - i) / 2;
                if (D != obj.get_pointer_value_degree(mid))
                {
                    i = mid + 1;
                }
                else
                {
                    if (obj.get_pointer_value_degree(mid - 1) != D)
                    {
                        i = mid;
                        break;
                    }
                    else
                    {
                        end = mid - 1;
                    }
                }
            }
            startingIndex = i;
            return;
        }
        else
        {
            int startingIndex = 0;
            int endingIndex = 0;
            int i = 0;
            int end = obj.get_size();
            while (i <= end)
            {
                int mid = i + (end - i) / 2;
                if (D != obj.get_pointer_value_degree(mid))
                {
                    end = mid - 1;
                }
                else
                {
                    if (obj.get_pointer_value_degree(mid + 1) != D)
                    {
                        end = mid;
                        break;
                    }
                    else
                    {
                        i = mid + 1;
                    }
                }
            }
            endingIndex = end;
            i = 0;
            end = obj.get_size();
            while (i <= end)
            {
                int mid = i + (end - i) / 2;
                if (D != obj.get_pointer_value_degree(mid))
                {
                    i = mid + 1;
                }
                else
                {
                    if (obj.get_pointer_value_degree(mid - 1) != D)
                    {
                        i = mid;
                        break;
                    }
                    else
                    {
                        end = mid - 1;
                    }
                }
            }
            startingIndex = i;
            if (startingIndex > endingIndex)
            {
                startingIndex = -1;
                endingIndex = -1;
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