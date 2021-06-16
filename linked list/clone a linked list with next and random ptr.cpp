//  time O(N)
//   spaceO(1)

Node* copyRandomList(Node* head) {
         Node *iter = head; 
          Node *front = head;

          // First round: make copy of each node,
          // and link them together side-by-side in a single list.
          while (iter != NULL) {
            front = iter->next;
            // make a copy of data of the node and insert it after it in the single list
            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;

            iter = front;
          }

          // Second round: assign random pointers for the copy nodes.
          iter = head;
          while (iter != NULL) {
            if (iter->random != NULL) {
              iter->next->random = iter->random->next;
            }
            // move iter two steps bcz there will be copy node in the list created in 1 step
            iter = iter->next->next;
          }

          // Third round: restore the original list, and extract the copy list.
          iter = head;
        //   to save the head of copied list
          Node *pseudoHead = new Node(0);
          Node *copy = pseudoHead;

          while (iter != NULL) {
            front = iter->next->next;

            // extract the copy
            copy->next = iter->next;

            // restore the original list
            iter->next = front;
              
            copy = copy -> next; 
            iter = front;
          }

          return pseudoHead->next;
}

// time O(N)
// space O(N)

Node *copyList(Node *head) {
    //ptr for traversing the original list and copy list
    Node*ori=head;
    Node*clone=NULL;
    
    // map to store the original and copy node
    / Traverse the original list and
        // make a copy of that in the 
        // clone linked list.
    unordered_map<Node*,Node*>mp;
    while(ori!=NULL){
        // make a new node  with the current node data in original list and store it 
        clone=new Node(ori->data);
        mp[ori]=clone;
        ori=ori->next;
    }
    
    // move back ori to head for travesing it again
    ori=head;
        // Traversal of original list again
        // to adjust the next and random 
        // references of clone list using 
        // hash map
    while(ori!=NULL){
        clone=mp[ori];
        clone->next=mp[ori->next];
        clone->arb=mp[ori->arb];
        ori=ori->next;
    }
    return mp[head];
}