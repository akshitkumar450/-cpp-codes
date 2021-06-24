class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        // to check for symmetric we have to check the mirror for left and right
        return isMirror(root->left,root->right);
        
    }
    
    bool isMirror(TreeNode* p,TreeNode* q){
        // if both are null then true
        if(p==NULL and q==NULL){
            return true;
        }
        // if any one of the tree is NULL then false
        if(p==NULL or q==NULL){
            return false;
        }
        // check if both tree root values are same or not
        // if same then only check for left and right
        if(p->val!=q->val){
            return false;
        }
        // for mirror we have check for p left and q right and vice versa
        bool leftMirror=isMirror(p->left,q->right);
        bool rightMirror=isMirror(p->right,q->left);
        return (leftMirror and rightMirror);
    }
};