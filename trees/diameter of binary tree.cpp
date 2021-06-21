int height(TreeNode*root){
        if(root==NULL){ // for a single node its height is -1
            return -1;  
        }

        int leftHt=height(root->left);
        int rightHt=height(root->right);
        int height=max(leftHt,rightHt)+1;
        return height;
}

    // diameter is taken through edges
int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0; // with no node there will be no diameter(bcz no edges)

    int leftDia=diameterOfBinaryTree(root->left); // diameter in left tree
    int rightDia=diameterOfBinaryTree(root->right);// diameter in right tree

    // diameter passing through root 
    int leftHt=height(root->left);
    int rightHt=height(root->right);
    int myHt=leftHt+ rightHt+2;
    // max of all diameter
    int myDia=max(myHt,max(leftDia,rightDia));
    return myDia;
}