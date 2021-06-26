Node* helper(int post[],int size,int min,int max,int &ptr ){
    // base
    if(ptr<0) 
        return NULL;
    // if out of range
    if(post[ptr]<min or post[ptr]>max)
     return NULL;
    //  if we are here means key in in the range
    Node*root=new Node(post[ptr]);
    int data=post[ptr];
    ptr--;
    if(ptr>=0){  // to avoid error (can ignore this)
        // right then left
        // for right max value remains same and min value changes to root data
        root->right=helper(post,size,data,max,ptr);
        // for left min value remains same and max value changes to root data
        root->left=helper(post,size,min,data,ptr);
    }
  
    return root;
}

Node *constructTree (int post[], int size)
{
//code here
    int ptr=size-1;
    Node* ans=helper(post,size,INT_MIN,INT_MAX,ptr);
    return ans;
}
