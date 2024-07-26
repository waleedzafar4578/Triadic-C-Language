#include "../Array/tarray_int.h"
void t_insertion_sort1(tarray_int obj)
{
    for(int i = 1; i < obj.get_size(); i++)
    {
        int key = obj.get_pointer_value(i);
        int j = obj.get_pointer_value(i-1);
        while(key > obj.get_pointer_value(j) && j >=0)
        {
            int k = j+1;
            obj.set_pointer_value(k , obj.get_pointer_value(j));
            obj.set_pointer_value_degree(k , obj.get_pointer_value_degree(j));
            --j;
        }
        int k = j+1;
        obj.set_pointer_value(k , key);
    }
}