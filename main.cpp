#include <iostream>
#include "Tree.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Tree<int> tree;
    cout<<"Insert new nodes to the binary tree"<<endl;
    tree.Insert_Node(4);
    tree.Insert_Node(5);
    tree.Insert_Node(6);
    tree.Insert_Node(1);
    tree.Insert_Node(2);
    tree.Insert_Node(3);
    cout<<endl<<"Altura: "<<tree.height_tree<<endl;
    cout<<endl<<"Delete node 5"<<endl;
    tree.Remove_Node(5);
    cout << endl<<"In-Order: "<<endl;
    tree.In_order();
    cout <<endl<< "Pre-Order: "<<endl;
    tree.Pre_order();
    cout <<endl<< "\nPost-Order: "<<endl;
    tree.Post_order();

    cout<<endl<<"Imprimir los caminos:"<<endl;
    tree.Shows_Paths;
    
    tree.print_ancestor(4);

    cout<<endl<<"Árbol balanceado: "<<tree.define_is_balanced;
    cout<<endl<<"Delete all tree"<<endl;
    tree.delete_tree;
    

    return 0;
}
