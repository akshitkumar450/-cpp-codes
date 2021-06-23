 void leftViewhelper(Node*root,int level,int &firstTime,vector<int>&res){
        if(root==NULL){
            return ;
        }
        // if we are any level for the first time means it will be included in our answer
        if(level==firstTime){
            res.push_back(root->data);
            firstTime++;
        }
        
        // call for right first and then for left
        leftViewhelper(root->left,level+1,firstTime,res);
        leftViewhelper(root->right,level+1,firstTime,res);
}
vector<int> leftView(Node *root)
{
        vector<int>res;
        int firstTime=0;
        leftViewhelper(root,0,firstTime,res);
        return res;
}