//Lab 5 : Task 3 : Queue LinkedList
#include<iostream>
#include<string>
using namespace std;

struct Node{
    string name;
    Node*next=NULL;
};

//PERFORM DISPLAY
void displayQueue(Node* front){
    if(front == NULL){ //check is the queue is empty
        cout<<"Queue is empty!"<<endl;
        return;
    }
    for(Node* current = front; current != NULL; current = current->next){
        cout<<current->name<<endl;
    }
}

//PERFORM ENQUEUE (Insert at Back)
void enqueue(Node**front, Node**rear, string name){
    Node*newNode = new Node();  // Create a new node
    newNode->name = name;
    newNode->next = NULL;       

    if(*front == NULL){         //check if queue is empty
        *front = newNode;       //new node becomes both front and rear
        *rear = newNode;
        return;
    }
    (*rear)->next = newNode;    //current rear points to new node
    *rear = newNode;            //new node becomes the new rear
}

//PERFORM DEQUEUE (Delete from Front)
void dequeue(Node**front){
    if(*front == NULL){         //check if queue is empty
        cout<<"Queue is empty!"<<endl;
        return;
    }
    Node*temp = *front;         //save current front temporarily
    *front = (*front)->next;    //move front to next node
    cout<<"*********************"<<endl;
    cout<<"Dequeued: "<<temp->name<<endl;
    cout<<"*********************"<<endl;
    delete temp;                
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

    //link nodes front to back (FIFO order)
    node1->next=node2;  
    node2->next=node3;  
    node3->next=node4;  
    

    Node*front = node1; //first to come out
    Node*rear  = node4; //last to come out

    cout<<"--- Original Queue ---"<<endl;
    displayQueue(front);

    enqueue(&front, &rear, "Zara");
    cout<<"--- After Enqueue ---"<<endl;
    displayQueue(front);

    dequeue(&front);
    cout<<"--- After Dequeue ---"<<endl;
    displayQueue(front);

    dequeue(&front);
    cout<<"--- After Dequeue Again ---"<<endl;
    displayQueue(front);
}
