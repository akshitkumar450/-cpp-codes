
Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    // temp for iterating the 2 lists
    Node* temp1=head1;
    Node* temp2=head2;
    // new list having common elements of 2 lists
    Node* newHead=NULL;
    // for iterating in new list
    Node* cur=NULL;

    while(temp1!=NULL and temp2!=NULL){
        if(temp1->data==temp2->data){
            // for the first common node when the list is not builded
            if(newHead==NULL){
                Node*t=new Node(temp1->data);
                newHead=t;
                cur=t;
                // if the list is already builded
            } else {
                Node*t=new Node(temp1->data);
                cur->next=t;
                cur=cur->next;
            }
            // move ptrs of both list
            temp1=temp1->next;
            temp2=temp2->next;
        } else if(temp1->data <temp2->data){
            temp1=temp1->next;
        } else{
             temp2=temp2->next;
        }
    }
    return newHead;
}