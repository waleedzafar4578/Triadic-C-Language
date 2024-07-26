

#include "../Array/tarray_int.h"
class tstack_int
{
    tarray_int array;
    t_int size;
    int top;

public:
    tstack_int(int _size, Degree D)
    {
        size.set_value(_size);
        size.set_Degree(D);
        array.create_array(size.get_value(), size.get_Degree());
        top = -1;
    }
    tstack_int(t_int _size)
    {
        size.set_value(_size.get_value());
        size.set_Degree(_size.get_Degree());
        array.create_array(size.get_value(), size.get_Degree());
        top = -1;
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (top == (size.get_value()) - 1)
            return true;
        else
            return false;
    }
    bool isLimit()
    {
        if(!isEmpty() && !isFull())
        {
            return true;
        }
        else
            return false;
    }
    void push(t_int val)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        if (array.g_indexD(top) == L || array.g_indexD(top) == F)
        {
            array.s_indexD(top, T);
        }
        set_value(array, top, val.get_value());
        set_vdegree(array, top, val.get_Degree());
    }
    void push(int val, Degree d)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        if (array.g_indexD(top) == L || array.g_indexD(top) == F)
        {
            array.s_indexD(top, T);
        }
        set_value(array, top, val);
        set_vdegree(array, top, d);
    }
    t_int pop()
    {
        t_int returningValue;
        if(isEmpty())
        {
            cout<<"Stack Underflow"<<endl;
            return returningValue;
        }
        returningValue.set_value(array.get_pointer_value(top));
        returningValue.set_Degree(array.get_pointer_value_degree(top));
        array.s_indexD(top , L);
        top--;
        return returningValue;
    }
//     // void set_top_value(int value)
//     // {
//     //     top.set_value(value);
//     // }
    int get_top_value()
    {
        return top;
    }
//     // degree get_top_degree()
//     // {
//     //     return top.get_degree();
//     // }
//     // int get_size_value()
//     // {
//     //     return size.get_value();
//     // }
//     // degree get_size_degree()
//     // {
//     //     return size.get_degree();
//     // }
//     // void set_array_top_value(int val)
//     // {

//     // }
    int get_array_top_value()
    {
        return array.get_pointer_value(top);
    }
//     // void set_array_top_degree(degree D)
//     // {

//     // }
//     // degree get_array_top_degree()
//     // {
//     //     array.g_indexD(top.get_value());
//     // }
    tarray_int get_array()
    {
        return array;
    }
    int get_size()
    {
        return size.get_value();
    }
    void pri()
    {

        for (int i = top; i >= 0; i--)
        {
            t_print(array, i);
        }
    }
 };

void scanStack(tstack_int &obj, int size)
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
        obj.push(val);
    }
}
void scanStack(tstack_int &obj)
{
    int _size;
    cout << "Enter Number Of Values: ";
    cin >> _size;
    if (obj.get_size() < obj.get_top_value() + _size)
    {
        cout << "The number of values is greater than the size of stack" << endl;
        cout << "Press Y to continue. Enter any key to leave." << endl;
        ;
        char _continue;
        cin >> _continue;
        if (_continue == 'Y' || _continue == 'y')
        {
            for (int i = obj.get_top_value(); i < obj.get_size(); i++)
            {
                int output;
                cout << "Enter A Number: ";
                cin >> output;
                char D;
                cout << "Enter The Degree Of Number: ";
                cin >> D;
                Degree d = enum_convert(D);
                t_int val(output, d);
                obj.push(val);
            }
            cout << "Stack Is Full" << endl;
        }
        else
        {
            return;
        }
    }
    if (obj.get_top_value() == -1)
    {

        for (int i = 0; i < _size; i++)
        {
            int output;
            cout << "Enter A Number: ";
            cin >> output;
            char D;
            cout << "Enter The Degree Of Number: ";
            cin >> D;
            Degree d = enum_convert(D);
            t_int val(output, d);
            obj.push(val);
        }
    }
    else
    {
        for (int i = obj.get_top_value(); i < _size; i++)
        {
            int output;
            cout << "Enter A Number: ";
            cin >> output;
            char D;
            cout << "Enter The Degree Of Number: ";
            cin >> D;
            Degree d = enum_convert(D);
            t_int val(output, d);
            obj.push(val);
        }
    }
}
void printStack(tstack_int &obj)
{
    int temp_top = obj.get_top_value();
    // t_int_stack tempStack(obj.get_size() , T);
    // for(int i = temp_top; i >= 0; i--)
    // {
    //     t_int_ptr k = obj.pop();
    //     cout<<k.get_value()<<"--------"<<endl;
    //     tempStack.push(k.get_value());
    // }
    // for(int i = 0; i < tempStack.get_size(); i++)
    // {
    //     obj.push(tempStack.pop());
    // }

    obj.pri();
}