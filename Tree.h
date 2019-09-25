#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Node.h"

template<typename T>
class Tree{
public:
    Node<T>* root;
    Tree(){
        this->root=nullptr;
    }
    ~Tree(){}
    void Insert_Node(const T& value){
        Node<T>* node= new Node<T>(value);
        if(root==nullptr)
            root= node;
        else{
           Node<T>* temp = root;
            while(temp){
                if (temp->key > _value)
                    if(temp->left)
                        temp = temp->left;
                    else {
                        temp->left = new_node;
                        break;
                    }
                else if (temp->key < _value)
                    if(temp->right)
                        temp = temp->right;
                    else {
                        temp->right = new_node;
                        break;
                    }
                else
                    break;
            }
        }   
    }
    void delete_Node(const T& value){
    }
    Node<T>* min_Node(){
    }
    Node<T>* max_Node(){
    }
    int height_tree(){
        int heigth =0;
        if(root==nullptr){
            return heigth;
        }     
        else
        {
            Node<T>*Temp = root;
            
        }
        
    }
    void Pre_orden(){}
    void In_orden(){}
    void Print_tree(){}
    bool is_balanced(){}




}