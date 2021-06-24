#include <iostream>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        
    TreeNode(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

TreeNode* build(TreeNode*root,int data){
    if(root==NULL){
        root=new TreeNode(data);
        return root;
    }
    if(data >root->data){
        root->right=build(root->right,data);
    } else{
        root->left=build(root->left,data);
    }
    return root;
}

TreeNode* insert(TreeNode*root){
    int data;
    cin>>data;
    
    while(data!=-1){
        root=build(root,data);
        cin>>data;
    }
    return root;
}
// L N R
void inOrder(TreeNode* root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

class listPair{
    public:
    TreeNode*head;
    TreeNode*tail;
};

listPair BSTtoList(TreeNode*root){
    listPair val;
    // if no root node is there
    if(root==NULL){
        val.head=NULL;
        val.tail=NULL;
        return val;
    }

    // if single root node is there
    if(root->left==NULL and root->right==NULL){
        val.head=root;
        val.tail=root;
        return val;
    }

    // if we have only left
    if(root->left!=NULL and root->right==NULL){
        // go to the left most node make it head
        listPair leftPair=BSTtoList(root->left);
        // connect tail to root
        leftPair.tail->right=root;
        val.head=leftPair.head;
        val.tail=root;
        return val;
    }
    // if we have only right
    if(root->left==NULL and root->right!=NULL){
        // go to the right most node make it tail
        listPair rightPair=BSTtoList(root->right);
        // connect root to head
        root->right=rightPair.head;
        val.head=root;
        val.tail=rightPair.tail;
        return val;
    }
    // if we both have left and right
    if(root->left!=NULL and root->right!=NULL){
        // go to the left most node make it head
        // go to the right most node make it tail
        listPair leftPair=BSTtoList(root->left);
        listPair rightPair=BSTtoList(root->right);

        leftPair.tail->right=root;
        root->right=rightPair.head;
        val.head=leftPair.head;
        val.tail=rightPair.tail;
        return val;
    }
}

int main(){
    TreeNode* root=NULL;
    root=insert(root);
    // inOrder(root);
    listPair p=BSTtoList(root);
    TreeNode*temp=p.head;
    
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}