class Solution
{
    public:
    bool isSumTree(Node* root){
        // assume it is a sum tree
         bool flag=true;
         solve(root,flag);
         return flag;
    }
    
    int solve(Node*root,bool&flag){
        if(root==NULL){
            return 0;
        }
        // leaf node is a sum tree
        if(root->left==NULL and root->right==NULL){
            return root->data;
        }
        int leftSum=solve(root->left,flag);
        int rightSum=solve(root->right,flag);
        // if at any node does not full fill the condition flag =false
        if(root->data!=leftSum+rightSum){
            flag=false;
        }
        return leftSum+rightSum+root->data;
    }
};