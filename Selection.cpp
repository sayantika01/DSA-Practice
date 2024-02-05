#include<bits/stdc++.h>
using namespace std;
void selection(int a[],int n){
    int k=0;
    for(int i=0;i<n;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[mini])
                mini=j;
        }
        swap(a[mini],a[i]);
        cout<<"Swap "<<++k<<":";
        for(int x=0;x<n;x++){
            cout<<a[x]<<" ";
        }
        cout<<endl;
    }
}
void printing(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    // int n;
    // cout<<"Enter the size of the array: ";
    // cin>>n;
    // int arr[n];
    // cout<<"Enter the elements in the array: ";
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    int arr[] = {12, 64, 38, 70, 58, 53}; 
    int n = 6; 
    selection(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

