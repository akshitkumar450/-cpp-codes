void removeLast(node*&head){
    if(head==NULL) return ;
    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    node*last=temp->next;
    temp->next=NULL;

    last->next=head;
    head=last;
}