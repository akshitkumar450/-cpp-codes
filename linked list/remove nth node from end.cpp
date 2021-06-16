ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*slow=head;
        ListNode*fast=head;
       int cnt=1;
        while(cnt<=n){
            fast=fast->next;
            cnt++;
        }
        if(!fast) return head->next;
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* temp=slow->next;
        slow->next=slow->next->next;
        delete temp;
        return head;
 }