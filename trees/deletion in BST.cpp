class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(key<root->val){
            root->left=deleteNode(root->left,key);
            return root;
        } else if(root->val==key){
            // 3 cases
            // with 0 child
            if(root->left==NULL and root->right==NULL){
                delete root;
                return NULL;
            }
            // with 1 child
            // left child is there
            if(root->left!=NULL and root->right==NULL){
                // store the left pointer and delete the current pointer 
                // and return the stored pointer
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            // right child is there
            if(root->left==NULL and root->right!=NULL){
                // store the right pointer and delete the current pointer
                // and return the stored pointer
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            // 2 child
            //  replace the node with 2 children with inorder successor (min element in right subtree)
            // and then delete that node aswell
            TreeNode* replace=root->right;
            while(replace->left!=NULL){
                replace=replace->left;
            }
            // replace the data of the inorder successor to root data and delete inorder successor
            root->val=replace->val;
            root->right=deleteNode(root->right,replace->val);
            return root;
            
        } else {
            root->right=deleteNode(root->right,key);
            return root;
        }
    }
};