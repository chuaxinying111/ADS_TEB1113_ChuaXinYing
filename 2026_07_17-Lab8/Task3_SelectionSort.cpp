//Lab 8:Task 3:Selection Sort

#include<iostream>
using namespace std;

//Selection sort:find the smallest value in the unsorted part,
//then swap it into the front of that part

void selectionSort(int arr[],int n){
    for (int i=0;i<n-1;i++){
        //assume the first unsorted element is the smallest
        int minIndex=i;

        //scan the rest of the array looking for smaller element
        for(int j=i+1;j<n;j++){
            //if a smaller element is found,
            //update the index of the minimum element
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        //if the smallest element is not already in the correct position,
        //swap it with the first unsorted element
        if(minIndex!=i){
            //store the current element temporarily
            int temp=arr[i];
            //move the smallest element to the correct position
            arr[i]=arr[minIndex];
            //place the original element into its new position
            arr[minIndex]=temp;
        }
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
    int n=sizeof(arr)/sizeof(arr[0]); //calculate the number of elements

    cout<<"Before: ";
    displayArray(arr,n);
    selectionSort(arr,n);
    cout<<"After: ";
    displayArray(arr,n);
    return 0;
}
