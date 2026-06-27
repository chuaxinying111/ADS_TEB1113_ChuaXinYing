//Lab 5 : Task 4 : Queue Array
#include<iostream>
#include<string>
using namespace std;

const int SIZE = 5;
string queue[SIZE];
int front = -1;  //means queue is empty
int rear  = -1;  //means queue is empty

//PERFORM DISPLAY
void display(){
    if(front == -1){
        cout<<"Queue is empty"<<endl;
        return;
    }
    for(int i = front; i <= rear; i++){  //print from front to rear
        cout<<queue[i]<<endl;
    }
}

//PERFORM ENQUEUE (Insert at Rear)
void enqueue(string name){
    if(rear == SIZE-1){              //check if queue is full
        cout<<"Queue Overflow"<<endl;
        return;
    }
    if(front == -1) front = 0;       //first element,set front to 0
    rear++;                          //move rear up
    queue[rear] = name;              //insert at rear
    cout<<"*****************************"<<endl;
    cout<<"Enqueued: "<<name<<endl;  
    cout<<"*****************************"<<endl;
}

//PERFORM DEQUEUE (Delete from Front)
void dequeue(){
    if(front == -1){                 //check if queue is empty
        cout<<"Queue Underflow!"<<endl;
        return;
    }
    cout<<"*****************************"<<endl;
    cout<<"Dequeued: "<<queue[front]<<endl;
    cout<<"*****************************"<<endl;
    front++;                         //move front up
    if(front > rear){                //if queue becomes empty after dequeue
        front = -1;                  //reset both front and rear
        rear  = -1;
    }
}

int main(){
    // Enqueue 4 names
    string name1 = "Ali";
    string name2 = "Ben";
    string name3 = "Chua";
    string name4 = "Dania";

    enqueue(name1);  //Ali enters first = front
    enqueue(name2);
    enqueue(name3);
    enqueue(name4);  //Dania enters last = rear

    cout<<"--- Original Queue ---"<<endl;
    display();

    enqueue("Zara");
    cout<<"--- After Enqueue Zara ---"<<endl;
    display();

    dequeue();
    cout<<"--- After Dequeue ---"<<endl;
    display();

    dequeue();
    cout<<"--- After Dequeue Again ---"<<endl;
    display();
}