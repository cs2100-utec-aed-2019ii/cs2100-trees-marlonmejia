
#include <iostream>

template <typename T>
class Node {
public:
    T key;
    Node<T> *left, *right;

    Node(T key = NULL){
        this->key = key;
        this->left = this->right = nullptr;
    }
    ~Node(){}

};
