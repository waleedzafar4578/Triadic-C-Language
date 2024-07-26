#include "../Array/tarray_int.h"
int Partition(tarray_int &obj, int start, int end)
{
    int pivot = obj.get_pointer_value(end);
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (obj.get_pointer_value(j) <= pivot)
        {
            i++;
            int temp = obj.get_pointer_value(i);
            Degree D = obj.get_pointer_value_degree(i);
            obj.set_pointer_value(i, obj.get_pointer_value(j));
            obj.set_pointer_value_degree(i, obj.get_pointer_value_degree(j));
            obj.set_pointer_value(j, temp);
            obj.set_pointer_value_degree(j, D);
        }
    }
    int k = i + 1;
    int temp = obj.get_pointer_value(k);
    Degree D = obj.get_pointer_value_degree(k);
    obj.set_pointer_value(k, obj.get_pointer_value(end));
    obj.set_pointer_value_degree(k, obj.get_pointer_value_degree(end));
    obj.set_pointer_value(end, temp);
    obj.set_pointer_value_degree(end, D);
    return (i + 1);
}
void QuickSort2(tarray_int &obj, int start, int end)
{
    if (start < end)
    {
        int p = Partition(obj, start, end);
        QuickSort2(obj, start, p - 1);
        QuickSort2(obj, p + 1, end);
    }
}
void t_quicksort_int2(tarray_int &obj)
{
    int size = obj.get_size();
    QuickSort2(obj, 0, size - 1);
}