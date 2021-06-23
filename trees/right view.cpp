class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        int firstTime=0;
        rightView(root,0,firstTime,res);
        return res;
    }
    
    // level will be available separately for every recursion call
    void rightView(TreeNode*root,int level,int &firstTime,vector<int>&res){
        if(root==NULL){
            return ;
        }
        // if we are any level for the first time means it will be included in our answer
        if(level==firstTime){
            res.push_back(root->val);
            firstTime++;
        }
        
        // call for right first and then for left
        rightView(root->right,level+1,firstTime,res);
        rightView(root->left,level+1,firstTime,res);
    }
};