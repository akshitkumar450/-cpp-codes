class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
         int ptr=0;
       TreeNode*ans= helper(pre,pre.size(),INT_MIN,INT_MAX,ptr);
        return ans;
    }
    
    TreeNode* helper(vector<int> pre,int n,int min,int max,int &ptr){
        // if the index > size of pre
        // base
       if(ptr >= n){
           return NULL;
       };
    //  if value is out of range
        if(pre[ptr]<min or pre[ptr]>max) 
            return NULL;
    //  if we are here means key in in the range
            // make the root
        TreeNode*root=new TreeNode(pre[ptr]);
        int data=pre[ptr];
        ptr++;
        // for left min value remains same and max value changes to root data
        root->left=helper(pre,n,min,data,ptr);
        // for right max value remains same and min value changes to root data
        root->right=helper(pre,n,data,max,ptr);
        return root;
}
};