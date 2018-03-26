#include "BinaryTree.h"

BinaryTree::BinaryTree(){
    head = new Node(0);
}

BinaryTree::~BinaryTree(){
    if (head != NULL)
    {
        destroy(head);
        head = NULL;
    }
}

void BinaryTree::insert_real(int key, Node *& node){
    if (node == NULL)
    {
        node = new Node(key);
    }
    else
    {
        if (node->key < key)
        {
            insert_real(key, node->right);
        }
        else if (node->key > key)
        {
            insert_real(key, node->left);
        }
    }
}

Node*& BinaryTree::find_real(int key, Node*& node){
    if (node != NULL)
    {
        if (key == node->key)
        {
            return node;
        }
        else if (key < node->key)
        {
            return find_real(key, node->left);
        }
        else
        {
            return find_real(key, node->right);
        }
    }
    return node;
}

void BinaryTree::destroy(Node* node){
    if (node != NULL)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
        node = NULL;
    }
}

void BinaryTree::in_order(Node* node){
    if (node != NULL)
    {
        in_order(node->left);
        printf("Key : %d\n", node->key);
        in_order(node->right);
    }
}

void BinaryTree::erase(int key){
    Node*& node = find_real(key, head->left);
    if (node != NULL)
    {
        Node* t = node;
        if (t->left != NULL && t->right != NULL)
        {
            Node* y = t;
            Node* x = t->right;
            while (x->left != NULL)
            {
                y = x;
                x = x->left;
            }
            /* 先把x的左右子树安顿好 */
            if (y == t)
            {
                y->right = x->right;
            }
            else
            {
                y->left = x->right;
            }
            /* 把待删除节点t的左右子树安顿好 */
            node = x;
            x->left = t->left;
            x->right = t->right;
        }
        else
        {
            node = t->left ? t->left : t->right;
        }
        delete t;
    }
}

void BinaryTree::print(){
    in_order(head->left);
    printf("\n");
}

void BinaryTree::insert(int key){
    return insert_real(key, head->left);
}

Node* BinaryTree::find(int key){
    return find_real(key, head->left);
}