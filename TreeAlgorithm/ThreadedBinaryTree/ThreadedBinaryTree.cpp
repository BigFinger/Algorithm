#include "ThreadedBinaryTree.h"

ThreadedBinaryTree::ThreadedBinaryTree(){
    root = NULL;
    head = NULL;
    createTree(root);
}

ThreadedBinaryTree::~ThreadedBinaryTree(){
    if (head != NULL)
    {
        destroyTree(root);
    }
    head = NULL;
}

void ThreadedBinaryTree::createTree(Node* node){
    char temp = 0;
    cin >> temp;
    if (temp != '.')
    {
        node = new Node();
        node->key = temp;
        createTree(node->left);
        createTree(node->right);
    }
}

void ThreadedBinaryTree::destroyTree(Node* node){
    if (node != NULL)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void ThreadedBinaryTree::exploreThreaded(Node* curNode, Node*& preNode){
    if (curNode != NULL)
    {
        exploreThreaded(curNode->left, preNode);
        if (curNode->left == NULL)
        {
            curNode->leftThread = true;
            curNode->left = preNode;
        }
        if (curNode->right == NULL)
        {
            curNode->rightThread = true;
        }
        if (preNode->rightThread)
        {
            preNode->right = curNode;
        }
        preNode = curNode;
        exploreThreaded(curNode->right, preNode);
    }
}

void ThreadedBinaryTree::formLoop(){
    head = new Node();
    head->leftThread = true;
    head->rightThread = true;
    head->left = head->right = head;

    Node* preNode = head;
    exploreThreaded(root, preNode);

    preNode->rightThread = true;
    preNode->right = head;
    head->left = pre;
}