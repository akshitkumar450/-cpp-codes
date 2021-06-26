class Solution
{
public:
    int findMax(Node *root)
    {
        //code here 
          if(!root){
            return 0;
        }
        // max element will be right most node
        while(root->right!=NULL){
            root=root->right;
        }
        return root->data;     
    }

    int findMin(Node *root)
    {
        //code here
          if(!root){
            return 0;
        }
        // min element will be left most node
        while(root->left!=NULL){
            root=root->left;
        }
        return root->data;
    }
};