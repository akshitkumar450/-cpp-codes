class Solution {
public:
  TreeNode* makeTree(vector<int>& nums,int low, int high) {
        if(low>high) return NULL;
        int mid = (low+high)/2;
        TreeNode *output = new TreeNode(nums[mid]);
        output->left= makeTree(nums,low,mid-1);
        output->right = makeTree(nums,mid+1,high);
        return output;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeTree(nums,0,nums.size()-1);
    }
};