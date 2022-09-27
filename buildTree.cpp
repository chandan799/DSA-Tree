#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter data: ";
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter data for inserting left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrderTraversal(node* root){
    queue<node*> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        node* temp = Q.front();
        Q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!Q.empty()){
                Q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
            Q.push(temp->left);
            }
            if(temp->right){
                Q.push(temp->right);
            }
        }
    }
}

void preOrderTraversal(node* root){

    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(node* root){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(node* root){
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

node* builtTreeUsingLeveOrder(node* root){
    cout<<"Enter root node: ";
    int data;
    cin>>data;
    root = new node(data);
    queue<node*> Q;
    Q.push(root);
    while(!Q.empty()){
        node* temp = Q.front();
        Q.pop();

        cout<<"Enter left data for "<<temp->data<<" :";
        int leftData;
        cin>>leftData;
        cout<<endl;
        if(leftData!=-1){
            temp->left = new node(leftData);
            Q.push(temp->left);
        }

        cout<<"enter right data for "<<temp->data<<" :";
        int rightData;
        cin>>rightData;
        cout<<endl;
        if(rightData!=-1){
            temp->right = new node(rightData);
            Q.push(temp->right);
        }
    }
    return root;
}

int main(){
    node* root = NULL;
    root = builtTreeUsingLeveOrder(root);
    // root = buildTree(root);
    // cout<<"Level Order traversal: "<<endl;;
    levelOrderTraversal(root);

    // cout<<"Preorder Traversal: "<<endl;
    // preOrderTraversal(root);
    // cout<<endl;

    // cout<<"Inorder Traversal: "<<endl;
    // inOrderTraversal(root);
    // cout<<endl;

    // cout<<"Postorder Traversal: "<<endl;
    // postOrderTraversal(root);

    return 0;
}