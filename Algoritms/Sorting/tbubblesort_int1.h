#include "../Array/tarray_int.h"
void t_bubblesort_int1(tarray_int &obj)
{
    int n = obj.get_size();
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n - i - 1; ++j)
        {
            if(obj.get_pointer_value(j) > obj.get_pointer_value(j + 1))
            {
                int k = j+1;
                int temp = obj.get_pointer_value(j);
                Degree D = obj.get_pointer_value_degree(j);
                obj.set_pointer_value(j , obj.get_pointer_value(k));
                obj.set_pointer_value_degree(j , obj.get_pointer_value_degree(k));
                obj.set_pointer_value(k , temp);
                obj.set_pointer_value_degree(k , D);
            }
        }
    }
}