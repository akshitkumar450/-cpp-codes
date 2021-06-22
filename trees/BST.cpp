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

bool search(TreeNode*root,int key){
    if(root==NULL){
        return false;
    }
    
    if(root->data==key){
        return true;
    }
    
    if(key>root->data){
       return search(root->right,key);
    } else{
    return search(root->left,key);
    }
}

 bool helper(TreeNode*root,int min=INT_MIN,int max=INT_MAX){
        // null tree is always a BST
        if(root==NULL){
            return true;
        }
        // in left call minvalue remains same and max value changed to root
        bool leftBST=helper(root->left,min,root->val);
        // in right call minvalue  changed to root and max remains same
        bool rightBST=helper(root->right,root->val,max);
        // check for BST
        if(leftBST and rightBST and root->val > min and root->val<max){
            return true;
        }
        return false;
}

int main(){
    TreeNode* root=NULL;
    root=insert(root);
    inOrder(root);
}

// 8 5 7 6 3 12 10 14 -1