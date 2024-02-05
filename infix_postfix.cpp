// #include<bits/stdc++.h>
// #define MaxSize 5
// using namespace std;
// class stack{
//     private:
//         int size;
//     public:
//         char a[MaxSize];
//         int top;
//         stack(){
//             top=-1;
//         }
//         bool isEmpty(){
//             if(top==-1)
//                 return true;
//             return false;
//         }
//         bool isFull(){
//             if(top=MaxSize-1)
//                 return true;
//             return false;
//         }
//         void push(char x){
//             if(isFull())
//                 cout<<"Stack Overflow"<<endl;
//             else{
//                 a[top+1]=x;
//                 top++;
//             }
//         }
//         void pop(){
//             if(isEmpty()){
//                 cout<<"Stack Underflow"<<endl;
//             }
//             else{
//                 top--;
//             }
//         }
//         char peek(){
//             return top;
//         }
//         void display(){
//             for(int i=peek();i>=0;i--){
//                 cout<<a[i]<<endl;
//             }
//         }
//         int priority(char s){
//             if(s=='*' || s=='/'){
//                 return 2;
//             }
//             else if(s=='+' || s=='-'){
//                 return 1;
//             }
//             else{
//                 return 0;
//             }
//         }

// };
// int main(){
//     stack st;
//     string str;
//     cout<<"Enter the string: "<<endl;
//     cin>>str;
//     string res;
//     for(int i=0;i<str.length();i++){
//         char s=str[i];
//         if(isalpha(s)){
//             res+=s;
//         }
//         else if(s==')'){
//             st.push(s);
//         }
//         else if(s==')'){
//             while(st.a[st.top]!='('){
//                 res+=st.a[st.top];
//                 st.pop();
//             }
//             st.pop();
//         }
//         else if(s=='+' ||s=='-' ||s=='*'|| s=='/'){
//             while(st.priority(st.a[st.top])>=st.priority(s)){
//                 res+=st.a[st.top];
//                 st.pop();
//             }
//             st.push(s);
//         }
//     }
//     while(st.top!=-1){
//         res+=st.a[st.top];
//         st.pop();
//     }
//     cout<<"Postfix expression is:"<<res<<endl;

//     return 0;
// }

#include<bits/stdc++.h>
#define MaxSize 135
using namespace std;

class Stack {
private:
    int size;
public:
    char a[MaxSize];
    int top;

    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MaxSize - 1);
    }

    void push(char x) {
        if (isFull())
            cout << "Stack Overflow" << endl;
        else {
            a[top + 1] = x;
            top++;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
        }
        else {
            top--;
        }
    }

    char peek() {
        return a[top];
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << a[i] << endl;
        }
    }

    int priority(char s) {
        if (s == '*' || s == '/') {
            return 2;
        }
        else if (s == '+' || s == '-') {
            return 1;
        }
        else {
            return 0;
        }
    }

};

int main() {
    Stack st;
    string str;
    cout << "Enter the string: " << endl;
    str="(a*b*c*d/e/f/g/h+i*j-k*l)*(m*n*o/p/q/r-s*t+u*v/(w*x*y*z))";
    string res;
    for (int i = 0; i < str.length(); i++) {
        char s = str[i];
        if (isalpha(s)) {
            res += s;
        }
        else if (s == '(') {
            st.push(s);
        }
        else if (s == ')') {
            while (st.peek() != '(') {
                res += st.peek();
                st.pop();
            }
            st.pop();
        }
        else if (s == '+' || s == '-' || s == '*' || s == '/') {
            while (!st.isEmpty() && st.priority(st.peek()) >= st.priority(s)) {
                res += st.peek();
                st.pop();
            }
            st.push(s);
        }
    }
    while (!st.isEmpty()) {
        res += st.peek();
        st.pop();
    }
    cout << "Postfix expression is: " << res << endl;

    return 0;
}