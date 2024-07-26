#include "../Array/tarray_int.h"
class t_b_tree_node
{
    tarray_int keys;
    int minimumKeys;
    t_b_tree_node **Children;
    int numberOfKeys;
    bool isLeaf;

public:
    t_b_tree_node(int minKeys, bool leaf)
    {
        minimumKeys = minKeys;
        isLeaf = leaf;
        int size = 2 * minimumKeys - 1;
        keys.create_array(size, L);
        Children = new t_b_tree_node *[2 * minimumKeys];
        numberOfKeys = 0;
    }
    t_b_tree_node *search(t_int val)
    {
        int i = 0;
        // Finding The Value In The Keys That Is Greater Than Or Equal To The Value That Is Being Searched
        while (i < numberOfKeys && val.get_value() > keys.get_pointer_value(i))
        {
            i++;
        }
        // If The Value Is Found In Keys
        if (keys.get_pointer_value(i) == val.get_value() && keys.get_pointer_value_degree(i) == val.get_Degree())
        {
            return this;
        }
        // If The Value Is Not Found In Keys
        // We Have Reached The Leaf Node With Value That May Be Equal To 'Val' But Did Not Found It
        // After Checking All The Non-Leaf Nodes That May Have Value Equal To The 'Val'
        if (isLeaf == true)
        {
            return NULL;
        }
        // Checking Appropriate Children (If It Is Not Leaf And We Have Not Found The Value Then Search
        // Further)
        return Children[i]->search(val);
    }
    void traverse()
    {
        int i;
        for (i = 0; i < numberOfKeys; i++)
        {
            // If It Is Not The Leaf Then Traverse Further And Print All The Keys On Leaf
            if (isLeaf == false)
                Children[i]->traverse();
            cout << keys.get_pointer_value(i) << " ";
        }
        // There Are N Keys And N+1 Children Of A Node. The Above Loop Will Traverse Through N Keys
        // Of N Children But There Is Still 1 Child Left To Be Traversed So:
        if (isLeaf == false)
            Children[i]->traverse();
    }
    // This Function will insert the value in a node with the assumption that it is not full
    void insertNonFull(t_int val)
    {
        // We are starting from the end of the keys array
        int i = numberOfKeys - 1;
        // If The Node Is A Leaf Then We Just Have To Insert It In
        if (isLeaf == true)
        {
            // We Will Move All The Keys That Are Greater Than 'Val' To The Right And Then Place The
            //'Val' In The Empty Location
            int location = i + 1;
            if (keys.g_indexD(location) == L)
            {
                keys.s_indexD(location, T);
            }
            while (i >= 0 && keys.get_pointer_value(i) > val.get_value())
            {
                int loc = i + 1;
                keys.set_pointer_value(loc, keys.get_pointer_value(i));
                keys.set_pointer_value_degree(loc, keys.get_pointer_value_degree(i));
                i--;
            }
            int l = i + 1;
            if (keys.g_indexD(l) == L)
            {
                keys.s_indexD(l, T);
            }
            keys.set_pointer_value(l, val.get_value());
            keys.set_pointer_value_degree(l, val.get_Degree());
            numberOfKeys++;
        }
        // If The Node Is Not Leaf
        else
        {
            // We Have To Find The Appropriate Child That Will Have The 'Val'.
            // We Will Do This The Same Way We Find The Correct Location For The 'Val' In Key Array
            while (i >= 0 && keys.get_pointer_value(i) > val.get_value())
            {
                i--;
            }
            // Now We Have The Correct Child To Have The 'Val'.
            // Now We Have To Check If The Child Is Already Have The Maximum Ammount Of Keys
            // If Itb Has We Have To Split It And Store The 'Val' Accordingly
            if (Children[i + 1]->numberOfKeys == (2 * minimumKeys - 1))
            {
                splitingChild(i + 1, Children[i + 1]);
                // After Spliting, the middle key of Children[i] goes up and Children[i] is splited
                // into two. See which of these two is going to have the new key
                if (keys.get_pointer_value(i + 1) < val.get_value())
                    i++;
            }
            Children[i + 1]->insertNonFull(val);
        }
    }
    void splitingChild(int indexInKeys, t_b_tree_node *Node)
    {
        // We Will Create A New Node That Will Contain (minimumKeys - 1) number of keys of 'Node'
        t_b_tree_node *NewNode = new t_b_tree_node(Node->minimumKeys, Node->isLeaf);
        NewNode->numberOfKeys = minimumKeys - 1;
        // Now We Copy last (minimumKeys - 1) Number Of Keys Of 'Node' to 'NewNode

        for (int j = 0; j < minimumKeys - 1; j++)
        {
            if (NewNode->keys.g_indexD(j) == L)
            {
                NewNode->keys.s_indexD(j, T);
            }
            if (NewNode->keys.g_indexD(j + minimumKeys) == L)
            {
                NewNode->keys.s_indexD(j + minimumKeys, T);
            }
            NewNode->keys.set_pointer_value(j, Node->keys.get_pointer_value(j + minimumKeys));
            NewNode->keys.set_pointer_value_degree(j, Node->keys.get_pointer_value_degree(j + minimumKeys));
        }
        // Copying Last (minimumKeys) number of Children Of 'Node' to 'NewNode;
        if (Node->isLeaf == false)
        {
            for (int j = 0; j < minimumKeys; j++)
                NewNode->Children[j] = Node->Children[j + minimumKeys];
        }
        // Reducing The  Number Of Number Of Keys In 'Node'
        Node->numberOfKeys = minimumKeys - 1;
        // The Calling Node Is Going To Have A New Child So We Have To Make Space For It
        for (int j = numberOfKeys; j >= indexInKeys + 1; j--)
            Children[j + 1] = Children[j];
        // Assigning the child to the appropriate location in the node
        Children[indexInKeys + 1] = NewNode;
        // Now We Will Move Keys Of 'Node' To This Node So We Have To Find The Location Appropriate
        // For The New Key And Move All The Keys That Are Greater Than The New Key, One Space Ahead
        for (int j = numberOfKeys - 1; j >= indexInKeys; j--)
        {
            int location = j + 1;
            if (keys.g_indexD(location) == L)
            {
                keys.s_indexD(location, T);
            }
            if (keys.g_indexD(j) == L)
            {
                keys.s_indexD(j, T);
            }
            keys.set_pointer_value(location, keys.get_pointer_value(j));
            keys.set_pointer_value_degree(location, keys.get_pointer_value_degree(j));
        }
        // Copying the middle key to this node
        if (keys.g_indexD(indexInKeys) == L)
        {
            keys.s_indexD(indexInKeys, T);
        }
        if (keys.g_indexD(minimumKeys - 1) == L)
        {
            keys.s_indexD(minimumKeys - 1, T);
        }
        keys.set_pointer_value(indexInKeys, Node->keys.get_pointer_value(minimumKeys - 1));
        keys.set_pointer_value_degree(indexInKeys, Node->keys.get_pointer_value_degree(minimumKeys - 1));
        numberOfKeys++;
    }
    // This Function returns the index of the key in the array
    int findIndexOfKey(t_int val)
    {
        int index = 0;
        while (index < numberOfKeys && keys.get_pointer_value(index) < val.get_value())
            index++;
        return index;
    }
    void removeKey(t_int val)
    {
        int index = findIndexOfKey(val);
        // Checking if the key to be removed is present in the current node
        if (index < numberOfKeys && keys.get_pointer_value(index) == val.get_value())
        {
            if (isLeaf)
            {
                removeKeyFromLeaf(index);
            }
            else
            {
                removeKeyFromNonLeaf(index);
            }
        }
        else
        {
            // If The Current Node Is A Leaf Node Then It Is CLear That The Key Is Not Present In The Tree
            if (isLeaf)
            {
                cout << val.get_value() << " Is Not Present In The Tree" << endl;
                return;
            }
            // Now We Are Certain That The Key Is Present In The Tree But We Need To Find Out That If
            // The Key Is Present In The Sub-Tree Rooted By The Last Child Of The Not Or Not. Because
            // It Affects The Deletion Method As The Last Child Cannot Borrow A Child/Key From Its Right
            bool flag = ( (index == numberOfKeys)? true : false );
            // If The Child That Has The Key Has Less Than Minimum Number Of Keys(minimumKeys) Then
            // We Have To Fill(Borrow A Child/Key From Right Or Left And If We Cannot Borrow Then We
            // Have To Merge Two Nodes)
            if (Children[index]->numberOfKeys < minimumKeys)
            {
                FillChild(index);
            }
            // If The Child Has To Merge It Must Have Been Merged With Previous Child So We Have To Recur
            // On (index - 1)th Child Else We Have To Recur On (index)th Child
            if (flag && index > numberOfKeys)
                Children[index - 1]->removeKey(val);
            else
                Children[index]->removeKey(val);
        }
        return;
    }
    void removeKeyFromLeaf(int index)
    {
        // Moving All The Keys After (index)th Position Backward
        for (int i = index + 1; i < numberOfKeys; i++)
        {
            int location = i - 1;
            keys.set_pointer_value(location, keys.get_pointer_value(i));
            keys.set_pointer_value_degree(location, keys.get_pointer_value_degree(i));
        }
        numberOfKeys--;
        return;
    }
    // This Function Removes Keys From Nodes That Are Not Leaves
    void removeKeyFromNonLeaf(int index)
    {
        t_int val;
        val.set_value(keys.get_pointer_value(index));
        val.set_Degree(keys.get_pointer_value_degree(index));
        // If The Key Is In The Node That Is Not A Leaf Node We Have To Find The Inorder Predecessor Key
        // If The Inorder Predecessor Is In The Node That Has Atleast (minimumKeys) Number Of Keys
        // Then We Replace The Key With Its Inorder Predecessor And Delete The Predecessor. And If Inorder
        // Predecessor Is In The Node Tat Donot Have (minimumKeys) Number Of Key Then We Check It For
        // Inorder Successor. If The Neither The Successor Or Predecessor Has Enough Keys Then We Merge
        // Children[index] And Children[index + 1] And They Will Have (2 * t - 1) Number Of Keys So
        // We Can Delete The Key From It And It Will Still Be Balanced
        if (Children[index]->numberOfKeys >= minimumKeys)
        {
            t_int predecessor = getPredecessor(index);
            keys.set_pointer_value(index, predecessor.get_value());
            keys.set_pointer_value_degree(index, predecessor.get_Degree());
            Children[index]->removeKey(predecessor);
        }
        else if (Children[index + 1]->numberOfKeys >= minimumKeys)
        {
            t_int predecessor = getSuccessor(index);
            keys.set_pointer_value(index, predecessor.get_value());
            keys.set_pointer_value_degree(index, predecessor.get_Degree());
            Children[index + 1]->removeKey(predecessor);
        }
        else
        {
            Merge(index);
            Children[index]->removeKey(val);
        }
        return;
    }
    t_int getPredecessor(int index)
    {
        t_b_tree_node *currentNode = Children[index];
        while (!currentNode->isLeaf)
            currentNode = currentNode->Children[currentNode->numberOfKeys];
        t_int returningVal;
        returningVal.set_value(currentNode->keys.get_pointer_value(currentNode->numberOfKeys - 1));
        returningVal.set_Degree(currentNode->keys.get_pointer_value_degree(currentNode->numberOfKeys - 1));
        return returningVal;
    }
    t_int getSuccessor(int index)
    {
        t_b_tree_node *currentNode = Children[index + 1];
        while (!currentNode->isLeaf)
            currentNode = currentNode->Children[0];
        t_int returningVal;
        returningVal.set_value(currentNode->keys.get_pointer_value(0));
        returningVal.set_Degree(currentNode->keys.get_pointer_value_degree(0));
        return returningVal;
    }
    // This Function Fulfills The Deficiency Of Keys(If There Are Less Than
    //(minimumKeys - 1) number of keys) Due To Deletion Of Keys In The Node
    void FillChild(int index)
    {
        // If The Previous Child(Children[index - 1]) Has More Than (minimumKeys - 1) Number Of Keys
        // Then We Borrow A Key From It
        if (index != 0 && Children[index - 1]->numberOfKeys >= minimumKeys)
        {
            BorrowFromPreviousChild(index);
        }
        // If The Next Child(Children[index - 1]) Has More Than (minimumKeys - 1) Number Of Keys
        // Then We Borrow A Key From It
        else if (index != numberOfKeys && Children[index + 1]->numberOfKeys >= minimumKeys)
        {
            BorrowFromNextChild(index);
        }
        // If Neither Next Child Or Previous Child Has Enough Keys To Borrow Then We Have To Merge
        // If The Deficient Node Is The Last Child We Have To Merge It With The Previous One
        // Otherwise We Have To Merge It With The Next Child
        else
        {
            if (index != numberOfKeys)
            {
                Merge(index);
            }
            else
            {
                Merge(index - 1);
            }
        }
        return;
    }
    void BorrowFromPreviousChild(int index)
    {
        t_b_tree_node *borrowingChild = Children[index];
        t_b_tree_node *previousChild = Children[index - 1];
        // We Will Borrow The Last Key Of Children[index - 1] And Put It In Place Of First Key Of
        // Children[index].For That We Have TO Move All The Keys In  Children[index] One Position To Right
        for (int i = borrowingChild->numberOfKeys - 1; i >= 0; --i)
        {
            int location = i + 1;
            if(borrowingChild->keys.g_indexD(location) == L)
            {
                borrowingChild->keys.s_indexD(location , T);
                borrowingChild->keys.set_pointer_value(location , -1);
                borrowingChild->keys.set_pointer_value_degree(location , T);
            }
            borrowingChild->keys.set_pointer_value(location, borrowingChild->keys.get_pointer_value(i));
            borrowingChild->keys.set_pointer_value_degree(location, borrowingChild->keys.get_pointer_value_degree(i));
        }
        // If The 'borrowingChild' Is Not A Leaf Then We Have To Move Its Children As Well
        if (borrowingChild->isLeaf == false)
        {
            for (int i = borrowingChild->numberOfKeys; i >= 0; --i)
                borrowingChild->Children[i + 1] = borrowingChild->Children[i];
        }
        int loc = 0;
        borrowingChild->keys.set_pointer_value(loc, keys.get_pointer_value(index - 1));
        borrowingChild->keys.set_pointer_value_degree(loc, keys.get_pointer_value_degree(index - 1));
        // Now We Have To Make 'previousChild's last Child The Firts Child Of 'borrowingChild'
        if (borrowingChild->isLeaf == false)
            borrowingChild->Children[0] = previousChild->Children[previousChild->numberOfKeys];
        int l = index - 1;
        keys.set_pointer_value(l, previousChild->keys.get_pointer_value(previousChild->numberOfKeys - 1));
        keys.set_pointer_value_degree(l, previousChild->keys.get_pointer_value_degree(previousChild->numberOfKeys - 1));
        borrowingChild->numberOfKeys += 1;
        previousChild->numberOfKeys -= 1;
        return;
    }
    void BorrowFromNextChild(int index)
    {
        t_b_tree_node *borrowingChild = Children[index];
        t_b_tree_node *nextChild = Children[index + 1];
        // We Will Borrow The Last Key Of Children[index - 1] And Put It In Place Of First Key Of
        // Children[index].For That We Have TO Move All The Keys In  Children[index] One Position To Right
        borrowingChild->keys.set_pointer_value(borrowingChild->numberOfKeys , keys.get_pointer_value(index));
        borrowingChild->keys.set_pointer_value_degree(borrowingChild->numberOfKeys , keys.get_pointer_value_degree(index));
        if (borrowingChild->isLeaf == false)
        {
            borrowingChild->Children[borrowingChild->numberOfKeys + 1] = nextChild->Children[0];
        }
        keys.set_pointer_value(index , nextChild->keys.get_pointer_value(0));
        keys.set_pointer_value_degree(index , nextChild->keys.get_pointer_value_degree(0));
        for(int i = 1; i < nextChild->numberOfKeys; ++i)
        {
            int loca = i -1;
            nextChild->keys.set_pointer_value(loca , nextChild->keys.get_pointer_value(i));
            nextChild->keys.set_pointer_value_degree(loca , nextChild->keys.get_pointer_value_degree(i));
        }
        if(nextChild->isLeaf == false)
        {
            for(int i = 1; i <= nextChild->numberOfKeys; ++i)
            {
                nextChild->Children[i - 1] = nextChild->Children[i];
            }
        }
        borrowingChild->numberOfKeys += 1;
        nextChild->numberOfKeys -= 1;
        return;
    }
    void Merge(int index)
    {
        t_b_tree_node *mergerChild = Children[index];
        t_b_tree_node *mergingChild = Children[index + 1];
        int l = minimumKeys - 1;
        if(mergerChild->keys.g_indexD(l) == L)
        {
            mergerChild->keys.s_indexD(l , T);
            mergerChild->keys.set_pointer_value(l , -1);
            mergerChild->keys.set_pointer_value_degree(l , T);
        }
        mergerChild->keys.set_pointer_value(l , keys.get_pointer_value(index));
        mergerChild->keys.set_pointer_value_degree(l , keys.get_pointer_value_degree(index));
        //Copying All The Keys From 'Children[index + 1]' To The End Of Children[index]
        for(int i = 0; i < mergingChild->numberOfKeys; ++i)
        {
            int lo = i + minimumKeys;
            if(keys.g_indexD(lo) == L)
            {
                keys.s_indexD(lo , T); 
                keys.set_pointer_value(lo, -1);
                keys.set_pointer_value_degree(lo, T);
            }
            mergerChild->keys.set_pointer_value(lo , mergingChild->keys.get_pointer_value(i));
            mergerChild->keys.set_pointer_value_degree(lo , mergingChild->keys.get_pointer_value_degree(i));
        }
        //If The 'mergerChild' Is Not Leaf Then It Is Certain That 'mergingChild' Will Also Not
        //Be A Leaf ANd We Have To Copy The Children Of 'mergingChild' Into 'mergerChild'
        if(mergerChild->isLeaf == false)
        {
            for(int i = 0; i <= mergingChild->numberOfKeys; i++)
                mergerChild->Children[i + minimumKeys] = mergingChild->Children[i];
        } 
        //Filling The Gap Created By Moving The Keys
        for(int i = index + 1; i <= numberOfKeys; i++)
        {
            int loc = i - 1;
            keys.set_pointer_value(loc , keys.get_pointer_value(i));
            keys.set_pointer_value_degree(loc , keys.get_pointer_value_degree(i));
        }
        for(int i = index + 2; i <= numberOfKeys; i++)
        {
            Children[i - 1] = Children[i];
        }
        mergerChild->numberOfKeys += mergingChild->numberOfKeys + 1;
        numberOfKeys--;
        //Deleting The mergingChild
        delete(mergingChild);
        return;
    }
    friend class t_b_tree;
};