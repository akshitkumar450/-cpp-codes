vector<int> reverseLevelOrder(Node *root)
{
    // code here
    stack<Node*>st;
    queue<Node*>q;
    vector<int>ans;
    // push the root
    q.push(root);
    while(!q.empty()){
        // take the front 
        Node* f=q.front();
        q.pop();
        // push the front in stack
        st.push(f);
        // push right node first
         if(f->right){
            q.push(f->right);
        }
        // push left node then
        if(f->left){
            q.push(f->left);
        } 
    }
    //at this point stack will have all nodes 
    while(!st.empty()){
        Node* t=st.top();
        //  cout<<t->data<<" ";
        ans.push_back(t->data);
        st.pop();
    }
    return ans;
}