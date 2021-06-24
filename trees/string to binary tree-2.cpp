// Time Complexity: O(N)
// Auxiliary Space: O(N)

Node* constructTree(string s) {
	// First character is the root of the tree
	Node* root = new Node(s[0] - '0');
	// Stack used to store the
	// previous root elements
	stack<Node*> stk;
	// Iterate over remaining characters
	for (int i = 1; i < s.length(); i++) {
		// If current character is '('
		if (s[i] == '(') {
			// Push root into stack
			stk.push(root);
		}
		// If current character is ')'
		else if (s[i] == ')') {
			// Make root the top most
			// element in the stack
			root = stk.top();
			// Remove the top node
			stk.pop();
		}
		// If current character is a number
		else {
			// If left is null, then put the new
			// node to the left and move to the
			// left of the root
			if (root->left ==NULL) {
				Node* left = new Node(s[i] - '0');
				root->left = left;
				root = root->left;
			}
			// Otherwise, if right is null, then
			// put the new node to the right and
			// move to the right of the root
			else if (root->right ==NULL) {
				Node* right = new Node(s[i] - '0');
				root->right = right;
				root = root->right;
			}
		}
	}
	return root;
}

int main(){
	string s = "4(2(3)(1))(6(5))";
	Node* root = constructTree(s);
	return 0;
}
