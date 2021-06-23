class Solution {
public:
    vector <int> printBoundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        boundary(root,ans);
        return ans;
    }
    
    void leftBoundary(Node*root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        // we want to traverse the left boundary first  (top down manner)
        if(root->left){
            // save answer then call for left
            ans.push_back(root->data);
            // call for left
            leftBoundary(root->left,ans);
        } else if(root->right){
            // save ans
              ans.push_back(root->data);
            //   call for right
            leftBoundary(root->right,ans);
        }
    }
    
     void rightBoundary(Node*root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(root->right){
            // we want to traverse in bottom up manner
            rightBoundary(root->right,ans);
            ans.push_back(root->data);
        } else if(root->left){
            rightBoundary(root->left,ans);
              ans.push_back(root->data);
        }
    }
    
    void leaves(Node*root,vector<int>&ans){
        if(root==NULL) 
            return;
        // first call for left
        leaves(root->left,ans);
        // if leaf then save it
        if(root->left==NULL and root->right==NULL){
             ans.push_back(root->data);
        }
        // then call for right
        leaves(root->right,ans);
    }
    
    void boundary(Node*root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        // save the root node first 
        ans.push_back(root->data);
        // print left boundary in top down manner
        leftBoundary(root->left,ans);
        // print all leafs
        leaves(root->left,ans);
        leaves(root->right,ans);
        // print right boundary in bottom up manner
        rightBoundary(root->right,ans);
        
    }
    
};
