#include "Array/tarray_int.h"
void t_bubble_with_supra(tarray_int &obj)
{
    int size = obj.get_size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            tp_int result = supra_less(obj.g_indexD(j), obj.g_indexD(j + 1));
            switch (result.get_value())
            {
            case 1:
                break;

            default:
                break;
            }
        }
    }
}