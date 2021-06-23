vector <int> zigZagTraversal(Node* root)
{
	vector<int>ans;
    // to store the current level
	stack<Node*>curr;
    // to store the next level
	stack<Node*>next;
    // to check the level 
    // whether from left to right or right to left
    // to check direction
	bool leftRight=true;
	curr.push(root);
	while(!curr.empty()){
	    Node*temp=curr.top();
	    curr.pop();
	    
	    if(temp){
	        ans.push_back(temp->data);
	        if(leftRight){
	           // left first
	            if(temp->left){
	                next.push(temp->left);
	            }
	           // right second
	            if(temp->right){
	                next.push(temp->right);
	            }
	        } 
	        else if(!leftRight){
	           // right first
	             if(temp->right){
	                next.push(temp->right);
	            }
	           // left second
	             if(temp->left){
	                next.push(temp->left);
	            }
	        }
	    }
        // after every level end
        // alter the leftRight ( to change the direction)
        // swap curr stack with next stack
	    if(curr.empty()){
	       // change leftRight
	       leftRight=!leftRight;
	       swap(curr,next);
	    }  
	}
	return ans;
}