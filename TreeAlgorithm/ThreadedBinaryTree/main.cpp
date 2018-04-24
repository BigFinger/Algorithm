#include "ThreadedBinaryTree.h"

int main(){
    ThreadedBinaryTree* binaryTree = new ThreadedBinaryTree();
    binaryTree->formLoop();
    binaryTree->inOrderPrint();
    system("PAUSE");
    return 0;
}