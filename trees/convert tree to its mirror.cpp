 void mirror(Node* root) {
    if(root==NULL){
        return;
    }
    // swap the left and right pointers
    swap(root->left,root->right);
    // call for left
    mirror(root->left);
    // call for right
    mirror(root->right);
    // no need to return root 
    // bcz after mirroring the tree root will remain the same
}

treenode* mirrorTree(node* root)
{
    // Base Case
    if (root == NULL)
        return root;
    node* t = root->left;
    root->left = root->right;
    root->right = t;
 
    if (root->left)
        mirrorTree(root->left);
    if (root->right)
        mirrorTree(root->right);
   
  return root;
}