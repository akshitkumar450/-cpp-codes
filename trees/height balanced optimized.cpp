// O(N)

pair<bool,int> heightOptimized(TreeNode*root){
    // first for checking balanced and second for height
    pair<bool,int>val;

    if(root==NULL){
        val.first=true;
        val.second=-1;
        return val;
    }

    pair<bool,int>leftPair=heightOptimized(root->left);
    pair<bool,int>rightPair=heightOptimized(root->right);

    bool leftBalanced=leftPair.first;
    bool rightBalanced=rightPair.first;

    int leftHeight=leftPair.second;
    int rightHeight=rightPair.second;

    if(leftBalanced==false or rightBalanced==false){
        val.first=false;
        return val;
    }

    int myHeight=max(leftHeight,rightHeight)+1;
    val.second=myHeight;
    
    int diff=abs(leftHeight-rightHeight);
    if(diff>1){
        val.first=false;
    } else{
        val.first=true;
    }
    return val;
}