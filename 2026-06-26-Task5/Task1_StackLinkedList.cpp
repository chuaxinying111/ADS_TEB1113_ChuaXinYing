//Lab 5 : Task 1: Stack LinkedList
#include<iostream>
#include<string>
using namespace std;

struct Node{
    string name;
    Node*next=NULL;
};
//PERFORM DISPLAY
void display(Node* head){
    for(Node* current = head; current != NULL; current = current->next){
        cout << current->name << endl;
    }
}

//PERFORM INSERTION AT THE FRONT(Push at Front)
void push(Node**head,string name){
    Node*newNode=new Node();//Create a new node
    newNode->name=name;
    newNode->next=*head; //new node point to current head
    *head=newNode; //new node becomes the new head
}

//PERFORM DELETION (From top of the Stack:LIFO)
void pop(Node**head){
    if(*head==NULL){
        cout<<"Empty Stack"<<endl;
        return;
    }
    Node*temp=*head; //save the current top node
    *head=(*head)->next; //move head to next node
    cout<<"*****************************"<<endl;
    cout<<"Popped: "<<temp->name<<endl;
    cout<<"*****************************"<<endl;
    delete temp; //delete the old top node
}
//Perform PEEK
void peek(Node* head){
    if(head == NULL){ //check if the stack is empty
        cout << "Stack is empty" << endl;
        return;
    }
    cout<<"*****************************"<<endl;
    cout << "Top element: " << head->name << endl;
    cout<<"*****************************"<<endl;
}

int main(){
    Node*node1=new Node();
    Node*node2=new Node();
    Node*node3=new Node();
    Node*node4=new Node();
    
    node1->name="Ali";
    node2->name="Ben";
    node3->name="Chua";
    node4->name="Dania";
    
    // reverse the order
    node4->next=node3;  
    node3->next=node2;  
    node2->next=node1;

    Node* head = node4; // head starts at node 4

    cout<<"--- Original Stack ---"<<endl;
    display(head);

    peek(head);

    push(&head,"Zara");
    cout<<"--- After Pushing ---"<<endl; 
    display(head);

    pop(&head);
    cout<<"--- After Popping ----"<<endl;
    display(head);
}