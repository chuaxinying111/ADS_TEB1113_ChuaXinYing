//Lab 4: Task 1:  Circular Linked List

#include<iostream>
#include<string>
using namespace std;

struct Node{
    string name;
    Node*next=NULL; 
};

//PERFORM DISPLAY
void display(Node* head){
    if(head == NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    Node* current = head;
    do{
        cout<<current->name<<"-->";
        current = current->next;    //move to next node
    }while(current != head);        //stop when reach head 
    cout<<"(back to "<<head->name<<")"<<endl;
}

//PERFORM INSERTION AT BEGINNING
void insertAtBeginning(Node*& head, string newName){
    Node* newNode = new Node();
    newNode->name = newName;

    if(head == NULL){               //check if list is empty
        newNode->next = newNode;    //point to itself (circular)
        head = newNode;
        return;
    }
    // Find last node (the node that pointing back to head)
    Node* temp = head;
    while(temp->next != head){      //traverse until last node
        temp = temp->next;
    }
    newNode->next = head;           //new node points to current head
    temp->next = newNode;           //last node points to new node
    head = newNode;                 //new node becomes new head
}

//PERFORM INSERTION AT END
void insertAtEnd(Node*& head, string newName){
    Node* newNode = new Node();
    newNode->name = newName;

    if(head == NULL){               //check if list is empty
        newNode->next = newNode;    //point to itself (circular)
        head = newNode;
        return;
    }
    // Find last node (the one pointing back to head)
    Node* temp = head;
    while(temp->next != head){      //traverse until last node
        temp = temp->next;
    }
    temp->next = newNode;           //last node points to new node
    newNode->next = head;           //new node points back to head (circular)
}

//PERFORM DELETION
void deletion(Node*& head, string name){
    if(head == NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    Node* current = head;
    Node* prev = NULL;

    // Find last node first
    Node* last = head;
    while(last->next != head){
        last = last->next;
    }

    // If head node is the one to delete
    if(head->name == name){
        if(head->next == head){     //only one node in list
            delete head;
            head = NULL;
            return;
        }
        last->next = head->next;    //last node points to second node
        Node* temp = head;
        head = head->next;          //move head forward
        delete temp;
        return;
    }

    // Search for the node to delete
    do{
        prev = current;
        current = current->next;
        if(current->name == name){
            prev->next = current->next; //skip the target node
            delete current;
            return;
        }
    }while(current != head);

    cout<<"Name not found."<<endl;
}

int main(){
    Node*node1 = new Node();
    Node*node2 = new Node();
    Node*node3 = new Node();
    Node*node4 = new Node();

    node1->name="Ali";
    node2->name="Ben";
    node3->name="Chua";
    node4->name="Dania";

    // Forward links
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node1;  //last node points back to head (circular)

    Node* head = node1;

    cout<<"--- Original Circular List ---"<<endl;
    display(head);

    insertAtBeginning(head, "Zara");
    cout<<"--- After Insert Zara At Beginning ---"<<endl;
    display(head);

    insertAtEnd(head, "Ella");
    cout<<"--- After Insert Ella At End ---"<<endl;
    display(head);

    deletion(head, "Ben");
    cout<<"--- After Deleting Ben ---"<<endl;
    display(head);
}
