TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        
//       if root itself is one of the values
        if(root==p or root==q){
            return root;
        }
//      if root is not any one of the value call left and right
        
      TreeNode*leftLCA=lowestCommonAncestor(root->left,p,q);
      TreeNode*rightLCA=lowestCommonAncestor(root->right,p,q);
        
//       if we dont get any answer from left and right ,means lca is not there
//       no need to check for root 
//       bcz we have check for root above
        if(leftLCA==NULL and rightLCA==NULL){
            return NULL;
        }
        
//      means we have got answer from left and right both
        if(leftLCA!=NULL and rightLCA!=NULL){
            return root;
        }
//      if we are here means we have got  answer from left or right
        if(leftLCA==NULL){
            return rightLCA;    
        } else{
            return leftLCA;
        }        
    }