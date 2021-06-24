void helper(struct Node *root, int k,vector<int>&v){
    if(!root){
        return ;
    }
    // means we have founded the node 
    if(k==0){
        v.push_back(root->data);
        // no need to check for its chilren bcz we have found the node at k dist
        return;
    }
    helper(root->left,k-1,v);
    helper(root->right,k-1,v);
    
}

vector<int> Kdistance(struct Node *root, int k)
{
  vector<int>v;
    helper(root,k,v);
    return v;
}