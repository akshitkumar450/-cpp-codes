node* reverseByN(node*head,int n){
    if(n==0){
        return head;
    }
    node*temp=head;
    int cnt=0;
    // move till the node from where we have to rotate
    while(cnt<n-1 and temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    // store the node from where we have to rotate
    node* nthNode=temp;
    // move till last node
    while(temp->next!=NULL){
        temp=temp->next;
    }
    // change the pointer
    // join the last pointer with first node
    temp->next=head;
    head->prev=temp;
    // make new head
    head=nthNode->next;
    head->prev=NULL;
    nthNode->next=NULL;
    return head;
}