class Solution{
  public:
    // Return the Kth smallest element in the given BST 
    int KthSmallestElement(Node *root, int k)
    {
        int counter=1; // to check for the counter
        int ans=-1; //to store the answer
        inorder(root,counter,k,ans);
        return ans;
    }

    // O(K) TC
    // do a inorder traversal
      void inorder(Node*root,int &counter,int k,int &ans){
         if(!root) return;
         inorder(root->left,counter,k,ans);
         if(counter==k){
             ans=root->data;
             counter++;
             return;
         } else{
             counter++;
         }
         inorder(root->right,counter,k,ans);
    }
};