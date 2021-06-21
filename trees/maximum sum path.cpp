class Solution {
public:
    int maxPathSum(TreeNode* root) {
//         to store the maxVal (ans)
//         a global variable so that it should not make a copy of this at each recursion call and to store the maximum sum in same variable
       int maxVal=INT_MIN; 
        helper(root,maxVal);
        return maxVal;
    }
    
    int helper(TreeNode*root,int &maxVal){
        if(root==NULL){
            return 0;
        }
//         max from left and right
        int leftMax=helper(root->left,maxVal);
        int rightMax=helper(root->right,maxVal);
        
//         to avoid any negative sum from left and right
//         to convert negative to 0
//         convert if we are getting negative value to 0
        leftMax=max(leftMax,0);
        rightMax=max(rightMax,0);
        // to update the maxVal 
        int maxSumPathThroughMe=leftMax+root->val+rightMax;
        maxVal=max(maxVal,maxSumPathThroughMe);
        
//         return max sum to parent
        int maxSumReturnedToParent=max(leftMax+root->val,rightMax+root->val);
        return   maxSumReturnedToParent;
    }
};