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

TreeNode* build(TreeNode* root){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    
    if(root==NULL){
        root=new TreeNode(data);
    }
    root->left=build(root->left);
    root->right=build(root->right);
    return root;
}

// N L R 
void preorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// L N R
void inOrder(TreeNode* root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

// L R N
void postOrder(TreeNode* root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int countNodes(TreeNode*root){
    if(root==NULL) return 0;
    
    int leftCnt=countNodes(root->left);
    int rightCnt=countNodes(root->right);
    int total=leftCnt+rightCnt+1;
    return total;
}

int sumOfNodes(TreeNode* root){
    
    if(root==NULL){
        return 0;
    }
    
    int leftSum=sumOfNodes(root->left);
    int rightSum=sumOfNodes(root->right);
    int total=leftSum+ rightSum+root->data;
    return total;
}

bool search(TreeNode* root,int key){
    if(root==NULL) return false;
    
    if(root->data==key) return true;
    
    bool left=search(root->left,key);
    bool right=search(root->right,key);
    if(left or right) return true;
    else return false;
}

int height(TreeNode*root){
    if(root==NULL){ // for a single node its height is -1
        return -1;  
    }
    
    int leftHt=height(root->left);
    int rightHt=height(root->right);
    int height=max(leftHt,rightHt)+1;
    return height;
}


int diameter(TreeNode* root){
    if(root==NULL) return 0;
    
    int leftDia=diameter(root->left);
    int rightDia=diameter(root->right);
    
    int leftHt=height(root->left);
    int rightHt=height(root->right);
    int myHt=leftHt+ rightHt+2;
    
    int myDia=max(myHt,max(leftDia,rightDia));
    return myDia;
}

int main() {
	TreeNode* root=NULL;
	root=build(root);
    // preorder(root);
    // inOrder(root);
    // cout<<countNodes(root);
    // cout<<sumOfNodes(root);
    // cout<<search(root,1000);
    // cout<<height(root);
    cout<<diameter(root);
	return 0;
}