#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Node.h"
using namespace std;
template<typename T>
class Tree{
public:
    Node<T>* root;
    int n_nodes=0;
    Tree(){
        this->root=nullptr;
    }
    ~Tree(){}
    //Insert Node
    void Insert_Node(const T& value){
        Node<T>* node= new Node<T>(value);
        if(root==nullptr)
            root= node;
        else{
            Node<T>* temp = root;
            while(temp){
                if (temp->key > value){
                    if(temp->left)
                        temp = temp->left;
                    else {
                        temp->left = node;
                        n_nodes++;
                        break;
                    }}
                else if (temp->key < value)
                    if(temp->right)
                        temp = temp->right;
                    else {
                        temp->right = node;
                        n_nodes++;
                        break;
                    }
                else
                    break;
            }}}
    //Delete Node
   
    bool Remove_Node(T data) {
        if (n_nodes > 0) {
            Node<T> **pointer = &root;
            while (*pointer) {
                if (data <= (*pointer)->key) {
                    if ((*pointer)->key == data) {
                        if (!((*pointer)->left))
                            deleteNode(pointer);
                        else
                            swap_Del(pointer);
                        return true;
                    } else
                        pointer = &(*pointer)->left;
                } else
                    pointer = &(*pointer)->right;}
        } return false;
    }
    void delete_Node (Node<T>** pointer, bool right = true) {
        Node<T> *temp = *pointer;
        if (right) *pointer = temp->right;
        else *pointer = temp->left;
        delete temp;
        this->nodes--;
        }

    void swap_Del (Node<T>** pointer) {
        Node<T> *temp = *pointer;        
        pointer = &(*pointer)->left;
        while (*pointer) {
            if (!(*pointer)->right) {
                temp->key = (*pointer)->key;
                if (!(*pointer)->left)
                    delete_Node(pointer);
                else
                    delete_Node(pointer, false);
                return;
                } else
                pointer = &(*pointer)->right;
            }
        }
  
    //Calculate height of a binary tree

    left_direction(Node<T>* temp,int& height,int& cont);
    right_direction(Node<T>* temp,int& height,int& cont);
    int height_tree(){
        int heigth =0;
        if(root==nullptr)
            return 0;  
        else{
            Node<T>* temp=root; 
            int cont=0;
            if(temp->left != nullptr)
                left_direction(temp,heigth,cont);
            if(temp->right != nullptr)
                right_direction(temp,heigth,cont);
        }
    }
    left_direction(Node<T>* temp,int& height,int& cont){
        cont++;
        temp=temp->left;
        if(cont>height)
            height=cont;
        if(temp->left !=nullptr)
            left_direction(temp,height,cont);
        if(temp->right !=nullptr)
            right_direction(temp,height,cont);
    }
    right_direction(Node<T>* temp,int& height,int& cont){
        cont++;
        temp=temp->right;
        if(cont>height)
            height=cont;
        if(temp->left!=nullptr)
            left_direction(temp,height,cont);
        if(temp->right!=nullptr)
            right_direction(temp,height,cont);
    }
    //Delete given Binary Tree
    void delete_right(Node<T>* temp);
    void delete_left(Node<T>* temp);
    void delete_tree(){
        if(root!=nullptr){
            Node<T>* temp=root;
            if(temp->right!=nullptr)
                delete_right(temp);
            if(temp->left!=nullptr)
                delete_left(temp);
        }
    }
    void delete_right(Node<T>* temp){
        temp=temp->right;
        if(temp->left!=nullptr)
            delete_left(temp);
        if(temp->right!=nullptr)
            delete_right(temp);
        delete temp;
    }
    void delete_left(Node<T>* temp){
        temp=temp->left;
        if(temp->left!=nullptr)
            delete_left(temp);
        if(temp->right!=nullptr)
            delete_right(temp);
        delete temp;
    }
    //Pre-order Tree
    void Pre_order(Node<T>* Root){
        if(Root==nullptr)
            Root=root;
        cout<<Root<<"-";
        Pre_order(Root->left);
        Pre_order(Root->right);
    }
    //Post-order
    void Post_order(Node<T>* Root){
        if(Root==nullptr)
            Root==root;
        Post_order(Root->left);
        Post_order(Root->right);
        cout<<root->key<<" - ";
    }
    //In-order Tree 
    void In_order(Node<T>* node){
        if(node==nullptr)
            node=root;
        In_order(Root->left);
        cout<<root->key<<"-";
        In_order(Root->right);
    }

    //Check if given binary tree is complete binary tree or not

    //Print all paths from root to leaf nodes in given binary tree
    void Print_PathsRe(Node<T>* node,int path[],int path_lenght);
    void Print_array(int var[],int lenght);
    void Shows_Paths(){
        if(root!=nullptr){
            T path[1000];
            Print_PathsRe(root,path,0); 
        }
    }
    void Print_PathsRe(Node<T>* node,int path[],int path_lenght){
        if(node==nullptr)
            return;
        path[path_lenght]=node->key;
        path_lenght++;
        if(node->left==nullptr && node->right==nullptr)
            Print_array(path,path_lenght);
        else
        {
            Print_PathsRe(node->left,path,path_lenght);
            Print_PathsRe(node->right,path,path_lenght);
        }
    }
    void Print_array(int var[],int lenght){
        for (int i = 0; i < lenght; i++)
        {
            cout<<var[i]<<"-";
        }
        cout<<endl;
        
    }
    //Find ancestors of given node in a Binary Tree
    bool print_ancestor(T target){
        if(root==nullptr)
            return false;
        if(root->key==target)
            return true;
        if(print_ancestor(root->left,target )|| print_ancestor(root->right,target)){
            cout<<root->key<<"-";
            return true;
        }
        return false;    
    }
    //Check if given binary tree is height balanced or not
    int height_balanced(Node<T>* node, bool& balanced){
        if(node==nullptr)
            return 0;
        int left_height=height_balanced(node->left, balanced);
        int rigth_heigt=height_balanced(node->right, balanced);
        if(abs(left_height-rigth_heigt)>1)
            balanced==false;       
    }
    bool define_is_balanced(Node<T>* root){
        bool balanced=true;
        height_balanced(root,balanced);
    }
    //Determine if given Binary Tree is a BST or not






}