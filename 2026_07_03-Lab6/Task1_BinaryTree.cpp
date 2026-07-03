//Lab 6:Task 1:Binary Tree

#include<iostream>
using namespace std;

struct Node{ 
    int value; //store node value
    Node* left=NULL; //pointer to left child
    Node* right=NULL; //pointer to right child

};

//create a new node with given value
Node*createNode(int val){
    Node* newNode=new Node();
    newNode->value=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

//Preorder traversal(Root,Left child,Right Child)
void preorderTraversal(Node* root){
    if(root==NULL) return; //stop if node is empty
    cout<<root->value<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//Inorder traversal(Left child,Root,Right child)
void inorderTraversal(Node* root){
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->value<<" ";
    inorderTraversal(root->right);
}

//Postorder traversal(Left child,Right Child,Root)
void postorderTraversal(Node* root){
    if(root==NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->value<<" ";
}

int main(){

    //Create four nodes
    Node* node1=createNode(10);
    Node* node2=createNode(20);
    Node* node3=createNode(30);
    Node* node4=createNode(40);

    //connect them to form tree 
    node1->left=node2; //node 1 is root,node2 is left child
    node1->right=node3; //node 1 is root,node 3 is right child
    node2->left=node4; //node 4 is left child of node 2

    Node*root=node1; //set the root of the tree

    cout<<"Preorder: ";
    preorderTraversal(root);
    cout<<endl;

    cout<<"Inorder: ";
    inorderTraversal(root);
    cout<<endl;

    cout<<"Postorder: ";
    postorderTraversal(root);
    cout<<endl;

    return 0;
}
