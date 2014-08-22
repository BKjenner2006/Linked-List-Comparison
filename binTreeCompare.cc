//************************************************************************
//Binary Tree Comparison
//Programmed By: Britton Kjenner
//Date: 8/21/2014
//This program builds three binary trees, two identical, and one different.
//It then runs the trees through a comparison function which uses recursion
//to tell wether or not the trees are identical.
//*************************************************************************
#include <iostream>
using namespace std;

struct treeNode{
    int data;
    treeNode* left;
    treeNode* right;
};

//Node insertion function
void insert(treeNode **tree, treeNode *node){
    if(*tree == NULL){//If node is empty, insert
        *tree = node;
    }else if(node->data < (*tree)->data){//insert down the left tree if item is smaller
        insert(&(*tree)->left, node);
    }else if(node->data > (*tree)->data){//insert down the right tree if item is larger
        insert(&(*tree)->right, node);
    }
}

//Comparison function, returns true if trees are identical
bool compare(treeNode* head1, treeNode* head2){
    //If matching NULLs are found, both trees have reached the end of a branch
    if((head1 == NULL) && (head2 == NULL)){
        return true;
    }
    
    //Compare left tree, and right tree
    if(compare(head1->left, head2->left) && compare(head1->right, head2->right))
    {
        //Check the data at the current node
        if(head1->data == head2->data){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }

    
}

int main(){
    int numbers[] = {100, 25, 22, 13, 59, 1, 87, 365, 0, 99};
    int numbers2[] = {100, 25, 22, 13, 59, 2, 87, 365, 0, 99};
    treeNode* tree1 = NULL;
    treeNode* tree2 = NULL;
    treeNode* tree3 = NULL;

    //Build the trees
    for (int i=0; i < 10; i++){
         treeNode *newNode = new treeNode;
         treeNode *newNode2 = new treeNode;
         treeNode *newNode3 = new treeNode;
         newNode->data = numbers[i];
         newNode2->data = numbers[i];
         newNode3->data = numbers2[i];
         insert(&tree1, newNode);
         insert(&tree2, newNode2);
         insert(&tree3, newNode3);
    }

    //compare
    if (compare(tree1, tree2)){
        cout << "Tree 1 and Tree 2 are identical trees!" << endl;
    }else{
        cout << "Tree 1 and Tree 2 are not identical trees!" << endl;
    }

    if (compare(tree1, tree3)){
        cout << "Tree1 and Tree 3 are identical trees!" << endl;
    }else{
        cout << "Tree 1 and Tree 3 are not identical trees!" << endl;
    }

    return 0;
}
