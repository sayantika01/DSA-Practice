#include<bits/stdc++.h>
using namespace std;
int fib(int n,int a=1,int b=1){
    if(n==1)
        return a;
    return fib(n-1,b,(a+b));  
}
int fact(int n,int res=1){
    if(n==0)
        return res;
    return fact(n-1,n*res);
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int a,b;
    // fib(n,a,b);
    cout<<"The fibonacci series is: "<<fib(n)<<endl;
    cout<<"The factorial of"<<n<<" is:" <<fact(n);
    
    
    
    return 0;
}