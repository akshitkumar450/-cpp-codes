Node* LCA(Node *root, int n1, int n2)
{
   if(root==NULL) {
       return NULL;
   }
//    if both are less then root data ,go left
   if(n1<root->data and n2<root->data){
       Node*LcaLeft=LCA(root->left,n1,n2);
       return LcaLeft;
//    if both are greater then root data ,go right
   } else if(n1>root->data and n2>root->data){
       Node*LcaRight=LCA(root->right,n1,n2);
       return LcaRight;
   } else{
    // if we are here means they are different subtress ,
    // in that case root itself is LCA
       return root;
   }
}