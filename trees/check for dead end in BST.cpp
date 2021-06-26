void helper(Node*root,int min,int max,bool &flag){
    if(!root) return ;
    // if(flag) return;
    // if leaf node
    if(!root->left and !root->right){
        // condition for dead end
        if(min==max){
            flag=true;
        }
        return;
    }
    helper(root->left,min,root->data-1,flag) ;
    helper(root->right,root->data+1,max,flag);
}
bool isDeadEnd(Node *root)
{   
    // assuming that it does not have dead end
    // bcz if we find only one  condition which can tell that tree is having
    //  dead end we just mark flag true;
    bool flag=false;
     helper(root,1,INT_MAX,flag);
     return flag;
}