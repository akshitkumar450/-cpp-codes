TreeDetail LargestBstInBinaryTree(TreeNode* root){
    TreeDetail val;
    if(root==NULL){
        val.bst=true;
        val.size=0;
        val.min=INT_MAX;
        val.max=INT_MIN;
        return val;
    }
    
    TreeDetail leftDetail=LargestBstInBinaryTree(root->left);
    TreeDetail rightDetail=LargestBstInBinaryTree(root->right);
    
    if(leftDetail.bst==false or rightDetail.bst==false or root->data < leftDetail.max or root->data > rightDetail.min){
        // if here means i am not bst
        val.bst=false;
        // if i am not a bst(from root itself) ,then we will find max size from left and right
        val.size=max(leftDetail.size ,rightDetail.size);
        return val;
    }
    // if here measn a BST
    val.bst=true;
    val.size=leftDetail.size+rightDetail.size+1;
    
    int minValue;
    if(root->left==NULL){
        minValue=root->data;
    } else{
        minValue=leftDetail.min;
    }
    
    int maxValue;
    if(root->right==NULL){
        maxValue=root->data;
    } else{
        maxValue=rightDetail.max;
    }
    
    val.min=minValue;
    val.max=maxValue;
    return val;
}
