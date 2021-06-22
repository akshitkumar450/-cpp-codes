  int kthSmallest(TreeNode* root, int k) {
        int ans;
        kthHelper(root,k,ans);
        return ans;
    }
    
    void kthHelper(TreeNode*root,int &k,int &ans){
        if(root==NULL)return;
        // just do inorder traversal
        kthHelper(root->left,k,ans);
        k--;
        if(k==0){
            ans=root->val;
        }
        kthHelper(root->right,k,ans);
    }