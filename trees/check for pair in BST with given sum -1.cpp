class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target) {
        if(root==NULL) return 0;
        stack<Node*>s1,s2;
        // push the element from root to leftmost 
        // true for left
        // false for right
        pushElement(root,s1,true);
        // push the element from root to rightmost
        pushElement(root,s2,false);

        while(!s1.empty()  and !s2.empty() and  s1.top()->data < s2.top()->data){
            int x=s1.top()->data;
            int y=s2.top()->data;
            if(x+y == target){
                return 1;
            }
            // if sum is smaller  and then we have to find the element which is just greater than the top element
            // which will be in leftsubtree in right node
            else if(x+y < target){
                Node*temp=s1.top();
                s1.pop();
                pushElement(temp->right,s1,true);
            } else {
                // if sum is greater than we have to find the just smaller element which we will be
                // in the rightsubtree in left node
                 Node*temp=s2.top();
                s2.pop();
                pushElement(temp->left,s2,false);
            }
        }
        return false;
        
    }
    
    void pushElement(struct Node *root,stack<Node*>&s,bool direction){
        // for left
        if(direction){
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
        } else{
            // for right
            while(root!=NULL){
                s.push(root);
                root=root->right;
            }
        }
    }
};