class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        // if both are null then they are isomorphic
        if(root1==NULL and root2==NULL) 
            return true;
        // if anyone of two is null they are not isomorphic
        if(root1==NULL or root2==NULL) 
            return false;
        // if root data of both trees are not same no need to check for the subtrees
        if(root1->data !=root2->data)
             return false;
        // There are two possible cases for n1 and n2 to be isomorphic
         // Case 1: The subtrees rooted at these nodes have NOT been "Flipped".
         // Both of these subtrees have to be isomorphic, hence the &&
         // Case 2: The subtrees rooted at these nodes have been "Flipped"
        return
        (isIsomorphic(root1->left ,root2->left)) and (isIsomorphic(root1->right ,root2->right)) ||
        (isIsomorphic(root1->left ,root2->right)) and (isIsomorphic(root1->right ,root2->left));
        
    }
};