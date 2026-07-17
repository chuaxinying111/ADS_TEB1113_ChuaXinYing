//Lab 8:Task 2:Insertion Sort

#include <iostream>
using namespace std;

//Insertion Sort:buld a sorted region on the left,one element at a time
void insertionSort(int arr[],int n){

    //start at index 1 because first element(index 0) is considered sorted
    for(int i=1;i<n;i++){
        int key=arr[i]; //value we insert into the sorted left part
        int j=i-1;      //start comparing from the element just before it

        //move elements that are greater than "key"
        //one position to the right
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j]; //move the larger element to right
            j--; //move the previous element
        }
        //insert the key into its correct position
        arr[j+1]=key;
    }
}
void displayArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={60,30,20,10,25,15,70};
    int n = sizeof(arr) / sizeof(arr[0]); //calculate number of elements 

    cout<<"Before: ";
    displayArray(arr,n);
    insertionSort(arr,n);
    cout<<"After:  ";
    displayArray(arr,n);
    return 0;
}