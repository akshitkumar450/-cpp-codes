    
Node* reverse(Node*head){
    if(head==NULL or head->next==NULL) return head;
    
    Node*prev=NULL;
    Node*curr=head;
    while(curr!=NULL){
        Node *nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}

Node *compute(Node *head) {
    // reverse the list
    head=reverse(head);
    // store the head of the reversed list to reverse it again
    Node*newHead=head;
    // two ptrs for traversing and comparing with the max value
    Node*prev=head;
    // take max as the firs node value of the reversed list
    int max=head->data;
    // move head one ptr ahead
    head=head->next;
    while(head!=NULL){
        // means this will include in our answer
        if(head->data>=max){
            // update the max with the head data if greater then old max
            max=head->data;
            // move both ptrs 
            prev=head;
            head=head->next;
        } else{
            // do not include in our answer
            prev->next=head->next;
            head=prev->next;
        }
    }
    // reverse the list again to get the order
    head=reverse(newHead);
    return head;
}