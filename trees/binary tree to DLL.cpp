class Solution {
    public: 
    void solve(Node*root,Node*&head,Node*&prev,int &first){
        if(root==NULL){
            return;
        }
        // do a inorder traversal 
        // left call
        solve(root->left,head,prev,first);
        // for first node in inorder traversal make it head 
        // make first =1 (it is the first node)
        if(first==0){
            // for the first node make it head and prev point to it
            head=root;
            prev=root;
            first=1;
        } else{
            // for every other node
            prev->right=root;
            root->left=prev;
            prev=prev->right;
        }
        // right call
        solve(root->right,head,prev,first);
    }
    
    Node * bToDLL(Node *root)
    {
        // your code here
        Node*head=NULL;
        Node*prev=NULL;
        int first=0;
        solve(root,head,prev,first);
        return head;
    }
};
