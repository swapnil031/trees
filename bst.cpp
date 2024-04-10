#include<iostream>
using namespace std;

class node{
    public:
        int value;
        node* left;
        node*right;
    node(int v){
        value=v;
        left=right=NULL;
    }
};
class BST{
    public:
    node* root;
    BST(){
        root=NULL;
    }
};

//*TODO Insertion iterative approach

void insert(node* &root,int value){
    node* ptr=new node(value);
    if(root==NULL){
        root=ptr;
        return;
    }
    
        node *currptr=root;
        while(true){
            if(value<currptr->value){
                if(currptr->left==NULL){
                    currptr->left=ptr;
                    return;
                }
                currptr=currptr->left;
            }
            else{
                if(currptr->right==NULL){
                    currptr->right=ptr;
                    return;
                }
                currptr=currptr->right;
            }
        }

    }

//*todo Insertion recursive approach 

node * insertnode(node* &root,int value){
    if(root==NULL){
        node* nodebst=new node(value);
        return nodebst;
    }
    if(value<root->value){
        root->left=insertnode(root->left,value);
    }
    else if(value>root->value){
        root->right=insertnode(root->right,value);
    }
    return root;
}

//*todo Find the smallest

node* findsmallest(node* root){
    if(root==NULL){
        //cout<<"Not Applicable"<<endl;
        return 0;
    }
    node *ptr=root;
    while(ptr->left!=NULL){
        ptr=ptr->left;;
    }
    return ptr;
}

//*todo Deletion of Nodes

node *deletenode(node *root,int val){
    //base case
    if(root==NULL)
        return root;
    if(root->value==val){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child

        //left child
        if(root->left!=NULL && root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left==NULL && root->right!=NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        //2 child

        if(root->left!=NULL && root->right!=NULL){
            node* min=findsmallest(root->right);
            root->value=min->value;
            root->right=deletenode(root->right,min->value);
            return root;
        }

    }
    else if(root->value>val){
        //left tree me jao
        root->left=deletenode(root->left,val);
        return root;
    }
    else{
        //right tree pe jaou
        root->right=deletenode(root->right,val);
        return root;
    }
}

//*todo Inordertraversal

void inordertraversal(node * &root){
    if(root==NULL){
        return;
    }
    inordertraversal(root->left);
    cout<<root->value<<" ";
    inordertraversal(root->right);
}

//*todo Search

bool search(node* &root,int key){
    if(root==NULL){
        return false;
    }
    node *ptr=root;
    while(ptr!=NULL){
        if(key<ptr->value){
            ptr=ptr->left;
        }
        else if(key>ptr->value){
            ptr=ptr->right;
        }
        else{
            return true;
        }
    }
    return false;
}

//*todo Find the largest

void findlargest(node* &root){
    if(root==NULL){
        cout<<"Not Applicable"<<endl;
        return ;
    }
    node *ptr=root;
    while(ptr->right!=NULL){
        ptr=ptr->right;;
    }
    cout<<ptr->value;
}

//*todo Total node

int total_node(node* &root){
    if(root==NULL){
        return 0;
    }
    return(total_node(root->left) + total_node(root->right)+1);
}

//*todo External node

int external_node(node* &root){
    if(root==0){
        return 0;
    }
    else if (root->left==0 && root->right==0){
        return 1;
    }
    else{
        return(external_node(root->left) + external_node(root->right));
    }
}


int main()
{  BST t1;
    int ch,x;
    cout<<"1.Insert"<<endl;
    cout<<"2.Inorder Traversal"<<endl;
    cout<<"3.Preorder Traversal"<<endl;
    cout<<"4.Postorder Traversal"<<endl;
    cout<<"5.Total Node"<<endl;
    cout<<"6.Height"<<endl;
    cout<<"7.Search"<<endl;
    cout<<"8.Find the smallest"<<endl;
    cout<<"9.Find the largest"<<endl;
    cout<<"10.Delete"<<endl;
    cout<<"11.Internal Nodes"<<endl;
    cout<<"12.External Nodes"<<endl;
    cout<<"13.Exit"<<endl;
    do{
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1:cout<<"enter the no you want to insert: ";
                   cin>>x;
                   t1.root=insertnode(t1.root,x);
                   break;
            case 2:inordertraversal(t1.root);
                    break;
            //case 3:
            //case 4:
            case 5:total_node(t1.root);
                    break;
            //case 6:
            case 7:cout<<"enter the no you want to search: ";
                    cin>>x;
                    if(search(t1.root,x)){cout<<"Success";}
                    else{cout<<"Not";}
                    break;
            case 8:findsmallest(t1.root);
                    break;
            case 9:findlargest(t1.root);
                    break;
            case 10:t1.root=deletenode(t1.root,5);
                    break;
            //case 11:
            case 12:external_node(t1.root);
                    break;
            case 13:cout<<"Exit done";
                    break;
            default:cout<<"enter a valid choice";

        }
    }while(ch!=13);
}