#include<bits/stdc++.h>
using namespace std; 
 
int precedence(char ch) 
{ 
    if (ch == '*' || ch == '/') 
        return 2; 
    if (ch == '+' || ch == '-') 
        return 1; 
    return 0; 
} 
bool isalnum(char ch) 
{ 
    if (ch >= '0' && ch <= '9') 
        return true; 
    if (ch >= 'a' && ch <= 'z') 
        return true; 
    return false; 
} 
int evaluation(string str) 
{ 
    stack<int> s; 
    for (int i = 0; i < str.size(); i++) 
    { 
        char ch = str[i]; 
        if (isalnum(ch)) 
            s.push(ch - '0'); 
        else 
        { 
            int second = s.top(); 
            s.pop(); 
            int first = s.top(); 
            s.pop(); 
            switch (ch) 
            { 
            case '+': 
                s.push(first + second); 
                break; 
            case '-': 
                s.push(first / second); 
                break; 
            case '*': 
                s.push(first * second); 
                break; 
            case '/': 
                s.push(first / second); 
                break; 
            default: 
                cout << "invalid"; 
                return -1; 
            } 
        } 
    } 
    return s.top(); 
} 
class Stack {
private:
    int size;
public:
    char a[100];
    int top;

    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == 100 - 1);
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
 
int main() 
{ 
    string str = "(1+2)*3/3*(5/5*7)+8"; 
    cout << str << endl; 
    string postfix = convert(str); 
    cout << postfix << endl; 
    cout << "value: " << evaluation(postfix); 
    return 0; 
}