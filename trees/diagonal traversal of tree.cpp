vector<int> diagonal(Node *root) {
   vector<int>ans;
    //    used to save the left nodes of the current root node 
    // which will be used for diagonal traversing
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        while(temp){
            //    check if it has left node 
            // if yes push to queue
            if(temp->left)
                q.push(temp->left);
                ans.push_back(temp->data);
                // move right
                temp=temp->right;
        }
    }
    return ans;
}