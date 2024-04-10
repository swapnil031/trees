#include<stdio.h>
struct BSTnode{
    int data;
    struct BSTnode *left;
    struct BSTnode *right;
};
struct BSTnode *root;
*root=NULL;
struct BSTnode *getnewnode(int data){
    struct BSTnode *new_node=(struct BSTnode*)malloc(sizeof(struct BSTnode));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
};
void preordertraversal(struct BSTnode *root){
    if(root){
    printf("%d",root->data);
    preordertraversal(root->left);
    preordertraversal(root->right);
    }
}

struct BSTnode *insert(int data){
    if(root==NULL){
        root=getnewnode(data);
        return;
    }
    else if(data<=root->data){
        root->left=insert(data);
    }
    else{
        root->right=insert(data);
    }
}
int main(){
    struct BSTnode *B=getnewnode(5);
    insert(1);
    insert(2);
    preordertraversal(B);

}
