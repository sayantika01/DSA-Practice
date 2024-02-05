#include<iostream> 
#include<queue> 
using namespace std;
//BST--> Binary Search Tree
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

Node* insertion(Node* root, int data){
    if(root==NULL){
        //creating the first node
        root=new Node(data);
        return root;
    }
    if(root->data>data){
        //insert in the left branch
        root->left=insertion(root->left,data);
    }
    else{
        //insert in the right branch
        root->right=insertion(root->right,data);
    }
    return root;

}
//TAking input from the user
void input(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root=insertion(root,data);
        cin>>data;
    }
}
//Printing of the tree
void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp= q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }  
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }

}

void preOrder(Node* root){
    if(root==NULL)
        return;
    else{
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root){
    if(root==NULL)
        return;
    else{
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

void inOrder(Node* root){
    if(root==NULL)
        return;
    else{
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
Node* Search(Node* root, int target){
    if(root==NULL)
        return NULL;
    if(root->data==target)
        return root;
    if(target> root->data){
        return Search(root->right, target);
    }
    else{
        return Search(root->left, target);
    }
    
}

int MinValue(Node* root){
    Node* temp= root;
    if(temp==NULL)
        return -1;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

int MaxValue(Node* root){
    Node* temp=root;
    if(temp==NULL)
        return -1;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
}
Node* findMin(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* del(Node* root,int delTarget){
    if(root==NULL)
        return NULL;
    else if(root->data<delTarget){
        root->right=del(root->right, delTarget);
    }
    else if(root->data>delTarget){
        root->left=del(root->left, delTarget);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
            
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        Node* temp=findMin(root->right);
        root->data=temp->data;
        root->right=del(root->right,temp->data);

    }
    return root;
}


int main(){
    Node* root=NULL;
    cout<<"Enter the data into the tree: "<<endl;
    input(root);
    cout<<"The Binary Search tree is: "<<endl;
    levelOrderTraversal(root);
    cout<<"PreOrder traversal of BST: "<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"PostOrder traversal of BST: "<<endl;
    postOrder(root);
    cout<<endl;
    cout<<"InOrder traversal of BST: "<<endl;
    inOrder(root);
    cout<<endl;

    int t; //target value
    cout<<"Enter the data to be searched: "<<endl;
    cin>>t;
    bool Ans= Search(root, t);
    cout<<"Is the target value present or not? "<<Ans<<endl;
    cout<<"The minimum value is: "<<MinValue(root)<<endl;
    cout<<"The maximum value is: "<<MaxValue(root)<<endl;

    int d;
    cout<<"Enter the data to be deleted: "<<endl;
    cin>>d;
    del(root,d);
    cout<<"The updated BST is: "<<endl;
    levelOrderTraversal(root);
    return 0;
}