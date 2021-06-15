//  If there are two middle nodes, return the second middle node. 
  
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
         ListNode* fast=head;
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }