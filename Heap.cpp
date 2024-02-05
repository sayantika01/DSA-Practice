#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i){
    int large=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[large])
    {
        large=left;
    }
    if(right<n && arr[right]>arr[large])
    {
        large=right;
    }
    if(large!=i)
    {
        swap(arr[large],arr[i]);
        heapify(arr,n,large);
    }

}
void heapsort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
int main(){
    // int arr[]={12, 64, 38, 70, 58, 53};
    // int n=6;
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    heapsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
