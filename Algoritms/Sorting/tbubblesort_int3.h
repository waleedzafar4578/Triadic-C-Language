#include "../Array/tarray_int.h"
void t_bubblesort_int3(tarray_int &obj)
{
    int size = obj.get_size();
    for (int i = 0; i < size; i++)
    {
        int j = 0, k = 1;
    skip:
        for (; j < size && k < size; j++, k++)
        {
            if (obj.g_indexD(j) == T)
            {
            again:
                if (obj.g_indexD(k) == T)
                {
                    // here we confirm both index availability
                    switch (obj.get_pointer_value_degree(j))
                    {
                    case T:
                        if (obj.get_pointer_value_degree(k) == T)
                        {
                            int l = obj.get_pointer_value(j);
                            int r = obj.get_pointer_value(k);
                            if (l > r)
                            {
                                obj.set_pointer_value(j, r);
                                obj.set_pointer_value(k, l);
                            }
                        }
                        else if (obj.get_pointer_value_degree(k) == F)
                        {
                            // here we dont need to swap its position is right
                        }
                        else
                        {
                            int l = obj.get_pointer_value(j);
                            int r = obj.get_pointer_value(k);
                            Degree ld = obj.get_pointer_value_degree(j);
                            Degree rd = obj.get_pointer_value_degree(k);
                            obj.set_pointer_value(j, r);
                            obj.set_pointer_value(k, l);
                            obj.set_pointer_value_degree(j, rd);
                            obj.set_pointer_value_degree(k, ld);
                        }
                        break;
                    case L:
                        if (obj.get_pointer_value_degree(k) == T)
                        {
                            // here we dont need to swap its position is right
                        }
                        else if (obj.get_pointer_value_degree(k) == F)
                        {
                            // here we dont need to swap its position is right
                        }
                        else
                        {
                            int l = obj.get_pointer_value(j);
                            int r = obj.get_pointer_value(k);
                            if (l > r)
                            {
                                obj.set_pointer_value(j, r);
                                obj.set_pointer_value(k, l);
                            }
                        }

                        break;
                    default:
                        if (obj.get_pointer_value_degree(k) == T)
                        {
                            int l = obj.get_pointer_value(j);
                            int r = obj.get_pointer_value(k);
                            Degree ld = obj.get_pointer_value_degree(j);
                            Degree rd = obj.get_pointer_value_degree(k);
                            obj.set_pointer_value(j, r);
                            obj.set_pointer_value(k, l);
                            obj.set_pointer_value_degree(j, rd);
                            obj.set_pointer_value_degree(k, ld);
                        }
                        else if (obj.get_pointer_value_degree(k) == F)
                        {
                            int l = obj.get_pointer_value(j);
                            int r = obj.get_pointer_value(k);
                            if (l > r)
                            {
                                obj.set_pointer_value(j, r);
                                obj.set_pointer_value(k, l);
                            }
                        }
                        else
                        {
                            int l = obj.get_pointer_value(j);
                            int r = obj.get_pointer_value(k);
                            Degree ld = obj.get_pointer_value_degree(j);
                            Degree rd = obj.get_pointer_value_degree(k);
                            obj.set_pointer_value(j, r);
                            obj.set_pointer_value(k, l);
                            obj.set_pointer_value_degree(j, rd);
                            obj.set_pointer_value_degree(k, ld);
                        }
                        break;
                    }
                }
                else
                {
                    k++;
                    if (k >= size)
                        goto skip;
                    goto again;
                }
            }
            else
            {
                if (j != 0 && j < size)
                {
                    k--;
                }
            }
        }
    }

    t_print(obj);
}