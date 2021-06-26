Node* inPre(Node*root){
    // for inorder predecessor 
    // move one step left and then go extreme right
    Node*temp=root->left;
    while(temp->right){
        temp=temp->right;
    }
    return temp;
}

Node* inSuc(Node*root){
    // for inorder successor go one step right
    // and then extreme left
    Node*temp=root->right;
    while(temp->left){
        temp=temp->left;
    }
    return temp;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    if(root==NULL) return;
    if(key==root->key){
        if(root->left){
            pre=inPre(root);
        }
        if(root->right){
            suc=inSuc(root);
        }
    } else if(key<root->key){
        // store suc while going to left
        suc=root;
        findPreSuc(root->left,pre,suc,key);
    }  else{
        // store pre while going right
        pre=root;
        findPreSuc(root->right,pre,suc,key);
    }
}