#pragma once
#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;

    Node(int key){
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree{
public:
    BinaryTree();
    ~BinaryTree();
    void insert(int key);
    Node* find(int key);
    void erase(int key);
    void print();
private:
    void destroy(Node* node);
    void insert_real(int key, Node *& node);
    Node*& find_real(int key, Node *& node);
    void in_order(Node* node);
private:
    Node* head;
};