// res is passed by reference bcz we want to have the same vector through call stack
// firstTime also by ref we dont want to create a copy at each recursion call 
void leftViewhelper(Node*root,int level,int &firstTime,vector<int>&res){
        if(root==NULL){
            return ;
        }
        // if we are any level for the first time means it will be included in our answer
        if(level==firstTime){
            res.push_back(root->data);
            firstTime++;
        }
        
        // call for left first and then for right
        leftViewhelper(root->left,level+1,firstTime,res);
        leftViewhelper(root->right,level+1,firstTime,res);
}

vector<int> leftView(Node *root) {
        vector<int>res;  // for storing the leftview
        int firstTime=0;
        leftViewhelper(root,0,firstTime,res);
        return res;
}