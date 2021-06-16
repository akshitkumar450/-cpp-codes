node* reverseByN(node*head,int n){
    if(n==0){
        return head;
    }
    node*temp=head;
    int cnt=0;
    // move till the node from where we have to rotate
    while(cnt<=n and temp!=NULL){
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
    temp->next=head;
    head->prev=temp;
    head=nthNode->next;
    head->prev=NULL;
    nthNode->next=NULL;
}