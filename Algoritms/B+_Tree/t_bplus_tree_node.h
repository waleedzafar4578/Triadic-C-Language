#include "../Array/tarray_int.h"
#define ORDER 4
class t_bplus_tree_node
{
    bool isLeaf;
    t_bplus_tree_node** pointer;
    tarray_int keys;
    int size;
public:
    //By Default the order of the tree will be 3
    t_bplus_tree_node()
    {
        keys.create_array(ORDER , L);
        pointer = new t_bplus_tree_node*[ORDER + 1];
    }
    friend class t_bplus_tree;
};