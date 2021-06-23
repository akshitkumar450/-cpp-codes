  bool isSameTree(TreeNode* p, TreeNode* q) {
    //   if both are null means they have traversed the same path on both trees 
        if(p==NULL and q==NULL){
            return true;
        }
        // if either left or right is not same then false
        if(p==NULL or q==NULL){
            return false;
        }
        // if both values of p and q are not same then they are not same
        if(p->val !=q->val){
            return false;
        }
        bool leftSame=isSameTree(p->left,q->left);
        bool rightSame=isSameTree(p->right,q->right);
        
        return (leftSame and rightSame);
}