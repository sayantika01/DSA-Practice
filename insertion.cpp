#include<bits/stdc++.h>
using namespace std;
void insertion(int a[],int n){
    int c=0;
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        cout<<"Swap "<<++c<<": ";
            for(int j=0;j<n;j++){
                cout<<a[j]<<" ";
            }
            cout<<endl;
        a[++j]=key;
    }
}
void printing(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int a[]={2,4,98,1,45,55,3};
    int n=7;
    insertion(a,n);
    printing(a,n);
    return 0;
}