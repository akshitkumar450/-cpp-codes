class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n) {
        // Code here
        Node* ans=buildFromInorderPreOrder(pre,in,0,n-1);
        return ans;
    }
    // global variable
    // we dont want to change it through our traversal
    int preIndex=0;
    Node* buildFromInorderPreOrder(int pre[],int in[],int start,int end){
        // base case
        if(start>end){
            return NULL;
        }
        // make the root the first data in pre order array
        int data=pre[preIndex];
        Node*root=new Node(data);
        int mid;
        // find the position of the root in inorder array
        for(int i=start;i<=end;i++){
            if(in[i]==data){
        // find the index of the root in inorder array
                mid=i;
                break;
            }
        }
    
        preIndex++;
        root->left=buildFromInorderPreOrder(pre,in,start,mid-1);
        root->right=buildFromInorderPreOrder(pre,in,mid+1,end);
        return root;
    }
};




class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preIndex=0;
        Node* ans=buildFromInorderPreOrder(pre,in,0,n-1,preIndex);
        return ans;
    }
      
    Node* buildFromInorderPreOrder(int pre[],int in[],int start,int end,int&preIndex){
        if(start>end){
            return NULL;
        }
        int data=pre[preIndex];
        Node*root=new Node(data);
        int mid;
        for(int i=start;i<=end;i++){
            if(in[i]==data){
                mid=i;
                break;
            }
        }
    
        preIndex++;
        // left first and then right
        root->left=buildFromInorderPreOrder(pre,in,start,mid-1,preIndex);
        root->right=buildFromInorderPreOrder(pre,in,mid+1,end,preIndex);
        return root;
    }
};