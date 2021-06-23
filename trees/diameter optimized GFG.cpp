class diaOpti{
    public:
        int dia;
        int ht;
};
// counting nodes
class Solution {
  public:
    
    diaOpti diameterOpti(Node*root){
        diaOpti val;
        
        if(root==NULL){
            val.dia=0;
            val.ht=0;
            return val;
        }
        
        diaOpti leftPair=diameterOpti(root->left);
        diaOpti rightPair=diameterOpti(root->right);
        
        int leftDia=leftPair.dia;
        int rightDia=rightPair.dia;
        
        int leftHt=leftPair.ht;
        int rightHt=rightPair.ht;
        int myDia=leftHt+rightHt+1;
        
        int maxDia=max(myDia,max(leftDia,rightDia));
        val.dia=maxDia;
        val.ht=max(leftHt,rightHt)+1;
        return val;
    }
    
    int diameter(Node* root) {
        // Your code here
        diaOpti ans=diameterOpti(root);
        return ans.dia;
    }
};