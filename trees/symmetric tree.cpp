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
        
        if(p==NULL and q==NULL){
            return true;
        }
        if(p==NULL or q==NULL){
            return false;
        }
        if(p->val!=q->val){
            return false;
        }
        // for mirror we have check for p left and q right and vice versa
        bool leftMirror=isMirror(p->left,q->right);
        bool rightMirror=isMirror(p->right,q->left);
        return (leftMirror and rightMirror);
    }
};