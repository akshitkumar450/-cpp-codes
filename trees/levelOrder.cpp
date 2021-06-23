void levelOrder(TreeNode*root){
    queue<TreeNode*>q;
    // push the root node
    q.push(root);
    while(!q.empty()){
        // pop the front node
        TreeNode* node=q.front();
        q.pop();
        // print data of the front
        cout<<node->data<<" ";
        // push the children of the front node which was popped
        if(node->left!=NULL){
            q.push(node->left);
        } 
        if(node->right!=NULL){
            q.push(node->right);
        }
    }
    cout<<endl;
}

// GFG
 vector<int> levelOrder(Node* root) {
    queue<Node*>q;
    vector<int>ans;
    q.push(root);
    while(!q.empty()) {
        Node* node=q.front();
        q.pop();
        // cout<<node->data<<" ";
        ans.push_back(node->data);
        
        if(node->left!=NULL){
            q.push(node->left);
        } 
        if(node->right!=NULL){
            q.push(node->right);
        }
    }
    return ans;
}