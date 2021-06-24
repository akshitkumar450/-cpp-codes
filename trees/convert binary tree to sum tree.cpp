    int solve(Node*root){
        if(root==NULL){
            // this will convert leaf node to 0
            return 0;
        }
        // sum for left tree
        int leftSum=solve(root->left);
        // sum for right tree
        int rightSum=solve(root->right);
        // store the root data
        int rootData=root->data;
        // update the root data with leftsum + rightsum
        root->data=leftSum+rightSum;
        // return leftSum,rightSum and root data to parent
        return  leftSum+rightSum+rootData;
    }
    
    void toSumTree(Node *node)
    {
        solve(node);
    }