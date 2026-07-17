//Lab 8: Task 5: Quick Sort (first element as pivot)

#include <iostream>
using namespace std;

// partition(): pick a pivot, rearrange the arrsy a pivot
//element smaller than pivot placed on left
//element larger than pivot placed on left
int partition(int arr[],int low,int high){

    int pivot=arr[low];   // choose first element as pivot
    int i=low;            // i = last index of the "smaller than pivot" region
                    

    // start after pivot to skip the pivot itself
    for(int j=low+1;j<=high;j++){

       //if the current element is samller than pivot
       //move to left 
        if(arr[j]<pivot){     
            i++;            //expand left partition  

            //swap arr[i] and arr[j]
            int temp=arr[i];  
            arr[i]=arr[j];
            arr[j]=temp;
        }
        // arr[j]>=pivot -> leave it, j moves on
    }

    //place pivot between left and right partitions
    int temp=arr[low];
    arr[low]=arr[i];
    arr[i]=temp;

    return i;   // return pivot's final position
}

void quickSort(int arr[],int low,int high){

    if(low>=high) return;   // base case: 0 or 1 element is already sorted

    int p=partition(arr,low,high);   // partition the array and get the pivot index

    quickSort(arr,low,p-1);     // sort the left side
    quickSort(arr,p+1,high);    // sort the right side
}

void displayArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={60,30,20,10,25,15,70};
    int n = sizeof(arr) / sizeof(arr[0]); //calculate the number of elements

    cout<<"Before: ";displayArray(arr,n);
    quickSort(arr,0,n-1);
    cout<<"After:  ";displayArray(arr,n);
    return 0;
}