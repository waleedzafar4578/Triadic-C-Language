#include "../Array/tarray_int.h"

void merge(tarray_int &array, int l, int m, int r)
{
    int i, j, k, nl, nr;
    // size of left and right sub-arrays
    nl = m - l + 1;
    nr = r - m;
    // int larr[nl], rarr[nr];
    tarray_int larr(nl, T);
    tarray_int rarr(nr, T);
    // fill left and right sub-arrays
    for (i = 0; i < nl; i++)
    {
        // larr[i] = array[l + i];
        int z = l + i;
        larr.set_pointer_value(i, array.get_pointer_value(z));
        larr.set_pointer_value_degree(i, array.get_pointer_value_degree(z));
    }

    for (j = 0; j < nr; j++)
    {
        // rarr[j] = array[m + 1 + j];
        int z = m + 1 + j;
        rarr.set_pointer_value(j, array.get_pointer_value(z));
        rarr.set_pointer_value_degree(j, array.get_pointer_value_degree(z));
    }

    i = 0;
    j = 0;
    k = l;
    // marge temp arrays to real array
    while (i < nl && j < nr)
    {
        if (larr.get_pointer_value(i) <= rarr.get_pointer_value(j))
        {
            // array[k] = larr[i];
            array.set_pointer_value(k, larr.get_pointer_value(i));
            array.set_pointer_value_degree(k, larr.get_pointer_value_degree(i));
            i++;
        }
        else
        {
            // array[k] = rarr[j];
            array.set_pointer_value(k, rarr.get_pointer_value(j));
            array.set_pointer_value_degree(k, rarr.get_pointer_value_degree(j));
            j++;
        }
        k++;
    }
    while (i < nl)
    { // extra element in left array
        array.set_pointer_value(k, larr.get_pointer_value(i));
        array.set_pointer_value_degree(k, larr.get_pointer_value_degree(i));
        i++;
        k++;
    }
    while (j < nr)
    { // extra element in right array
        array.set_pointer_value(k, rarr.get_pointer_value(j));
        array.set_pointer_value_degree(k, rarr.get_pointer_value_degree(j));
        j++;
        k++;
    }
}
void mergeSort(tarray_int &array, int l, int r)
{
    int m;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        // Sort first and second arrays
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}

void tmerge1(tarray_int &array, int size)
{
    mergeSort(array, 0, size);
}