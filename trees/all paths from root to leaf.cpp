public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        string temp="";
        helper(root,v,temp);
        return v;
    }
    
    void helper(TreeNode* root,vector<string>&v,string temp)
    {
        if(root==NULL){
            return;
        }
        temp=temp+to_string(root->val);
        
        if(root->left==NULL and root->right==NULL){
            v.push_back(temp);
        }
        temp+="->";
        helper(root->left,v,temp);
        helper(root->right,v,temp);
    }
};