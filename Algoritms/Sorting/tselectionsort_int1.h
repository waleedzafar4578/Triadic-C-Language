#include "../Array/tarray_int.h"
void t_selection_sort1(tarray_int obj)
{
    for(int i = 0; i < obj.get_size(); i++)
    {
        int indexMin = i;
        for(int j = i + 1; j < obj.get_size(); j++)
        {
            if(obj.get_pointer_value(j) < obj.get_pointer_value(indexMin))
            {
                indexMin = j;
            }
        }
        int temp = obj.get_pointer_value(indexMin);
        Degree D = obj.get_pointer_value_degree(indexMin);
        obj.set_pointer_value(indexMin, obj.get_pointer_value(i));
        obj.set_pointer_value_degree(indexMin, obj.get_pointer_value_degree(i));
        obj.set_pointer_value(i , temp);
        obj.set_pointer_value_degree(i , D);
    }
}