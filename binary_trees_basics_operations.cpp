#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
        int value;
        node *right;
        node *left;
    node(int v){
        this->value=v;
        this->left=NULL;
        this->right=NULL;
    }
};

class BST{
    public:
    node* root;
    BST(){
    this->root=NULL;
    }
};
void insert(node* &root,int value){
    node* ptr=new node(value);
    if(root==NULL){
        root=ptr;
    }
    else{
        node *currptr=root;
        node *parentptr=NULL;
        while(currptr!=NULL){
            parentptr=currptr;
            if(value<currptr->value){
                currptr=currptr->left;
            }
            else{
                currptr=currptr->right;
            }
        }
        if(value<parentptr->value){
            ptr=parentptr->left;
        }
        else{
            ptr=parentptr->right;
        }

    }
    cout<<"hello ";
}
void preordertraversal(node* root){
    if(root){
    cout<<root->value<<"->";
    preordertraversal(root->left);
    preordertraversal(root->right);
    }
}

void inordertraversal(node* root){
    if(root){
        inordertraversal(root->left);
        cout<<root->value<<"->";
        inordertraversal(root->right);
    }
}

void postordertraversal(node* root){
    if(root){
        inordertraversal(root->left);
        inordertraversal(root->right);
        cout<<root->value<<"->";
    }
}

// level order traversal

void levelordertraversal(node* root){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int nodes_at_currentlevel=q.size();
        while(nodes_at_currentlevel--){
            node* currnode=q.front();
            q.pop();
            cout<<currnode->value<<" ";
            if(currnode->left){
                q.push(currnode->left);
            }
            if(currnode->right){
                q.push(currnode->right);
            }
        }
        cout<<endl;
    }

}

//depth

int maxdepth(node* root){
    if(root){
        int leftdepth=maxdepth(root->left);
        int rightdepth=maxdepth(root->right);
        return(max(leftdepth,rightdepth)+1);
    }
}


int main(){
    /*node *root=new node(5);
    root->left=new node(6);
    root->right=new node(7);
    root->right->left=new node(8);
   /* cout<<"the preorder traversal is ";
    preordertraversal(root);cout<<"end";
    cout<<endl;
    cout<<"the inorder traversal is ";
    inordertraversal(root);cout<<"end";
    cout<<endl;
    cout<<"the postorder traversal is ";
    postordertraversal(root);cout<<"end";
    cout<<endl;
   cout<<"root is "<<root->data<<endl;
    cout<<"root left child "<<root->left->data<<endl;
    cout<<"root right child "<<root->right->data;;*/
    //levelordertraversal(root);
    /*cout<<root->left<<" ";
    cout<<root->right->left<<" ";
    cout<<max(root->left,root->right->left);*/
    BST t1;
    insert(t1.root,5);
    insert(t1.root,3);
    inordertraversal(t1.root);
}
