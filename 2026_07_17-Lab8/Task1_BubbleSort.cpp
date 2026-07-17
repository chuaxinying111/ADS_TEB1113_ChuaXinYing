//Lab 8:Task 1:Bubble Sort

#include <iostream>
using namespace std;

//Bubble sort:repeatedly comapare neighbour elements and swap if out of order
void bubbleSort(int arr[],int n){
    //Outer loop control number of passes
    for(int i =0;i<n-1;i++){

        //flag to check whther any swapping happends in this pass
        //id no swap occurs,the array is already sorted
        bool swapped = false; 

        //Inner loop compares arr[j] and arr[j+1]
        // "- i" because the last i elements are already sorted
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){ // check is it wrong order,if yes swap them
                int temp=arr[j]; // hold the left value
                arr[j]=arr[j+1]; // move right value to the left
                arr[j+1]=temp; // put held value on the right
                swapped=true; // remember the we made the change
            }
        }
        //if no swaps happend,the array is already sorted
        if (! swapped) break; 
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
    int n=sizeof(arr)/sizeof(arr[0]); //calculate number of elements

    cout<<"Before: ";
    displayArray(arr,n);
    bubbleSort(arr,n);
    cout<<"After: ";
    displayArray(arr,n);
    return 0;
}
