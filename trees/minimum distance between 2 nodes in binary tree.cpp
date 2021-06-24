Node* lowestCommonAncestor(Node* root, int p, int q) {
        if(root==NULL){
            return NULL;
        }
        
//       if root itself is one of the values
        if(root->data==p or root->data==q){
            return root;
        }
//      if root is not any one of the value call left and right
        
      Node*leftLCA=lowestCommonAncestor(root->left,p,q);
      Node*rightLCA=lowestCommonAncestor(root->right,p,q);
        
//       if we dont get any answer from left and right ,means lca is not there
//       no need to check for root 
//       bcz we have check for root above
        if(leftLCA==NULL and rightLCA==NULL){
            return NULL;
        }
        
//      means we have got answer from left and right both
        if(leftLCA!=NULL and rightLCA!=NULL){
            return root;
        }
//      if we are here means we have got  answer from left or right
        if(leftLCA==NULL){
            return rightLCA;    
        } else{
            return leftLCA;
        }        
    }

int Dist(Node*root,int a,int level){
    if(!root){
        return -1;
    }
    if(root->data==a){
        return level;
    }
    // call left
    int left=Dist(root->left,a,level+1);
    // if we did not find in left call then for right
    if(left==-1){
        int right=Dist(root->right,a,level+1);
        return right;
    }
    return left;
}
    
int findDist(Node* root, int a, int b) {
    // first find the lca of the two given nodes
    Node* lca=lowestCommonAncestor(root,a,b);
    int level=0;
    // then find the distance from lca to first node
    // then find the distance from lca to second node
    int dis1=Dist(lca,a,level);
    int dis2=Dist(lca,b,level);
    // add both the distance
    return dis1+dis2;
}