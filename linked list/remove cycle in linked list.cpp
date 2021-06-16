 void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node* slow=head;
        Node* fast=head;
        // means list has cycle
        while(fast!=NULL and fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            // if both ptrs point to same ,,at that point they have cycle
            if(fast==slow){
                slow=head;
                
                while(slow->next!=fast->next){
                    slow=slow->next;
                    fast=fast->next;
                }
                fast->next=NULL;
            }
        } 
}


void detectRemoveLoop(Node* head) 
{ 
    Node *slow = head;
    Node *fast = head; 
    while (fast!=NULL && fast->next!=NULL) { 
        slow = slow->next; 
        fast = fast->next->next; 
        // if there is cycle 
        if (slow == fast) { 
            break; 
        } 
    } 
    // if there is not loop in cycle then return
    if(slow!=fast)
        return;
        // move slow to head
    slow=head;
    // remove cycle step
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=NULL;
}