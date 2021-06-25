class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    
    void inorder(Node *root,vector<int>&v){
        if(root==NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    
    void mergeHelper(vector<int>v1,vector<int>v2,vector<int>&v3){
        int n1=v1.size();
        int n2=v1.size();
        int i=0,j=0;
        while(i<n1 and j<n2){
            if(v1[i]<v2[j]){
                v3.push_back(v1[i]);
                i++;
            } else{
                v3.push_back(v2[j]);
                j++;
            }
        }
        while(i<n1){
           v3.push_back(v1[i]);
                i++; 
        }
        while(j<n2){
               v3.push_back(v2[j]);
                j++;
        }
    }
// Time Complexity: O(n1+n2)
// Space Complexity: O(n1+n2) 
    vector<int> merge(Node *root1, Node *root2)
    {   
        // store the inorder of both trees and then do merge them
       vector<int>v1,v2,v3;
       inorder(root1,v1);
       inorder(root2,v2);
       mergeHelper(v1,v2,v3);
       return v3;
    }
    
    
};