#include "../Array/tarray_int.h"
void t_insertionsort_int3(tarray_int &obj)
{
    int size = obj.get_size();
    for (int i = 0; i < size; i++)
    {
        if (obj.g_indexD(i) == T)
        {
            int j = i - 1;
            while (j >= 0)
            {
                if (obj.g_indexD(j) == T)
                {
                    int k = j + 1;
                    if (obj.g_indexD(k) == T)
                    {

                        if (obj.get_pointer_value_degree(k) == L && obj.get_pointer_value_degree(j) == T)
                        {
                            int temp = obj.get_pointer_value(k);
                            Degree D = obj.get_pointer_value_degree(k);
                            obj.set_pointer_value(k, obj.get_pointer_value(j));
                            obj.set_pointer_value_degree(k, obj.get_pointer_value_degree(j));
                            obj.set_pointer_value(j, temp);
                            obj.set_pointer_value_degree(j, D);
                        }
                        else if (obj.get_pointer_value_degree(k) == L && obj.get_pointer_value_degree(j) == F)
                        {
                            int temp = obj.get_pointer_value(k);
                            Degree D = obj.get_pointer_value_degree(k);
                            obj.set_pointer_value(k, obj.get_pointer_value(j));
                            obj.set_pointer_value_degree(k, obj.get_pointer_value_degree(j));
                            obj.set_pointer_value(j, temp);
                            obj.set_pointer_value_degree(j, D);
                        }
                        else if (obj.get_pointer_value_degree(k) == T && obj.get_pointer_value_degree(j) == F)
                        {
                            int temp = obj.get_pointer_value(k);
                            Degree D = obj.get_pointer_value_degree(k);
                            obj.set_pointer_value(k, obj.get_pointer_value(j));
                            obj.set_pointer_value_degree(k, obj.get_pointer_value_degree(j));
                            obj.set_pointer_value(j, temp);
                            obj.set_pointer_value_degree(j, D);
                        }
                    }
                    else
                    {
                        k++;
                        if (k >= size)
                        {
                            break;
                        }
                    }
                }

                j--;
            }
        }
        
    }

    for (int i = 1; i < size; i++)
    {
        if (obj.g_indexD(i) == T)
        {
            int key = obj.get_pointer_value(i);
            Degree D = obj.get_pointer_value_degree(i);
            int j;
            for (j = i - 1; j >= 0; j--)
            {
                if (obj.g_indexD(j) == T)
                {
                    if (obj.get_pointer_value_degree(j) == obj.get_pointer_value_degree(i))
                    {
                        if (obj.get_pointer_value(j) > key)
                        {
                            int k = j + 1;
                            obj.set_pointer_value(k, obj.get_pointer_value(j));
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
            int k = j + 1;
            if (obj.get_pointer_value_degree(k) == D)
            {
                obj.set_pointer_value(k, key);
            }
        }
    }
}