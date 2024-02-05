#include<bits/stdc++.h>
using namespace std;
int piv(int arr[],int left,int right){
    int pivot=arr[left];
    int i=left;
    int j=right;
    while(i<j){
        while(i<=right && arr[i]<=pivot){
            i++;
        }
        while(j>=left && arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[left]);
    return j;
}
void quicksort(int arr[],int left,int right){
    if(left<right){
        int partition=piv(arr, left, right);
        quicksort(arr,left,partition-1);
        quicksort(arr,partition+1,right);
    }
}
int main(){
     int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int left=0;
    int right=n-1;
    quicksort(arr,left,right);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}