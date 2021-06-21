
class DiaHeight{
    public:
        int diameter;
        int height;
};

DiaHeight diameterOptimized(TreeNode* root){
        DiaHeight val;
        
        if(root==NULL){
            val.diameter=0;
            val.height=-1;
            return val;
        }
        
       DiaHeight leftPair= diameterOptimized(root->left);
       DiaHeight rightPair= diameterOptimized(root->right);
       
       int leftDia=leftPair.diameter;
       int rightDia=rightPair.diameter;
       
       int leftHt=leftPair.height;
       int rightHt=rightPair.height;
       
       int myDia=leftHt+rightHt+2;
       
       int maxDia=max(myDia,max(leftDia,rightDia));
       val.diameter=maxDia;
       val.height=max(leftHt,rightHt)+1;
        
        return val;
    
}

int main() {
	TreeNode* root=NULL;
	root=build(root);
  
    DiaHeight ans=diameterOptimized(root);
    cout<<ans.diameter;
	return 0;
}