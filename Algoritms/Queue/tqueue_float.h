#include "../Array/tarray_float.h"
class tqueue_float
{
private:
    tarray_float array;
    int front;
    int rear;
    t_int size;

public:
    tqueue_float(int _size, Degree D)
    {
        size.set_value(_size);
        size.set_Degree(D);
        array.create_array(size.get_value(), size.get_Degree());
        front = -1;
        rear = -1;
    }
    tqueue_float(t_int _size)
    {
        size.set_value(_size.get_value());
        size.set_Degree(_size.get_Degree());
        array.create_array(size.get_value(), size.get_Degree());
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (rear == (size.get_value() - 1))
            return true;
        else
            return false;
    }
    void enqueue(t_float value)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear++;
        if (isEmpty())
        {
            rear = 0;
            front = 0;
        }
        if (array.g_indexD(rear) == L || array.g_indexD(rear) == F)
        {
            array.s_indexD(rear, T);
        }
        set_value(array, rear, value.get_value());
        set_vdegree(array, rear, value.get_Degree());
    }
    void enqueue(float value, Degree d)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear++;
        if (isEmpty())
        {
            rear = 0;
            front = 0;
        }
        if (array.g_indexD(rear) == L || array.g_indexD(rear) == F)
        {
            array.s_indexD(rear, T);
        }
        set_value(array, rear, value);
        set_vdegree(array, rear, d);
    }
    t_float dequeue()
    {
        t_float returningValue;
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return returningValue;
        }
        returningValue.set_value(array.get_pointer_value(front));
        returningValue.set_Degree(array.get_pointer_value_degree(front));
        array.s_indexD(front, L);
        front++;
        if(front == rear)
        {
            front = 0;
            rear = 0;
        }
        return returningValue;
    }
    float get_array_front_value()
    {
        return array.get_pointer_value(front);
    }
    //
    float get_array_rear_value()
    {
        return array.get_pointer_value(rear);
    }
    tarray_float get_array()
    {
        return array;
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

void scanQueue(tqueue_float &obj, int size)
{
    for (int i = 0; i < size; i++)
    {
        float output;
        cout << "Enter A Number: ";
        cin >> output;
        char D;
        cout << "Enter The Degree Of Number: ";
        cin >> D;
        Degree d = enum_convert(D);
        t_float val(output, d);
        obj.enqueue(val);
    }
}
void scanQueue(tqueue_float &obj)
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
                float output;
                cout << "Enter A Number: ";
                cin >> output;
                char D;
                cout << "Enter The Degree Of Number: ";
                cin >> D;
                Degree d = enum_convert(D);
                t_float val(output, d);
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

            float output;
            cout << "Enter A Number: ";
            cin >> output;
            char D;
            cout << "Enter The Degree Of Number: ";
            cin >> D;
            Degree d = enum_convert(D);
            t_float val(output, d);
            obj.enqueue(val);
        }
    }
    else
    {
        for (int i = obj.get_rear_value(); i < _size; i++)
        {
            float output;
            cout << "Enter A Number: ";
            cin >> output;
            char D;
            cout << "Enter The Degree Of Number: ";
            cin >> D;
            Degree d = enum_convert(D);
            t_float val(output, d);
            obj.enqueue(val);
        }
    }
}
void printQueue(tqueue_float &obj)
{
    int temp_top = obj.get_front_value();
    // t_int_queue tempqueue(obj.get_size() , T);
    // for(int i = temp_top; i >= 0; i--)
    // {
    //     t_int_ptr k = obj.pop();
    //     cout<<k.get_value()<<"--------"<<endl;
    //     tempqueue.push(k.get_value());
    // }
    // for(int i = 0; i < tempqueue.get_size(); i++)
    // {
    //     obj.push(tempqueue.pop());
    // }

    obj.pri();
}