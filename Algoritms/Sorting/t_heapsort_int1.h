#include "../Array/tarray_int.h"
void Heapify1(tarray_int& obj , int size , int index)
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
        Heapify1(obj , size , largest);
    }
} 
void t_heapSort_int(tarray_int &obj , int size)
{
    for(int i = (size / 2) - 1; i >= 0; i--)
    {
        Heapify1(obj , size , i);
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
        Heapify1(obj , i , 0);
    }
    t_print(obj);
}