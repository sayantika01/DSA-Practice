#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};
int flag=0;
Node* checkBST(Node* root,int data){
    if(root==NULL)
        root=new Node(data);
    if(root->left==NULL && root->right== NULL)
        // cout<<"BST"<<endl;
        flag=1;
    // else if(root->left!=NULL){
    else{
        while(root->left!=NULL){
            if(root->left->data<root->data){
                checkBST(root->left,data);
            }
            else if(root->right->data>data){
                checkBST(root->right,data);
            }
            flag=1;
    }
    // else if(root->right!=NULL){
        while(root->right!=NULL){
            if(root->left->data<root->data){
                checkBST(root->left,data);
            }
            else if(root->right->data>data){
                checkBST(root->right,data);
            }
            flag=1;
        }
    }
    
}
int main(){
    Node* root;
    int data;
    root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(6);
    root->left->left=new Node(2); 
    root->left->right=new Node(4); 
    checkBST(root,data);
    if(flag==1)
        cout<<"BST"<<endl;
    else{
        cout<<"Not BST"<<endl;
    }

    return 0;
}