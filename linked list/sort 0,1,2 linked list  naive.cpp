 Node* segregate(Node *head) {
    Node*temp=head;
    int c0=0,c1=0,c2=0;
    while(temp!=NULL){
        if(temp->data==0) c0++;
        else if(temp->data==1) c1++;
        else c2++;
        
        temp=temp->next;
    }
    
    temp=head;
    while(temp!=NULL){
        for (int i = 0; i < c0; i++) {
            /* code */
            temp->data=0;
            temp=temp->next;
        }
        for (int i = 0; i < c1; i++) {
            /* code */
            temp->data=1;
            temp=temp->next;
        }
        for (int i = 0; i < c2; i++) {
            /* code */
            temp->data=2;
            temp=temp->next;
        }
    }
    return head;        
}
// O(N) time
// O(1) space