#include <iostream>
#include <string>
#include <variant>
using namespace std;

class car
{
public:
    int speed;
    string name;
    car(string t, int n)
    {
        name = t;
        speed = n;
    };
    void show()
    {
        cout << name << "    " << speed << endl;
    }
};
ostream &operator<<(ostream &cout, car &obj)
{
    obj.show();
    return cout;
}

class t_hnode
{
public:
    variant<int, float, char, string, car> data;
    t_hnode *next;
    t_hnode(variant<int, float, char, string, car> r_data)
    {
        data = r_data;
        next = nullptr;
    }
    void display()
    {
        if (get_if<int>(&data))
        {
            cout << get<int>(data) << endl;
        }
        else if (get_if<float>(&data))
        {
            cout << get<float>(data) << endl;
        }
        else if (get_if<char>(&data))
        {
            cout << get<char>(data) << endl;
        }
        else if (get_if<string>(&data))
        {
            cout << get<string>(data) << endl;
        }
        else if (get_if<car>(&data))
        {
            cout << get<car>(data) << endl;
        }
        else
        {
            cout << "Empty" << endl;
        }
    }
};
class hetro_linklist
{
private:
    t_hnode *head = nullptr;
    t_hnode* add_node(t_hnode *head, variant<int, float, char, string, car> data)
    {
        if (head == nullptr)
        {
            head = new t_hnode(data);
            return head;
        }
        else
        {
           head->next= add_node(head->next,data);
        }
        return head;
    }

public:
    hetro_linklist(variant<int, float, char, string, car> data)
    {
        head = new t_hnode(data);
    }
    void
    insert(variant<int, float, char, string, car> data)
    {
        head=add_node(head,data);
    }
    void
    display()
    {
        t_hnode *temp = head;
        while (true)
        {
            if (temp == nullptr)
            {
                break;
            }
            else
            {
                temp->display();
                temp = temp->next;
            }
        }
    }
};

void fun(variant<int, float, char, string, car> pin)
{
    cout << get<car>(pin) << endl;
}

int main()
{

    // string show = "Enter Value: ";
    // t_hnode b;

    //   b.data = car("toyota", 100);
    // b.display();

    // fun(car("Mestange", 500));
    variant<int, float, char, string, car> data, d2, d3;
    data = "waleed";
    d2 = 45;
    d3 = car("mestang", 4899);
    hetro_linklist list(data);
    list.insert(d2);
    list.insert(d3);
    list.display();
}