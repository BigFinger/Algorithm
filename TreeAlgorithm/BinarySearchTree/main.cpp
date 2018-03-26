#include "BinaryTree.h"

int main(){
    BinaryTree binaryTree;
    binaryTree.insert(7);
    binaryTree.insert(2);
    binaryTree.insert(1);
    binaryTree.insert(1);
    binaryTree.insert(5);
    binaryTree.insert(3);
    binaryTree.insert(6);
    binaryTree.insert(4);
    binaryTree.insert(9);
    binaryTree.insert(8);
    binaryTree.insert(11);
    binaryTree.insert(11);
    binaryTree.insert(10);
    binaryTree.insert(12);
    binaryTree.print();

    Node * p = nullptr;
    cout << ((p = binaryTree.find(2)) ? p->key : -1) << endl;   //  2
    cout << ((p = binaryTree.find(100)) ? p->key : -1) << endl; // -1

    // test "erase"
    binaryTree.erase(2);
    binaryTree.print(); // 1 3 4 5 6 7 8 9 10 11 12
    binaryTree.erase(10);
    binaryTree.erase(9);
    binaryTree.print(); // 1 3 4 5 6 7 8 11 12

    return 0;
}