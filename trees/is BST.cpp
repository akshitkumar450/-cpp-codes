bool isValidBST(TreeNode* root) {
    return helper(root);
}

bool helper(TreeNode*root,int min=INT_MIN,int max=INT_MAX){
    
        if(root==NULL){
        return true;
    }
    // on left min value remains same and max will update to root data
    bool leftBST=helper(root->left,min,root->val);
    // on right max value remains same and min will update to root data
    bool rightBST=helper(root->right,root->val,max);
    // if right is bst and left is bst and myself is also a bst the true
    if(leftBST and rightBST and root->val > min and root->val<max){
        return true;
    }
    return false;
}