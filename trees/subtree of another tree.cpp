class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL){
            return false;
        }
        // if root and subroot is matched return true
        if(isSameTree(root,subRoot)){
            return true;
        }
        // check whether the subroot is found in left part
        bool leftMatch=isSubtree(root->left,subRoot);
        // check whether the subroot is found in right part
        bool rightMatch=isSubtree(root->right,subRoot);
        // return true if found either on left or right part
        return leftMatch or rightMatch;
    }
    
      bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL){
            return true;
        }
        if(p==NULL or q==NULL){
            return false;
        }
        
        if(p->val !=q->val){
            return false;
        }
        bool leftSame=isSameTree(p->left,q->left);
        bool rightSame=isSameTree(p->right,q->right);
        
        return (leftSame and rightSame);
    }
};