class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool found=false;
         helper(root,targetSum,0,found);
        return found;
    }
    
    void helper(TreeNode*root,int target,int curSum,bool &isfound){
        if(root==NULL){
            return ;
        }
        curSum+=root->val;
        if(root->left==NULL and root->right==NULL and curSum==target){
            isfound=true;
        }
        helper(root->left,target,curSum,isfound);
        helper(root->right,target,curSum,isfound);
        
    }
};