//Lab 4: Doubly Linked List

#include<iostream>
#include<string>

using namespace std;

struct Node{
    string name;
    Node*prev=NULL; //pointer to previous node
    Node*next=NULL; //pointer to next node
};
//Perform Insertion
void functionInsertAtBegining(Node*& head , string newName){
    Node* newNode=new Node(); 
    newNode->name=newName;
    newNode->prev=NULL;
    newNode->next=head; //new node's next->old head

    if(head!=NULL){
        head->prev=newNode;
    }
    head=newNode;
}

void functionInsertAtEnd(Node*& head,string newName){
    Node*newNode=new Node();
    newNode->name=newName;
    newNode->next=NULL; //new node's next =NULL

    if(head==NULL){
        newNode->prev=NULL;
        head=newNode;
        return;
    }
    Node*temp=head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next=newNode; //last node points to new node
    newNode->prev=temp; //new node points back to last node
}

int main(){
    //create new node
    Node*node1=new Node();
    Node*node2=new Node();
    Node*node3=new Node();
    Node*node4=new Node();
        
    node1->name="Ali";
    node2->name="Ben";
    node3->name="Chua";
    node4->name="Dania";
    
    //Foward links
    node1->next=node2;
    node2->next=node3; 
    node3->next=node4; 
    node4->next=NULL; //Dania is last node,no sucessor after it

    //Backward links
    node1->prev=NULL;//Ali is first node,no predecessor  before it
    node2->prev=node1;
    node3->prev=node2;
    node4->prev=node3;

    //Move forward
    cout<<"Forward: ";
    Node* current=node1;
    while(current!=NULL){
        cout<<current->name<<" ";
        current=current->next;
    }
    cout<<endl;

    //Move backward
    cout<<"Backward: ";
    current=node4;
    while(current!=NULL){
        cout<<current->name<<" ";
        current=current->prev;
    }
    cout<<endl;

    return 0;
}
