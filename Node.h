
#include <iostream>

template<typename T>
class Node{
public:
    Node<T>* left;
    Node<T>* right;
    Node(T key){
        this->key=key;
        this->left=nullptr;
        this->right=nullptr;
    }
    ~Node()
};


