class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
     vector<int>v;
     inorder(root,v);
     bool flag=false;
     int n=v.size();
     int i=0,j=n-1;
     while(i<j){
         if((v[i]+v[j])==target){
             i++;
             j--;
           flag=true;
         } else if((v[i]+v[j])<target){
             i++;
         } else{
             j--;
         }
     }
      return flag?1:0;
    }
    
    // store the inorder the sorted array and use 2 pointer approach to find the given sum
    void inorder(struct Node *root,vector<int>&v){
        if(root==NULL)
            return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
};