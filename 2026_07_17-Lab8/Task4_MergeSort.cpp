//Lab 8:Task 4:Merge Sort

#include<iostream>
using namespace std;

void merge(int arr[],int left,int mid,int right){
    int n1=mid-left+1; //claculate number of elements of left half
    int n2=right-mid; //calculate number of elements of right half

    // create temporary arrays to store the left and right halves
    int*L=new int[n1];
    int*R=new int[n2];

    //copy the lft half into array L
    for(int i=0;i<n1;i++){
        L[i]=arr[left+1];
    }
    //copy the right half into array R
    for(int j=0;j<n2;j++){
        R[j]=arr[mid+1+j];
    }
    //i is index for array L
    int i=0;
    //j is index for array R
    int j=0;
    //k is the index for the original array
    int k=left;

    //comoare elements from both arrays
    //copy smaller value into original array
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){       
            arr[k]=L[i];
            i++;
        } 
        //otherwise,copy the right value
        else{
            arr[k]=R[j];
            j++;
        }
        //Move to the next position in the original array
        k++;
    }
    // one half ran out; copy the remaining from the other
    // (only one of these two loops will actually run)

    //copy any remaining elements from L
    while(i<n1){ 
        arr[k]=L[i]; i++; k++;
     }
    //copy any remaining elements from R
    while(j<n2){
         arr[k]=R[j]; j++; k++;
     }
    // free the temp arrays, we used new
    delete[] L;   
    delete[] R;
}
// MergeSort: keep dividing the array into samller halves,
// then merge tham back in sorted order.
void mergeSort(int arr[],int left,int right){
    // base case: 0 or 1 element is already sorted
    if(left>=right) 
        return;   

    int mid=left+(right-left)/2;   // find the middle index

    mergeSort(arr,left,mid);        // sort the left half
    mergeSort(arr,mid+1,right);     // sort the right half
    merge(arr,left,mid,right);      // combine them
}

void displayArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={60,30,20,10,25,15,70};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Before: ";
    displayArray(arr,n);
    mergeSort(arr,0,n-1); // n-1, not n — it's the last index
    cout<<"After:  ";
    displayArray(arr,n);
    return 0;
}