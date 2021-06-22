bool isValidBST(TreeNode* root) {
    return helper(root);
}

bool helper(TreeNode*root,int min=INT_MIN,int max=INT_MAX){
    
        if(root==NULL){
        return true;
    }
    bool leftBST=helper(root->left,min,root->val);
    bool rightBST=helper(root->right,root->val,max);
    
    if(leftBST and rightBST and root->val > min and root->val<max){
        return true;
    }
    return false;
}