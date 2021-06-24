class Solution
{
    // after serialization we the the tree in a vector 
    // and we put -1 in every node which has missing left pointer or right pointer
    // basically we put -1 for every node which has NULL in left or right
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int>v;
        helperSer(root,v);
        return v;
    }
    
    void helperSer(Node*root,vector<int>&v){
        // preorder traversal
        if(root==NULL){
            // when ever we see a node have any null either in left or right we put -1
            v.push_back(-1);
            return;
        }
        // put the root
        v.push_back(root->data);
        helperSer(root->left,v);
        helperSer(root->right,v);
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       int cur=0;
       Node* ans=helperDer(A,cur);
       return ans;
    }
    
    Node* helperDer(vector<int> &A,int &cur){
        // if the current index is -1
        if(A[cur]==-1){
            cur++;
            return  NULL;
        }
        // create a node with the current data if it is not -1
        Node*root=new Node(A[cur]);
        cur++;
        root->left=helperDer(A,cur);
        root->right=helperDer(A,cur);
        return root;
    }

};