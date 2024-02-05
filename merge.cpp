#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int left,int mid,int right){
    int i=left;
    int j=mid+1;
    int k=0;
    // int n=sizeof(arr)/sizeof(arr[0]);
    int n=right-left+1;
    int *b=new int[n];
    while(i<=mid && j<=right){
        if(arr[i]>=arr[j]){
            b[k]=arr[j];
            j++;
        }
        else{
            b[k]=arr[i];
            i++;
        }
        k++;
    }
    while (i <= mid) {
        b[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        b[k] = arr[j];
        j++;
        k++;
    }
    // if(i>mid){
    //     while(j<=right){
    //         b[k]=arr[j];
    //         j++;
    //         k++;
    //     }
    // // }
    // // else{
    //     while(i<=mid && j>right){
    //         b[k]=arr[i];
    //         i++;
    //         k++;
    //     }
    // }
    // while(i>mid || j>right){
    //     if(i>mid){
    //         int b[k]=arr[i];
    //         i++;
    //     }
    //     if(j>right){
    //         int b[k]=arr[j];
    //         j++;
    //     }
    // }
    
    for(i=0;i<n;i++){
        arr[i+left]=b[i];

    }

}
void mergesort(int arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
    

}

int main(){
    int arr[] = {1, 54, 35, 89, 13, 20}; 
    int left=0,right=6;
    mergesort(arr,left,right);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// void merge(int arr[], int left, int mid, int right) {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;
//     int L[n1], R[n2];

//     for (int i = 0; i < n1; i++)
//         L[i] = arr[left + i];
//     for (int j = 0; j < n2; j++)
//         R[j] = arr[mid + 1 + j];

//     int i = 0, j = 0, k = left;

//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         } else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }

// void mergesort(int arr[], int left, int right) {
//     if (left < right) {
//         int mid = left + (right - left) / 2;
//         mergesort(arr, left, mid);
//         mergesort(arr, mid + 1, right);
//         merge(arr, left, mid, right);
//     }
// }

// int main() {
//     int arr[] = {1, 54, 35, 89, 13, 20};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int left = 0, right = size - 1;
//     mergesort(arr, left, right);
//     for (int i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }