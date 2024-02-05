#include<bits/stdc++.h>
using namespace std;
void bubble(int a[],int n){
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
            cout<<"Swap "<<++c<<": ";
            for(int j=0;j<n;j++){
                cout<<a[j]<<" ";
            }
            cout<<endl;
        }
    }
}
void printing(int a[],int n ){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int arr[] = {12, 64, 38, 70, 58, 53}; 
    int n = 6; 
    // quicksort(arr, 0, n - 1); 
    bubble(arr, n);
    return 0;
}