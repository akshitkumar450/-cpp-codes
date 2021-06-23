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

// global variable
int preIndex=0;
TreeNode* buildFromInorderPreOrder(int pre[],int in[],int start,int end){

    if(start>end){
        return NULL;
    }
    // make the root the first data in pre order array
    int data=pre[preIndex];
    TreeNode*root=new TreeNode(data);
    int mid;
    // find the position of the root in inorder array
    for(int i=start;i<=end;i++){
        if(in[i]==data){
            // find the index of the root in inorder array
            mid=i;
            break;
        }
    }

    preIndex++;
    // call for left
    root->left=buildFromInorderPreOrder(pre,in,start,mid-1);
    // call for right
    root->right=buildFromInorderPreOrder(pre,in,mid+1,end);
    return root;
}

int main(){
    TreeNode* root=NULL;
    // root=insert(root);
    int pre[]={4,2,1,3,5,8,7};
    int in[]={1,2,3,4,5,6,7,8};
    int n=7;
    root=buildFromInorderPreOrder(pre,in,0,n-1);
    
}