void helper(Node*root,int minRange ,int maxRange,int &count){
    if(!root){
        return;
    }
    // if in the range count ++
    if(root->data >=minRange and root->data<=maxRange){
        count++;
    }
    // for left
    if(root->data > minRange ){
        helper(root->left,minRange,maxRange,count);
    }
    // for right
    if(root->data< maxRange){
        helper(root->right,minRange,maxRange,count);
    }
}

int getCount(Node *root, int l, int h)
{
  // your code goes here
  int count=0;
  helper(root,l,h,count);
  return count;
}


