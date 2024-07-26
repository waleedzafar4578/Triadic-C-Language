// #include "t_Wumpus_World_Agent.h"
#include "Triadic.h"
#include"TTable.h"
#include <fstream>
#include <variant>
int main()
{
   // ifstream fin("Doc.txt");
   /// t_scanfile(fin,obj);
   /// t_print(obj);
   /// fin.close();
   /*
      t_int a,b;
      t_scan(a);
      t_scan(b);
      t_print(tplus_1(a,b));
      t_print(tsub_2(a,b));
      t_print(tmul_3(a,b));
      t_print(tdiv(a,b));
   */

   // tp_int a;
   // tp_int b(12, T, F);

   // t_print(a);
   // a.set_Degree_ptr(T);
   // a.set_pointer(45,T);
   // t_print(a);

   // tstack_int s1(4);
   // t_int a(23 , T);
   // t_int b(12 , L);
   // t_int c(11 , F);
   // scanStack(s1);
   // s1.pop();
   // printStack(s1);

   // Queue Testing
   // tqueue_uint q(3);
   // t_uint a('A' , T);
   // t_uint b('B' , L);
   // t_uint c('C' , F);
   // q.enqueue(a);
   // q.enqueue(b);
   // q.enqueue(c);
   // printQueue(q);
   // q.dequeue();
   // printQueue(q);
   // q.dequeue();
   // q.dequeue();
   // scanQueue(q);
   // printQueue(q);
   // tflinklist_int l;
   // t_print(a);
   // l.t_insert;
   // tnode_int_tree A(a);
   // t_print(A.getData());
   // A.getRight();
   // t_print(A);
   // ttree_int B;
   // cout<<B.isEmpty();
   // B.t_insert(a);
   // B.t_insert(b);
   // tarray_int A1 = B.getArray();
   // tnode_int A;
   // t_print(A.getData());
   // tnode_int B;
   // B = A;
   // t_print(B);
   // tnode_int C(a);
   // t_print(C);
   // tflinklist_int l;
   // l.t_insert(a);
   // l.t_insert(b);
   // t_print(l);

   // tnode_int *obj = new tnode_int(a);
   // tnode_int *obj1 = new tnode_int(b);
   // obj->setNext(obj1);
   //  t_print(*obh);
   // obj = obj->getNext();
   // t_print(*obj);
   // tnode_int b1(T, 23, T);
   // tnode_int b2(T,90,F);
   // b1.next=new tnode_int(b2);
   // tnode_int b3(*b1.next);
   // b1.next=&b2;
   // b2.next=new tnode_int(T,1002,L);
   // t_print(*b1.next->next);

   // ttreenode_uint b5(T, 10, L);
   // ttreenode_uint b4(T, 12, L);
   // ifstream fin("test.txt");
   // t_scanfile(fin,b4);
   // t_print(b4);
   // b4.set_node(T,9023,F);
   // t_print(b4);
   // b4.set_node(b5);
   // t_print(b4);

   // linklist testing

   //    tlink_int l1;
   //    l1.insert_node(b5);
   //    t_print(l1,2);
   //    l1.insert_node(T,40,T);
   //    l1.insert_node(F,80,T);
   //    l1.insert_node(T,70,F);
   //   t_scan(l1);
   //    t_print(l1);
   //    l1.delete_node(2);
   //    t_print(l1);

   // testing of tree
   //  t_tree_int t1;
   //  t1.insert_node(b5);
   //  t1.insert_node(T,40,L);
   //  t1.insert_node(T,140,T);
   //  t1.insert_node(T,240,F);
   //  t_print(t1);

   // tbstree_uint t1;
   // t1.insert_node(b5);
   // t1.insert_node(b4);
   // t1.insert_node(T,40,L);
   // t1.insert_node(T,140,T);
   // t1.insert_node(T,240,F);
   // t1.insert_node(T,5,T);
   // t1.insert_node(T,3,T);
   // t1.delete_node(3);
   // t_print(t1);

   // Red-Black Tree Testing
   //  t1.insert(6);
   //  t1.insert(5);
   //  t1.insert(4);
   //  t1.insert(3);
   //  t1.insert(2);
   //  t1.insert(1);
   //  t1.inorder();

   // Bubble Sort Tewsting
   // ofstream fout;
   // tarray_int a(5, L);
   /*
   int i = 0;
   a.s_indexD(i, L);
   // a.set_pointer_value(i, 5);
   // a.set_pointer_value_degree(i, T);

   i = 1;
   a.s_indexD(i, T);
   a.set_pointer_value(i, 6);
   a.set_pointer_value_degree(i, T);

   i = 2;
   a.s_indexD(i, T);
   a.set_pointer_value(i, 14);
   a.set_pointer_value_degree(i, L);

   i = 3;
   a.s_indexD(i, T);
   a.set_pointer_value(i, 0);
   a.set_pointer_value_degree(i, L);

   i = 4;
   a.s_indexD(i, L);
   // a.set_pointer_value(i, 4);
   // a.set_pointer_value_degree(i, T);

   i = 5;
   a.s_indexD(i, T);
   a.set_pointer_value(i, 11);
   a.set_pointer_value_degree(i, F);

   i = 6;
   a.s_indexD(i, L);
   // a.set_pointer_value(i, 18);
   // a.set_pointer_value_degree(i, L);

   i = 7;
   a.s_indexD(i, T);
   a.set_pointer_value(i, 7);
   a.set_pointer_value_degree(i, T);

   i = 8;
   a.s_indexD(i, T);
   a.set_pointer_value(i, 7);
   a.set_pointer_value_degree(i, L);
   i = 9;
   a.s_indexD(i, L);
   //a.set_pointer_value(i, 0);
   //a.set_pointer_value_degree(i, T);
   */
   //-----------------------------------------------
   /*
  int i = 0;
  a.s_indexD(i, T);
  a.set_pointer_value(i, 6);
  a.set_pointer_value_degree(i, F);

  i = 1;
  a.s_indexD(i, T);
  a.set_pointer_value(i, 5);
  a.set_pointer_value_degree(i, L);

  i = 2;
  a.s_indexD(i, T);
  a.set_pointer_value(i, 4);
  a.set_pointer_value_degree(i, F);

  i = 3;
  a.s_indexD(i, T);
  a.set_pointer_value(i, 3);
  a.set_pointer_value_degree(i, F);

  i = 4;
  a.s_indexD(i, T);
  a.set_pointer_value(i, 2);
  a.set_pointer_value_degree(i, L);

  i = 5;
  a.s_indexD(i, T);
  a.set_pointer_value(i, 1);
  a.set_pointer_value_degree(i, F);

   */
   //-----------------------------------------------
   // /*
   // char Deg;
   // srand(time(0));
   // for (int i = 0; i < 5; i++)
   // {
   //    Degree D;
   //    int Rvalue = rand() % 15;
   //    int t = rand() % 3;
   //    switch (t)
   //    {
   //    case 0:
   //       D = F;
   //       break;
   //    case 1:
   //       D = T;
   //       break;
   //    default:
   //       D = L;
   //       break;
   //    }

   //    a.s_indexD(i, T);
   //    a.set_pointer_value(i, Rvalue);
   //    a.set_pointer_value_degree(i, D);
   // }
   // int t = rand() % 9;
   // a.s_indexD(t, L);
   // t = rand() % 5;
   // a.s_indexD(t, L);
   // t = rand() % 3;
   // a.s_indexD(t, L);
   //*/

   // t_print(a);
   // cout << endl
   //      << "<----------After Sorting------->>>>" << endl;
   // // t_selection_sort_int3(a);
   // tmerge3(a, 10);
   // t_bubblesort_int1(a);
   // t_print(a);
   // t_print(a);
   //t2Darray_int arrh(4,4);
// t2Darray_int* arrh=new t2Darray_int(4,4);
//    arrh->set(1 , 2 , T , 1 , T);
//    arrh->set(2 , 1 , T , 1 , T);
//    arrh->set(2 , 3 , T , 1 , T);
//    arrh->set(3 , 2 , T , 1 , T);
//    arrh->set(3 , 0 , T , 1 , T);
//    arrh->set(0 , 3 , T , 1 , T);
//    tp_int target(0 , T , T);
//    tp_int starting(1 , T , T);
//    t_print(*arrh);
//    t_depthfirstsearch(arrh , target , starting);

//B-Tree Testing

// t_b_tree a(3);
// //Inserting Values Must Be The Values With True Degree
// t_int A1(50 , T);
// t_int A2(80 , T);
// t_int A3(10 , T);
// t_int A4(20 , T);
// t_int A5(60 , T);
// t_int A6(70 , T);
// t_int A7(75 , T);
// t_int A8(90 , T);
// t_int A9(95 , T);
// t_int A10(4 , T);
// t_int A11(5 , T);
// t_int A12(6, T);
// t_int A13(14 , T);
// t_int A14(15 , T);
// t_int A15(16, T);
// t_int A16(23, T);
// t_int A17(27 , T);
// t_int A18(51 , T);
// t_int A19(52 , T);
// t_int A20(64, T);
// t_int A21(65 , T);
// t_int A22(68 , T);
// t_int A23(72, T);
// t_int A24(73 , T);
// t_int A25(77 , T);
// t_int A26(78 , T);
// t_int A27(79 , T);
// t_int A28(81 , T);
// t_int A29(82 , T);
// t_int A30(89 , T);
// t_int A31(92 , T);
// t_int A32(93 , T);
// t_int A33(100 , T);
// t_int A34(110 , T);
// t_int A35(111 , T);
// a.Insert(A1);
// a.Insert(A2);
// a.Insert(A3);
// a.Insert(A4);
// a.Insert(A5);
// a.Insert(A6);
// a.Insert(A7);
// a.Insert(A8);
// a.Insert(A9);
// a.Insert(A10);
// a.Insert(A11);
// a.Insert(A12);
// a.Insert(A13);
// a.Insert(A14);
// a.Insert(A15);
// a.Insert(A16);
// a.Insert(A17);
// a.Insert(A18);
// a.Insert(A19);
// a.Insert(A20);
// a.Insert(A21);
// a.Insert(A22);
// a.Insert(A23);
// a.Insert(A24);
// a.Insert(A25);
// a.Insert(A26);
// a.Insert(A27);
// a.Insert(A28);
// a.Insert(A29);
// a.Insert(A30);
// a.Insert(A31);
// a.Insert(A32);
// a.Insert(A33);
// a.Insert(A34);
// a.Insert(A35);
// cout<<"Taversing: ";
// a.Traversal();
// cout<<endl;
// // if(a.Search(A4) != NULL)
// //    cout<<"Present";
// // else
// //    cout<<"\nNot Present\n";
// // t_int A9(15 , F);
// // if(a.Search(A9) != NULL)
// //    cout<<"Present";
// // else
// //    cout<<"\nNot Present\n"; 
// a.Remove(A20);
// cout<<"Traversal After Removing 64"<<endl;
// a.Traversal();
// cout<<endl;
// a.Remove(A16);
// cout<<"Traversal After Removing 23"<<endl;
// a.Traversal();
// cout<<endl;
// a.Remove(A23);
// cout<<"Traversal After Removing 72"<<endl;
// a.Traversal();
// cout<<endl;
// a.Remove(A21);
// cout<<"Traversal After Removing 65"<<endl;
// a.Traversal();
// cout<<endl;
// a.Remove(A4);
// cout<<"Traversal After Removing 20"<<endl;
// a.Traversal();
// cout<<endl;
// a.Remove(A6);
// cout<<"Traversal After Removing 70"<<endl;
// a.Traversal();
// cout<<endl;
// a.Remove(A9);
// cout<<"Traversal After Removing 95"<<endl;
// a.Traversal();
// cout<<endl;
// a.Remove(A25);
// cout<<"Traversal After Removing 77"<<endl;
// a.Traversal();
// cout<<endl;
// a.Remove(A2);
// cout<<"Traversal After Removing 80"<<endl;
// a.Traversal();
// cout<<endl;
// a.Remove(A33);
// cout<<"Traversal After Removing 100"<<endl;
// a.Traversal();
// cout<<endl;
// a.Remove(A12);
// cout<<"Traversal After Removing 6"<<endl;
// a.Traversal();
// cout<<endl;
// a.Remove(A17);
// cout<<"Traversal After Removing 27"<<endl;
// a.Traversal();
// cout<<endl;
// a.Remove(A5);
// cout<<"Traversal After Removing 60"<<endl;
// a.Traversal();
// cout<<endl;
// a.Remove(A15);
// cout<<"Traversal After Removing 16"<<endl;
// a.Traversal();
// cout<<endl;
// a.Remove(A1);
// cout<<"Traversal After Removing 50"<<endl;
// a.Traversal();
// cout<<endl;
// if(a.Search(A1) != NULL)
// {
//    cout<<"Present"<<endl;
// }
// else
// {
//    cout<<"Not Present"<<endl;
// }
// a.Insert(A1);
// cout<<"After Inserting 50"<<endl;
// a.Traversal();
// cout<<endl;
// if(a.Search(A1) != NULL)
// {
//    cout<<"Present"<<endl;
// }
// else
// {
//    cout<<"Not Present"<<endl;
// }

//B+ Tree Testing

// t_bplus_tree a;
// t_int A1(20 , T);
// t_int A2(7 , T);
// t_int A3(17 , T);
// t_int A4(25 , T);
// t_int A5(31 , T);
// t_int A6(21 , T);
// t_int A7(1 , T);
// t_int A8(4 , T);
// t_int A9(10 , T);
// t_int A10(19 , T);
// t_int A11(28 , T);
// t_int A12(42 , T);
// a.Insert(A1);
// a.Insert(A2);
// a.Insert(A3);
// a.Insert(A4);
// a.Insert(A5);
// a.Insert(A6);
// a.Insert(A7);
// a.Insert(A8);
// a.Insert(A9);
// a.Insert(A10);
// a.Insert(A11);
// a.Insert(A12);
// a.display(a.getRoot());
// a.Remove(A6);
// cout<<"After Removing 21"<<endl;
// a.display(a.getRoot());
// a.Remove(A5);
// cout<<"After Removing 31"<<endl;
// a.display(a.getRoot());
// a.Remove(A1);
// cout<<"After Removing 20"<<endl;
// a.display(a.getRoot());
// a.Remove(A9);
// cout<<"After Removing 10"<<endl;
// a.display(a.getRoot());
// a.Remove(A2);
// cout<<"After Removing 7"<<endl;
// a.display(a.getRoot());
// a.Remove(A4);
// cout<<"After Removing 25"<<endl;
// a.display(a.getRoot());
// a.Remove(A12);
// cout<<"After Removing 42"<<endl;
// a.display(a.getRoot());


// t_int a(23 , T);
// variant<t_int, t_float>v;
// variant<t_int, t_float>w;
// v = a;
// w = get<t_int>(v);
// if(get_if<t_int>(&v))
// {
//    t_print(get<t_int>(v));
// }
// t_print(get<t_int>(w));
// variant<t_int, t_float> *p;
// p = new variant<t_int , t_float>;
// p = &w;

// t_hnode* ptr = new t_hnode(get<t_int>(v));
// ptr->display();
// return 0;

variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data;
variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data1;
variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data2;
variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data3;
variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data4;
variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data5;
variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data6;
variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data7;
variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data8;

t_bool a(true , T);
t_char b('A' , L);
t_double c(9.445 , T);
t_float d(4.5 , L);
t_int e(3 , T);
t_ldouble f(7.890231 , L);
t_lint g(900000 , T);
t_sint h(-10 , L);
t_uint i(12 , T);

data = a;
data1 = b;
data2 = c;
data3 = d;
data4 = e;
data5 = f;
data6 = g;
data7 = h;
data8 = i;

//Hetrogeneous Link List Testing

// t_hetro_linklist linkL;
// linkL.insert(get<t_bool>(data));
// linkL.insert(get<t_char>(data1));
// linkL.insert(get<t_double>(data2));
// linkL.insert(get<t_float>(data3));
// linkL.insert(get<t_int>(data4));
// linkL.insert(get<t_ldouble>(data5));
// linkL.insert(get<t_lint>(data6));
// linkL.insert(get<t_sint>(data7));
// linkL.insert(get<t_uint>(data8));

// linkL.display();
// cout<<"After Deleting 'A'"<<endl;
// linkL.remove(1);
// linkL.display();
// cout<<"After Deleting 3"<<endl;
// linkL.remove(get<t_int>(data4));
// linkL.display();

//Heterogeneous Stacck Testing
// t_hetro_stack st;
// st.push(get<t_bool>(data));
// st.push(get<t_char>(data1));
// st.push(get<t_double>(data2));
// variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data9 = st.topValue();
// t_print(get<t_double>(data9));
// st.pop();
// variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data10 = st.topValue();
// t_print(get<t_char>(data10));
// st.display();

//Hetrogeneous Queue Testing
// t_hetro_queue Q;
// Q.enqueue(get<t_bool>(data));
// Q.enqueue(get<t_char>(data1));
// Q.display();
// Q.dequeue();
// Q.display();
// Q.dequeue();
// Q.display();
// Q.enqueue(get<t_double>(data2));
// Q.enqueue(get<t_float>(data3));
// Q.enqueue(get<t_int>(data4));
// Q.display();
// variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data9 = Q.frontValue();
// t_print(get<t_double>(data9));
// variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> data10 = Q.rearValue();
// t_print(get<t_int>(data10));

//Variant Array
// variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> arr[5];
// arr[0] = a;
// arr[1] = b;
// arr[2] = c;
// arr[3] = d;
// arr[4] = e;
// t_print(get<t_bool>(arr[0]));

//Hetrogenous Tree Testing
t_int tt(65 , L);
// variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> vtt;
// vtt = tt;
// t_int tt1(2 , F);
// variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> vtt1;
// vtt1 = tt1;
// t_hetro_tree Tree;
// Tree.Insert(get<t_int>(data4));
// Tree.Insert(get<t_int>(vtt));
// Tree.Insert(get<t_int>(vtt1));
// Tree.Display();
// Tree.Deletion(Tree.getRoot() , get<t_int>(vtt));
// Tree.Display();

// variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint> *vtt1;
// vtt1 = new variant<t_int, t_float, t_char, t_bool, t_double, t_ldouble, t_lint, t_sint, t_uint>[2];
// vtt1[0] = tt;
// char var = 98;
// cout<<var<<endl;
// TTable t1;
vector<string> columnNames = {"Name" , "Age" , "Date" , "Month" , "Year"};
// t1.defineColumns(columnNames);
// t1.print();
// TableRow t1;
// for(auto i = columnNames.begin(); i != columnNames.end(); i++)
// {
//    t1.insert(*i);
// }
// t1.printRow();
ofstream outFile;
ifstream myFile;
TTable table1;
table1.defineColumns(columnNames);
table1.addColumn("Star");
columnNames.push_back("Star");
table1.addRow(columnNames);
table1.addRow(columnNames);
table1.addRow(columnNames);
table1.addRow(columnNames);
table1.addRow(columnNames);
table1.addRow(columnNames);
vector<string> da = {"Color" , "Color" , "Color" , "Color" , "Color" , "Color" , "Color"};
table1.addColumn("Color" , da); 
//Error In This Command
// table1.addColumn("Cast");
// table1.print();
table1.printOnFile(outFile , "jd.txt");
table1.readFromFile(myFile , "jd.txt");
}