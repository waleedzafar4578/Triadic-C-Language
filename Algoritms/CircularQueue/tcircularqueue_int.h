#include "../Array/tarray_int.h"
class tcircularqueue_int
{
private:
    tarray_int array;
    int front;
    int rear;
    t_int size;

public:
    tcircularqueue_int(int _size, Degree D)
    {
        size.set_Degree(D);
        size.set_value(_size);
        array.create_array(_size, D);
        front = -1;
        rear = -1;
    }
    tcircularqueue_int(t_int _size)
    {
        size.set_value(_size.get_value());
        size.set_Degree(_size.get_Degree());
        array.create_array(size.get_value(), size.get_Degree());
        front = -1;
        rear = -1;
    }
    bool isFull()
    {
        if (front == 0 && rear == size.get_value() - 1)
            return true;
        if (front == rear + 1)
            return true;
        return false;
    }
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
    void enqueue(t_int val)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else
        {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % size.get_value();
            if (array.g_indexD(rear) == L || array.g_indexD(rear) == F)
            {
                array.s_indexD(rear, T);
            }
            set_value(array, rear, val.get_value());
            set_vdegree(array, rear, val.get_Degree());
        }
    }
    void enqueue(int value , Degree d)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else
        {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % size.get_value();
            if (array.g_indexD(rear) == L || array.g_indexD(rear) == F)
            {
                array.s_indexD(rear, T);
            }
            set_value(array, rear, value);
            set_vdegree(array, rear, d);
        }
    }
    t_int dequeue()
    {
        t_int element;
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return element;
        }
        else
        {
            element.set_value(array.get_pointer_value(front));
            element.set_Degree(array.get_pointer_value_degree(front));
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % size.get_value();
            }
            return element;
        }
    }
    int get_size()
    {
        return size.get_value();
    }
    int get_front_value()
    {
        return front;
    }
    int get_rear_value()
    {
        return rear;
    }
    void pri()
    {

        for (int i = front; i <= rear; i++)
        {
            t_print(array, i);
        }
    }
};
void scanQueue(tcircularqueue_int &obj, int size)
{
    for (int i = 0; i < size; i++)
    {
        int output;
        cout << "Enter A Number: ";
        cin >> output;
        char D;
        cout << "Enter The Degree Of Number: ";
        cin >> D;
        Degree d = enum_convert(D);
        t_int val(output, d);
        obj.enqueue(val);
    }
}
void scanQueue(tcircularqueue_int &obj)
{
    int _size;
    cout << "Enter Number Of Values: ";
    cin >> _size;
    if (obj.get_size() < obj.get_rear_value() + _size)
    {
        cout << "The number of values is greater than the size of queue." << endl;
        cout << "Press Y to continue. Enter any key to leave." << endl;
        char _continue;
        cin >> _continue;
        if (_continue == 'Y' || _continue == 'y')
        {
            for (int i = obj.get_rear_value(); i < obj.get_size(); i++)
            {
                int output;
                cout << "Enter A Number: ";
                cin >> output;
                char D;
                cout << "Enter The Degree Of Number: ";
                cin >> D;
                Degree d = enum_convert(D);
                t_int val(output, d);
                obj.enqueue(val);
            }
            cout << "Queue Is Full" << endl;
        }
        else
        {
            return;
        }
    }
    if (obj.get_rear_value() < 0)
    {
        for (int i = obj.get_rear_value() + 1; i < _size; i++)
        {
            
            int output;
            cout << "Enter A Number: ";
            cin >> output;
            char D;
            cout << "Enter The Degree Of Number: ";
            cin >> D;
            Degree d = enum_convert(D);
            t_int val(output, d);
            obj.enqueue(val);
        }
    }
    else
    {
        for (int i = obj.get_rear_value(); i < _size; i++)
        {
            int output;
            cout << "Enter A Number: ";
            cin >> output;
            char D;
            cout << "Enter The Degree Of Number: ";
            cin >> D;
            Degree d = enum_convert(D);
            t_int val(output, d);
            obj.enqueue(val);
        }
    }
}
void printQueue(tcircularqueue_int &obj)
{
    int temp_top = obj.get_front_value();
    obj.pri();
}