    ListNode *detectCycle(ListNode *head) {
        // make two pointers
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                // move till both are not same
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                // this point will be the starting point of the loop
                return slow;
            }
        }
        return NULL;
    }