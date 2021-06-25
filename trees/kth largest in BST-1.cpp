class Solution
{
    public:
    int kthLargest(Node *root, int k)
    {
        int counter=1;
        int ans=-1;
        inorder(root,counter,k,ans);
        return ans;
    }
    // O(K) TC
    // do a reverse inorder traversal
    // call right first and then left
     void inorder(Node*root,int &counter,int k,int &ans){
         if(!root) return;
         inorder(root->right,counter,k,ans);
        
         if(counter==k){
             ans=root->data;
             counter++;
             return;
         } else{
             counter++;
         }
         inorder(root->left,counter,k,ans);
    }
};