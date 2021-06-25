class Solution
{
    public:
    int kthLargest(Node *root, int k)
    {
        int ans=-1;
        helper(root,k,ans);
        return ans;
    }
    //  do reverse inorder 
    // call right first and then left
     void helper(Node*root,int& k,int &ans){
         if(!root) return;
         helper(root->right,k,ans);
            k--;
        if(k==0){
            ans=root->data;
            return;
        }
         helper(root->left,k,ans);
    }
};