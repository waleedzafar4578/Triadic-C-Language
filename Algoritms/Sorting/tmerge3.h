#include "../Array/tarray_int.h"

void merge3(tarray_int &array, int l, int m, int r)
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
void mergeSort3(tarray_int &array, int l, int r)
{
    int m;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        // Sort first and second arrays
        mergeSort3(array, l, m);
        mergeSort3(array, m + 1, r);
        merge3(array, l, m, r);
    }
}

void tmerge3(tarray_int &array, int size)
{
    int t = 0, l = 0, f = 0;
    for (int i = 0; i < size; i++)
    {
        if (array.g_indexD(i) == T)
        {
            if (array.get_pointer_value_degree(i) == T)
            {
                t++;
            }
            else if (array.get_pointer_value_degree(i) == F)
            {
                f++;
            }
            else
            {
                l++;
            }
        }
    }

    tarray_int tarr(t, T);
    tarray_int larr(l, T);
    tarray_int farr(f, T);
    int i = 0, i1 = 0, i2 = 0, i3 = 0;
    for (; i < size; i++)
    {
        if (array.g_indexD(i) == T)
        {
            if (array.get_pointer_value_degree(i) == T)
            {
                tarr.set_pointer_value(i2, array.get_pointer_value(i));
                tarr.set_pointer_value_degree(i2, array.get_pointer_value_degree(i));
                i2++;
            }
            else if (array.get_pointer_value_degree(i) == F)
            {
                farr.set_pointer_value(i3, array.get_pointer_value(i));
                farr.set_pointer_value_degree(i3, array.get_pointer_value_degree(i));
                i3++;
            }
            else if (array.get_pointer_value_degree(i) == L)
            {
                larr.set_pointer_value(i1, array.get_pointer_value(i));
                larr.set_pointer_value_degree(i1, array.get_pointer_value_degree(i));
                i1++;
            }
        }
    }
    // cout << i1 << " " << i2 << " " << i3 << endl;
    i1--, i2--, i3--;
    mergeSort3(tarr, 0, i2);
    mergeSort3(farr, 0, i3);
    mergeSort3(larr, 0, i1);

    // t_print(larr);
    // cout << endl;
    // t_print(tarr);
    // cout << endl;
    // t_print(farr);
    // cout << endl;

    for (int j = 0, c = 0; j < size; c++)
    {
        if (array.g_indexD(c) == T)
        {
            if (j >= 0 && j <= i1)
            {
                // cout << j << " " << endl;
                array.set_pointer_value(c, larr.get_pointer_value(j));
                array.set_pointer_value_degree(c, larr.get_pointer_value_degree(j));
            }
            else if (j >= i1 && j <= (i1 + i2 + 1))
            {
                // cout << j << " " << j - i1 - 1 << " i2 " << endl;
                array.set_pointer_value(c, tarr.get_pointer_value(j - i1 - 1));
                array.set_pointer_value_degree(c, tarr.get_pointer_value_degree(j - i1 - 1));
            }
            else if (j >= (i1 + i2) && j <= (i1 + i2 + i3 + 2))
            {
                // cout << j << " " << j - (i1 + i2 + 2) << " i3 " << endl;
                array.set_pointer_value(c, farr.get_pointer_value(j - (i1 + i2 + 2)));
                array.set_pointer_value_degree(c, farr.get_pointer_value_degree(j - (i1 + i2 + 2)));
            }
            j++;
        }
    }
    cout << endl;
    /*
        for (int j = 0; j <= i1; j++)
        {
            // cout << "i1:" << j << " ";
            array.set_pointer_value(j, larr.get_pointer_value(j));
            array.set_pointer_value_degree(j, larr.get_pointer_value_degree(j));
        }
        cout << endl;
        for (int j = 0; j <= i2; j++)
        {
            // cout << "i2:" << i1 + j + 1 << " ";
            int n = i1 + j + 1;
            array.set_pointer_value(n, tarr.get_pointer_value(j));
            array.set_pointer_value_degree(n, tarr.get_pointer_value_degree(j));
        }
        cout << endl;
        for (int j = 0; j <= i3; j++)
        {
            // cout << "i3:" << i1 + i2 + j + 2 << " ";
            int n = i1 + i2 + j + 2;
            array.set_pointer_value(n, farr.get_pointer_value(j));
            array.set_pointer_value_degree(n, farr.get_pointer_value_degree(j));
        }
        // array.set_pointer_value(j, larr.get_pointer_value(j));
        // array.set_pointer_value_degree(j, larr.get_pointer_value_degree(j));
        */
}