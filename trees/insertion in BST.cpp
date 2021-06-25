class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* temp=new TreeNode(val);
            return temp;
        }
        if(val>root->val){
           root->right= insertIntoBST(root->right,val);
        } else{
            root->left=insertIntoBST(root->left,val);
        }
        return root;
    }
};