#include "../2darray/t2Darray_int.h"
#include "../CircularQueue/tcircularqueue_int.h"
void t_breadthfirstsearch(t2Darray_int *arr, tp_int &target, tp_int &starting)
{
    tcircularqueue_int queue(arr->numberOfRows(), L);
    int number = arr->numberOfRows();
    bool *visited = new bool[number];
    for (int i = 0; i < number; i++)
    {
        visited[i] = false;
    }
    if (target.get_value() > arr->numberOfRows() || target.get_value() < 0)
    {
        cout << "Target Is Not Present In Graph" << endl;
        return;
    }
    else if (starting.get_value() > arr->numberOfRows() || starting.get_value() < 0)
    {
        cout << "Starting Point Is Not Presetn In Graph" << endl;
        return;
    }
    else
    {
        queue.enqueue(starting.get_value(), starting.get_Degree_val());
        while (!queue.isEmpty())
        {
            bool flag = true;
            t_int node = queue.dequeue();
            int p = node.get_value();
            if(visited[p] == false)
            {
                t_print(node);
            }
            
            if (node.get_value() == target.get_value() && node.get_Degree() == target.get_Degree_val())
            {
                cout << "Target Found" << endl;
                return;
            }
            int in = node.get_value();
            if (visited[in] == true)
            {
                flag = false;
            }
            if (flag)
            {
                int index = node.get_value();
                visited[index] = true;
                for (int i = 0; i < arr->numberofColumns(); i++)
                {
                    // tp_int val(-1 ,T , T);
                    // val.set_value(arr->get(index , i).get_value());
                    // if(val.get_value() == 1 && val.get_Degree_val() == T)
                    // {
                    //     queue.push(val.get_value() , val.get_Degree_val());
                    // }
                    t_int val(-1, T);
                    val.set_value(arr->get(index, i).get_value());
                    if (val.get_value() == 1 && val.get_Degree() == T)
                    {
                        queue.enqueue(i, val.get_Degree());
                    }
                }
            }
        }
        cout << "Target Not Found" << endl;
    }
}