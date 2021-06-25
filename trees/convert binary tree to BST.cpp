class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void retrieve(Node*root,vector<int>&v){
        if(root==NULL){
            return;
        }
        // retriev the data from the tree in any order and store in a vector
        // we have inorder traversal
        retrieve(root->left,v);
        v.push_back(root->data);
        retrieve(root->right,v);
    }
    
    void change(Node*root,vector<int>&v,int &i){
        if(root==NULL){
            return ;
        }
        // fill the tree from the vector in inorder manner
        change(root->left,v,i);
        root->data=v[i];
        i++;
        change(root->right,v,i);
        
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        if(root==NULL) return NULL;
        vector<int>v;
        retrieve(root,v);
        // sort the data in vector
        sort(v.begin(),v.end());
        int i=0;
        // convert the given tree to BST
        change(root,v,i);
        return root;
    }
};