//Lab 6:Task 2:Binary Search Tree

#include<iostream>
using namespace std;

struct Node{
    int value; //store node value
    Node* left=NULL; //pointer to left child
    Node* right=NULL; //pointer to right child
};

//Insertion using BTS rule(compare then decide left or right)
Node*functionInsert(Node* root,int newValue){
    Node* newNode=new Node();
    newNode->value=newValue;
    newNode->left=NULL;
    newNode->right=NULL;

    if(root==NULL){  //new node become root if tree is empty
        return newNode;
    }
    Node*current=root;
    Node*parent=NULL;

    //find the correct position for new node
    while(current !=NULL){
        parent=current;
        //go to  left if new value is smaller
        if(newValue <current->value){
            current=current->left;
        }
        //otherwise,go to right
        else{
            current=current->right; 
        }
    }

    //insert new node into its position
    if(newValue < parent->value){
        parent->left=newNode;
    }else{
        parent->right=newNode;
    }
    return root;
}

//Inorder Traversal(print BST in ascending order)
void inorderTraversal(Node*root){
    if(root==NULL) return; //stop if node is empty
    inorderTraversal(root->left);
    cout<<root->value<<" ";
    inorderTraversal(root->right);
}

int main(){
    Node* root=NULL;//start with an empty tree

    root=functionInsert(root,30);
    root=functionInsert(root,15);
    root=functionInsert(root,45);
    root=functionInsert(root,11);
    root=functionInsert(root,20);
    
    cout<<"Inorder(sorted ascending): ";
    inorderTraversal(root);
    cout<<endl;

    return 0;
}
