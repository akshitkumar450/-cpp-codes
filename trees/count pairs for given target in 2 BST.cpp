int countPairs(Node* root1, Node* root2, int x)
{
    stack<Node*>s1,s2;
    if(root1==NULL || root2==NULL)
         return  0;
    Node*top1,*top2;
    int count=0;
    while(1){
        // push all the nodes to root to leftmost element (inorder traversal)
        while(root1!=NULL){
            s1.push(root1);
            root1=root1->left;
        }
        // push all nodes from root to rightmost element (reverse inorder traversal)
        while(root2!=NULL){
            s2.push(root2);
            root2=root2->right;
        }
        // any one got empty then break
        if(s1.empty() || s2.empty()){
            break;
        }
        // get the top element from both stacks
        top1=s1.top();
        top2=s2.top();
        // if top matches with target
        // increase the count
        if((top1->data) +(top2->data)==x) {
            count++;
            s1.pop();
            s2.pop();
            root1=top1->right;
            root2=top2->left;
        } else if((top1->data) +(top2->data)<x){
            s1.pop();
            root1=top1->right;
        } else{
            s2.pop();
            root2=top2->left;
        }
    }
    return count;
}