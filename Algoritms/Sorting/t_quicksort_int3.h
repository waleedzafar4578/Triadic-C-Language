#include "../Array/tarray_int.h"
int partition3(tarray_int &obj, int start, int end)
{
    int pivot = obj.get_pointer_value(start);
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (obj.get_pointer_value(i) <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    int temp = obj.get_pointer_value(pivotIndex);
    obj.set_pointer_value(pivotIndex, obj.get_pointer_value(start));
    obj.set_pointer_value(start, temp);
    int i = start;
    int j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (obj.get_pointer_value(i) <= pivot)
            i++;
        while (obj.get_pointer_value(j) > pivot)
            j--;
        if (i < pivotIndex && j > pivotIndex)
        {
            int temp = obj.get_pointer_value(i + 1);
            obj.set_pointer_value(i, obj.get_pointer_value(j - 1));
            obj.set_pointer_value(j, temp);
        }
    }
    return pivotIndex;
}
void QuickSort3(tarray_int &obj, int start, int end)
{
    if (start >= end)
        return;
    int p = partition3(obj, start, end);
    QuickSort3(obj, start, p - 1);
    QuickSort3(obj, p + 1, end);
}
void t_quicksort_int3(tarray_int &obj)
{
    int filter1_size = 0;
    int size = obj.get_size();
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
        filter1.set_pointer_value(filter1_index, obj.get_pointer_value(i));
        filter1.set_pointer_value_degree(filter1_index, obj.get_pointer_value_degree(i));
        filter1_index++;
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
    QuickSort3(filter2f, 0, filter2f_size - 1);
    QuickSort3(filter2l, 0, filter2l_size - 1);
    QuickSort3(filter2t, 0, filter2t_size - 1);
    int filter3_size = filter1_size;
    tarray_int filter3(filter3_size, T);
    for (int i = 0; i < filter3_size;)
    {
        for (int j = 0; j < filter2l_size; j++)
        {
            filter3.set_pointer_value(i, filter2l.get_pointer_value(j));
            filter3.set_pointer_value_degree(i, filter2l.get_pointer_value_degree(j));
            i++;
        }
        for (int j = 0; j < filter2t_size; j++)
        {
            filter3.set_pointer_value(i, filter2t.get_pointer_value(j));
            filter3.set_pointer_value_degree(i, filter2t.get_pointer_value_degree(j));
            i++;
        }
        for (int j = 0; j < filter2f_size; j++)
        {
            filter3.set_pointer_value(i, filter2f.get_pointer_value(j));
            filter3.set_pointer_value_degree(i, filter2f.get_pointer_value_degree(j));
            i++;
        }
    }
    t_print(filter3);
}
