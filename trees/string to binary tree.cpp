   
//    Time Complexity: O(N^2)
// Auxiliary Space: O(N)
   
   TreeNode * str2tree(string &s) {
        // write your code here
        TreeNode*ans=BT(s,0,s.length()-1);
        return ans;

    }
    int findIndex(string &str,int start,int end){
        if(start>end){
            return -1;
        }
        stack<char>st;
        for(int i=start;i<=end;i++){
            // if ( push it
            if(str[i]=='('){
                st.push(str[i]);
                // if ) check at top if ( pop it
            } else if(str[i]==')'){
                if(st.top()=='('){
                    st.pop();
                    // if stack become empty we have find the ending index of the left subtree
                    if(st.empty()){
                        // return the index
                        return i;
                    }
                }
            }
        }
        return -1;
    }

    TreeNode* BT(string &str,int start,int end){
        if(start>end){
            return NULL;
        }
        // make the root of the first char
        // convert string to integer
        TreeNode*root=new TreeNode(str[start]-'0');
        // ending index of the left subtree string
        int index=-1;
        // start from next if it is (
        if(start+1<=end and str[start+1]=='('){
            index=findIndex(str,start+1,end);
        }
        // means we have find the ending index of the left subtree string
        if(index!=-1){
            // attach it on left
            // "4(2(3)(1))(6(5))"
             //   ⬆  //  ⬆ index will be here
                // start of left subtree
            root->left=BT(str,start+2,index-1);
            root->right=BT(str,index+2,end-1);
        }
        return root;
    }

    string str = "4(2(3)(1))(6(5))";
    Node* root = treeFromString(str, 0, str.length() - 1);