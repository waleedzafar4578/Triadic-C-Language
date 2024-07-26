#include"t_b_tree_node.h"
class t_b_tree
{
    t_b_tree_node *Root;
    int minimumDegree;
public:
    t_b_tree(int _minimumDegree)
    {
        Root = NULL;
        minimumDegree = _minimumDegree;
    }
    void Traversal()
    {
        if(Root != NULL)
            Root->traverse();
    }
    t_b_tree_node* Search(t_int val)
    {
        if(Root == NULL)
            return NULL;
        else
            return Root->search(val);
    }
    void Insert(t_int val)
    {
        //If The Root Is Empty
        if(Root == NULL)
        {
            Root = new t_b_tree_node(minimumDegree , true);
            if(Root->keys.g_indexD(0) == L)
            {
                Root->keys.s_indexD(0 , T);
            }
            int location = 0;
            Root->keys.set_pointer_value(location , val.get_value());
            Root->keys.set_pointer_value_degree(location , val.get_Degree());
            Root->numberOfKeys = 1;
        }
        else
        {
            //If The Root Is Full
            if(Root->numberOfKeys == (2 * minimumDegree - 1))
            {
                // Making A New Root Which Is Not Going To Be A Leaf Node Since We Are Going To Split It
                t_b_tree_node *NewRoot =  new t_b_tree_node(minimumDegree , false); 
                //Making Old Root The Child Of New Node So That We Can Split It 
                NewRoot->Children[0] = Root;
                NewRoot->splitingChild(0  , Root);
                //Now The New Root Has 2 Children(One The Old Root With Only The Children And Keys Less
                //Than Middle Key And The Child With Keys Greater Than Middle Key) And It Has A Key Which
                //Was The Middle Key Of The New Node
                //Now We Have To Decide Which Child Is Going To Have The New Key
                int i = 0;
                if(NewRoot->keys.get_pointer_value(0) < val.get_value())
                {
                    i++;
                }
                NewRoot->Children[i]->insertNonFull(val);
                Root = NewRoot;
            }
            else
            {
                Root->insertNonFull(val);
            }
        }
    }
    void Remove(t_int val)
    {
        if(Root == NULL)
        {
            cout<<"The Tree Is Empty"<<endl;
            return;
        }
        Root->removeKey(val);
        //If All The Keys Of Root Got Deleted We Have To Make Its First Child The New Root And If It
        //Doesnot HAve Any Child Just Simply Make It NULL
        if(Root->numberOfKeys == 0)
        {
            t_b_tree_node *temp = Root;
            if(Root->isLeaf == true)
                Root = NULL;
            else
                Root = Root->Children[0];
            delete temp;
        }
        return;
    }
};