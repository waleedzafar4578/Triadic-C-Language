#include "../Array/tarray_int.h"
void t_selection_sort_int3(tarray_int &obj)
{
    // cout<<"Before sorting"<<endl;
    // t_print(obj);
    int size = obj.get_size();
    for (int i = 0; i < size; i++)
    {
        if (obj.g_indexD(i) == T)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (obj.g_indexD(j) == T)
                {
                    if (obj.get_pointer_value_degree(i) == T && obj.get_pointer_value_degree(j) == L)
                    {
                        int temp = obj.get_pointer_value(i);
                        Degree D = obj.get_pointer_value_degree(i);
                        obj.set_pointer_value(i, obj.get_pointer_value(j));
                        obj.set_pointer_value_degree(i, obj.get_pointer_value_degree(j));
                        obj.set_pointer_value(j, temp);
                        obj.set_pointer_value_degree(j, D);
                    }
                    else if (obj.get_pointer_value_degree(i) == F && obj.get_pointer_value_degree(j) == T)
                    {
                        int temp = obj.get_pointer_value(i);
                        Degree D = obj.get_pointer_value_degree(i);
                        obj.set_pointer_value(i, obj.get_pointer_value(j));
                        obj.set_pointer_value_degree(i, obj.get_pointer_value_degree(j));
                        obj.set_pointer_value(j, temp);
                        obj.set_pointer_value_degree(j, D);
                    }
                    else if (obj.get_pointer_value_degree(i) == F && obj.get_pointer_value_degree(j) == L)
                    {
                        int temp = obj.get_pointer_value(i);
                        Degree D = obj.get_pointer_value_degree(i);
                        obj.set_pointer_value(i, obj.get_pointer_value(j));
                        obj.set_pointer_value_degree(i, obj.get_pointer_value_degree(j));
                        obj.set_pointer_value(j, temp);
                        obj.set_pointer_value_degree(j, D);
                    }
                }
            }
        }
    }
    // cout<<"Degree Sorted"<<endl;
    // t_print(obj);
    int indexOfMinimumValue;
    for (int i = 0; i < size; i++)
    {

        if (obj.g_indexD(i) == T)
        {
            indexOfMinimumValue = i;
            Degree DegreeOfMinimumValue = obj.get_pointer_value_degree(i);
            for (int j = i + 1; j < obj.get_size(); j++)
            {
                if (obj.g_indexD(j) == T)
                {
                    if (obj.get_pointer_value_degree(j) == DegreeOfMinimumValue)
                    {
                        if (obj.get_pointer_value(j) < obj.get_pointer_value(indexOfMinimumValue))
                        {
                            indexOfMinimumValue = j;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (indexOfMinimumValue != i)
            {
                int temp = obj.get_pointer_value(indexOfMinimumValue);
                obj.set_pointer_value(indexOfMinimumValue, obj.get_pointer_value(i));
                obj.set_pointer_value(i, temp);
            }
        }
    }

    // cout<<"After sorting"<<endl;
    // t_print(obj);
}