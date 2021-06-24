// in postorder 
// right subtree is generated first and then left subtree

Node* PostIn(int in[], int post[],int start,int end,int &postIndex){
        if(start>end){
            return NULL;
        }
    // make the last index of post order as root node
    int data=post[postIndex];
    Node*root=new Node(data);
    int mid;
    for(int i=start;i<=end;i++){
        if(in[i]==data){
            mid=i;
            break;
        }
    }
    // decrease the index in post array
    postIndex--;
    // call for right first 
   root->right= PostIn(in,post,mid+1,end,postIndex);
   root->left= PostIn(in,post,start,mid-1,postIndex);
   return root;
}

Node *buildTree(int in[], int post[], int n) {
    int postIndex=n-1;
   Node*ans= PostIn(in,post,0,n-1,postIndex);
   return ans;  
}
