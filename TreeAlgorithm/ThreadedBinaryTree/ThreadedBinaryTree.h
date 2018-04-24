#include <iostream>
using namespace std;

struct Node{
    char key;
    Node* left;
    Node* right;
    bool  leftThread;
    bool  rightThread;

    Node(){
        key = 0;
        left = right = NULL;
        leftThread = rightThread = false;
    }
};

class ThreadedBinaryTree {
public:
    ThreadedBinaryTree();
    ~ThreadedBinaryTree();
public:
    void exploreThreaded(Node* curNode, Node*& preNode);
    void formLoop();
    void inOrderPrint();
    Node* getSucceed(Node* node);
    Node* getPercursor(Node* node);
private:
    void createTree(Node** node);
    void destroyTree(Node* node);
private:
    Node* head;
    Node* root;
};