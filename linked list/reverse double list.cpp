
Node* reverseDLL(Node * head)
{
    //Your code here
    
    Node*temp=head;
    if(head==NULL or head->next==NULL) return head;
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    head=temp;
    //  reverse the last node
    temp->next=temp->prev;
    // only after
    temp->prev=NULL;
    temp=temp->next;
    
    // then reverse the middle nodes
    while(temp->prev!=NULL){
        Node* t=temp->next;
         temp->next=temp->prev;
         temp->prev=t;
          temp=temp->next;
    }
    // reverse first node
    temp->prev=temp->next;
    temp->next=NULL;
    return head;
    
}