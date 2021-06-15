node* kthNodeFromEnd(node*head,int k){
    if(head==NULL or head->next==NULL){
        return head;
    }
    // make two ptrs slow and fast
    node*slow=head;
    node*fast=head;
    int jump=1;
    // first move fast ptr k steps ahead
    while(jump<=k){
        fast=fast->next;
        jump++;
    }
    // then move both ptrs 
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    // slow ptr will be kth node from end
    return slow;
}