// tree is balanced if difference of height of left - right ={-1,0,1}
// O(N^2)
bool heightBalanced(TreeNode* root){
    
    if(root==NULL){
        return true;
    }
    
    bool leftBalanced=heightBalanced(root->left);
    bool rightBalanced=heightBalanced(root->right);
    
    if(leftBalanced==false or rightBalanced==false) {
        return false;
    }
    
    int leftHt=height(root->left);
    int rightHt=height(root->right);
    
    int diff=abs(leftHt-rightHt);
    
    if(diff>1){
        return false;
    }
    return true;
}