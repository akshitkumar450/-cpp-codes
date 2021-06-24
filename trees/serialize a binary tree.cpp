// preorder traversal
void serialize(Node*root,vector<int>&v){
    if(root==NULL){
        // whenever we a null we put a marker as -1 
        v.push_back(-1);
        return;
    }
    v.push_back(root->data);
    serialize(root->left,v);
    serialize(root->right,v);
}