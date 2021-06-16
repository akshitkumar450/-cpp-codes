
void splitList(Node *head, Node **head1, Node **head2){
    Node* slow=head;
    Node* fast=head;
    // first find the middle node
    while(fast->next!=head and fast->next->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    // make the first list
    *head1=head;
    *head2=slow->next;
    slow->next=*head1;
    // move till last to make second list
    Node* cur=*head2;
    while(cur->next!=head){
        cur=cur->next;
    }
    cur->next=*head2;
}