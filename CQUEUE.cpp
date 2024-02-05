#include<iostream>
using namespace std;
#define MAX_SIZE 5
class queue{
    public:
    int rear, front;
    int a[MAX_SIZE];
    queue(){
        rear=-1;
        front=0;
    }
    bool isEmpty(){
        if(rear==-1)
            return true;
        return false;
    }
    bool isFull(){
        if(front==MAX_SIZE-1)
            return true;
        return false;
    }
    void add(int v){
        if(isFull())
            cout<<"Overflow"<<endl;
        else{
            if(front==0 && rear==MAX_SIZE-1){
                a[rear]=v;
            }
        }
    }
    void del(){
        if(front==-1){
            cout<<"Underflow"<<endl;
            return;
        }
        int y=a[front];
        if(front==rear){
            front=-1;
            rear=-1;
            //front--;
            //front = (front + 1) % MAX_SIZE;
        }
        else if(front==MAX_SIZE-1)
            front=0;
        else{
            front++;
        }
        cout<<"Element deleted= "<<y<<endl;
    }
    void display(){
        for(int i=front;i<=rear;i++){
            cout<<a[i]<<endl;
        }
    }
};
int main(){
    queue d;
    cout<<"Menu:"<<endl;
	cout<<"1. Insert"<<endl;
	cout<<"2. Delete"<<endl;
	cout<<"3. Display"<<endl;
	int ch;
    int x;
    do{
        cout<<"Enter the choice"<<endl;
	    cin>>ch;
        switch(ch){
            case 1: cout<<"Enter the element: "<<endl;
                    cin>>x;
                    d.add(x);
                    break;
            case 2: d.del();
                    break;
            case 3: d.display();
                    break;
            case 4: cout<<"EXIT "<<endl;
        }
    }
    while(ch!=4);
    return 0;
}
