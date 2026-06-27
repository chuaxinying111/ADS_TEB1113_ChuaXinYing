//Lab 5 : Task 2 : Stack Array
#include<iostream>
#include<string>
using namespace std;

const int SIZE=5;
string stack[SIZE];
int top =-1; //means stack is empty

//PERFORM DISPLAY
void display(){
    if(top == -1){
        cout<<"Stack is empty"<<endl;
        return;
    }
    for(int i = top; i >= 0; i--){  
        cout<<stack[i]<<endl;
    }
}

//PERFORM INSERTION(Push)
void push(string name){
    if(top==SIZE-1){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    top++; //move the top up
    stack[top]=name; //insert at top
    cout<<"*********************"<<endl;
    cout<<"Pushed: "<<name<<endl;
    cout<<"*********************"<<endl;
    return;
}

//PERFORM DELETION(Pop)
void pop(){
    if(top==-1){ //check if the stack is empty
        cout<<"Stack Underflow"<<endl;
        return;
    }
    cout<<"*********************"<<endl;
    cout<<"Popped: "<<stack[top]<<endl;
    cout<<"*********************"<<endl;
    top--; //move the top down
}

int main(){
    //Push the names
    string name1="Ali";
    string name2="Ben";
    string name3="Chua";
    string name4="Dania";

    push(name1); //Insert at first->bottom
    push(name2);
    push(name3);
    push(name4); //Insert at last->top

    cout<<"---Original Stack ---"<<endl;
    display();

    push("Zara");
    cout<<"--- After Pushing ---"<<endl;
    display();

    pop();
    cout<<"--- After Popping ---"<<endl;
    display();
}