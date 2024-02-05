// #include<iostream>
// #include<stdlib.h>
// #define max_size 5
// using namespace std;

// class Stack{
//     private:
//         int size;
//         int a[max_size];
//         int top;

//     public:
//         Stack()
//         {
//             top=-1;
//         }

//         bool isEmpty()
//         {
//             if(top==-1)
//                 return true;
//             else 
//                 return false;
//         }

//         bool isFull()
//         {
//             if(top==max_size-1)
//                 return true;
//             else 
//                 return false;
//         }

//         void push(int n)
//         {
//             if(isFull())
//             {
//                 cout<<"Stack Overflow"<<endl;
//             }
//             else
//             {
//                 a[top+1]=n;
//                 top++;
//             }
//         }

//         void pop()
//         {
//             if(isEmpty())
//             {
//                 cout<<"Stack Underflow"<<endl;
//             }
//             else
//             {
//                 top=top-1;
//                 cout<<"Popped"<<a[top+1]<<endl;
//             }
//         }
//         int peek()
//         {
//             return top;
//         }
//         void display()
//         {
//             for(int i=peek();i>=0;i--)
//             {
//                 cout<<a[i]<<endl;
//             }
//         }
// };

// int main()
// {
//     Stack c;
//     cout<<"MENU:"<<endl;
//     cout<<"1.PUSH"<<endl;  
//     cout<<"2.POP"<<endl;   
//     cout<<"3.PEEK"<<endl;   
//     cout<<"4.DISPLAY"<<endl;   
//     cout<<"5.EXIT"<<endl;   

//     int ch;
//     do
//     {
//         cout<<"Enter the choice: "<<endl;
//         cin>>ch;
//         switch(ch)
//         {
//             case 1: cout<<"Enter the element to be pushed: "<<endl;
//                     int x;
//                     cin>>x;
//                     c.push(x);
//                     break;
//             case 2: c.pop();
//                     break;
//             case 3: cout<<"Top Element: "<<c.peek();
//                     break;
//             case 4: cout<<"STACK: "<<endl;
//                     c.display();
//                     break;
//             case 5: cout<<"EXITED: "<<endl;;
//                     break;
//             default: cout<<"INVALID"<<endl;
//         }
//     }
//     while (ch!=5);
   
    
//     return 0;
// }


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
      int fact(int n)
{
int i = 1, a = 1;
    while (n)
    {
        a = a * i;
        i++;
        n--;
    }
    return a;
}
    int findCatalan(int n) 
    {
        //code here
    stack<  int> s;
      int a = fact(2 * n);
    // cout << a << endl;
      int b = fact(n + 1);
    // cout << b << endl;

      int c = fact(n);
    // cout << c << endl;

      int d = b * c;

    // cout << d << endl;
      int catalan = a / d;
    s.push(catalan);
    return s.top();
    }
    
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends