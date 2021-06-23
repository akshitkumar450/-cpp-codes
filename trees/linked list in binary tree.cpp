class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        if(root==NULL){
            return false;        
        }
        // first check whether root itself can have the list head
        if(helper(head,root)){
            return true;
        }
        // if not then call for left and right
        bool isSubPathLeft=isSubPath(head,root->left);
        bool isSubPathRight=isSubPath(head,root->right);
        return  isSubPathLeft or  isSubPathRight;
    }
    
    bool helper(ListNode*head,TreeNode*root){
        // if  we have found the complete list in tree 
        // then head will reached to NULL while traversing
        if(head==NULL){
            return true;
        }
        // if root become null before the completely checking the list
        if(root==NULL){
            return false;
        }
        // if the root data not equal to head data
        if(head->val!=root->val){
            return false;
        }
        // if we are here means we have matched the root data and head data
        // then check in left with the sublist of list
        bool leftList=helper(head->next,root->left);
        // then check in left with the sublist of list
        bool rightList=helper(head->next,root->right);
        return leftList or rightList;
        
    }
};