#include <iostream>
#include "Node.h"

template<typename T>
class Tree{
public:
    Node<T>* root;
    Tree(){
        this->root=nullptr;
    }
    ~Tree(){}
    void new_Node(const T& value){
        Node<T>* node= new Node<T>(value);
        if(root==nullptr)
            root= node;
        else
        {
            Node<T>* temp = root;

        }
           

    }
    void delete_Node(const T& value){
    }
    Node<T>* min_Node(){
    }
    Node<T>* max_Node(){
    }
    int height_tree(){     
    }
    void Pre_orden(){}
    void In_orden(){}
    void Print_tree(){}
    bool is_balanced(){}




}