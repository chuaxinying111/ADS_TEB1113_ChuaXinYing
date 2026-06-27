//Lab 3:LinkedList
#include<iostream>
#include<string>
using namespace std;

struct Node{
    string name;
    Node*next=NULL; // Pointer to the next node, default is NULL
};

//PERFORM DISPLAY 
void displayList(Node* head){
    // Start from head, move to next node until end of list
    for(Node* current = head; current != NULL; current = current->next){
        cout << current->name << endl;
    }
}

//PERFORM INSERTION
void insertion(Node**head,string name){
    Node*newNode=new Node(); // Create a new node
    newNode->name=name;      // Assign the name to the new node
    newNode->next=NULL;

    if(*head==NULL){ //Check if the list is empty,then new node become head
        *head=newNode;
        return;
    }
    Node* current= *head; //Start from Head
    while(current->next !=NULL){ //Move to last node
        current=current->next;
    }
    current->next=newNode; //insert new node at the end of list
}

//PERFORM DELETION
void deletion(Node**head,string name){
    if(*head==NULL){ //check if the list is empty
        cout<<"The list is empty"<<endl;
        return;
    }

    //When we want to delete head node
    if((*head)->name==name){
        Node* temp= *head;    // Save current head temporarily
        *head = (*head)->next;// Move head to the next node
        delete temp;          // Free the old head from memory
        return;
    }

    Node* current=*head;
    while(current->next !=NULL){
        if(current->next->name==name){  // Check if next node matches the name
            Node*temp=current->next;    // Save the target node temporarily
            current->next=temp->next;   //ignore the target node
            delete temp;
            return;
        }
        current=current->next; //Move to next node
    }
    cout<<"Name not found."<<endl;
}

int main(){
    Node*node1=new Node();
    Node*node2=new Node();
    Node*node3=new Node();
    Node*node4=new Node();
    
    //creating new instance for the object
    node1->name="Ali";
    node2->name="Ben";
    node3->name="Chua";
    node4->name="Dania";
    
    node1->next=node2; 
    node2->next=node3;
    node3->next=node4; 
    
    cout<<"--- Original List ---"<<endl;
    displayList(node1);

    deletion(&node1,"Ben");
    cout<<"--- After Performing Deletion ---"<<endl;
    displayList(node1);

    insertion(&node1,"Ella");
    cout<<"--- After Performing Insertion ---"<<endl;
    displayList(node1);
}    
