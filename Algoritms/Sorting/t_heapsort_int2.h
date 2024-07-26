#include "../Array/tarray_int.h"
void Heapify2(tarray_int& obj , int size , int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if(left < size && obj.get_pointer_value(left) > obj.get_pointer_value(largest))
        largest = left;
    if(right < size && obj.get_pointer_value(right) > obj.get_pointer_value(largest))
        largest = right;
    if(largest != index)
    {
        int temp = obj.get_pointer_value(index);
        Degree D = obj.get_pointer_value_degree(index);
        obj.set_pointer_value(index , obj.get_pointer_value(largest));
        obj.set_pointer_value_degree(index , obj.get_pointer_value_degree(largest));
        obj.set_pointer_value(largest , temp);
        obj.set_pointer_value_degree(largest , D);
        Heapify2(obj , size , largest);
    }
} 
void HeapSort(tarray_int &obj , int size)
{
    for(int i = (size / 2) - 1; i >= 0; i--)
    {
        Heapify2(obj , size , i);
    }
    for(int i = size - 1; i >= 0; i--)
    {
        int a = 0;
        int temp = obj.get_pointer_value(0);
        Degree D = obj.get_pointer_value_degree(0);
        obj.set_pointer_value(a , obj.get_pointer_value(i));
        obj.set_pointer_value_degree(a , obj.get_pointer_value_degree(i));
        obj.set_pointer_value(i , temp);
        obj.set_pointer_value_degree(i , D);
        Heapify2(obj , i , 0);
    }
}
void t_heapsort_int2(tarray_int& obj , int size)
{
    int filter1_size = 0;
    for (int i = 0; i < size; i++)
    {
        if (obj.g_indexD(i) == T)
        {
            filter1_size++;
        }
    }
    int filter1_index = 0;
    tarray_int filter1(filter1_size, T);
    for (int i = 0; i < filter1_size; i++)
    {
        if (obj.g_indexD(i) == T)
        {
            filter1.set_pointer_value(filter1_index, obj.get_pointer_value(i));
            filter1.set_pointer_value_degree(filter1_index, obj.get_pointer_value_degree(i));
            filter1_index++;
        }
    }
    int filter2t_size = 0;
    int filter2f_size = 0;
    int filter2l_size = 0;
    for (int i = 0; i < filter1_size; i++)
    {
        if (filter1.get_pointer_value_degree(i) == T)
        {
            filter2t_size++;
        }
        else if (filter1.get_pointer_value_degree(i) == F)
        {
            filter2f_size++;
        }
        else
        {
            filter2l_size++;
        }
    }
    tarray_int filter2t(filter2t_size, T);
    tarray_int filter2f(filter2f_size, T);
    tarray_int filter2l(filter2l_size, T);
    int filter2t_index = 0;
    int filter2f_index = 0;
    int filter2l_index = 0;
    for (int i = 0; i < filter1_size; i++)
    {
        if (filter1.get_pointer_value_degree(i) == T)
        {
            filter2t.set_pointer_value(filter2t_index, filter1.get_pointer_value(i));
            filter2t.set_pointer_value_degree(filter2t_index, filter1.get_pointer_value_degree(i));
            filter2t_index++;
        }
        else if (filter1.get_pointer_value_degree(i) == F)
        {
            filter2f.set_pointer_value(filter2f_index, filter1.get_pointer_value(i));
            filter2f.set_pointer_value_degree(filter2f_index, filter1.get_pointer_value_degree(i));
            filter2f_index++;
        }
        else
        {
            filter2l.set_pointer_value(filter2l_index, filter1.get_pointer_value(i));
            filter2l.set_pointer_value_degree(filter2l_index, filter1.get_pointer_value_degree(i));
            filter2l_index++;
        }
    }
    HeapSort(filter2f , filter2f_index);
    HeapSort(filter2l , filter2l_index);
    HeapSort(filter2t , filter2t_index);
    int filter3_size = filter1_size;
    tarray_int filter3(filter3_size , T);
    for(int i = 0; i < filter3_size;)
    {
        for(int j = 0; j < filter2l_size; j++)
        {
            filter3.set_pointer_value(i , filter2l.get_pointer_value(j));
            filter3.set_pointer_value_degree(i , filter2l.get_pointer_value_degree(j));
            i++;
        }
        for(int j = 0; j < filter2t_size; j++)
        {
            filter3.set_pointer_value(i , filter2t.get_pointer_value(j));
            filter3.set_pointer_value_degree(i , filter2t.get_pointer_value_degree(j));
            i++;
        }
        for(int j = 0; j < filter2f_size; j++)
        {
            filter3.set_pointer_value(i , filter2f.get_pointer_value(j));
            filter3.set_pointer_value_degree(i , filter2f.get_pointer_value_degree(j));
            i++;
        }
    }
    t_print(filter3);
}