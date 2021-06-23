void display(vector<int>ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

void leafpath(TreeNode*root,vector<int>ans){
    if(root==NULL){
        return;
    }
    // push data when reached to node
    // it also means that we have travelled a valid path from root to leaf so print it
    ans.push_back(root->data);
    if(root->left==NULL and root->right==NULL){
       display(ans);
        return;
    }
    
    leafpath(root->left,ans);
    leafpath(root->right,ans);
}

int main() {
	TreeNode* root=NULL;
	root=build(root);
    vector<int>ans;
    leafpath(root,ans);
	return 0;
}