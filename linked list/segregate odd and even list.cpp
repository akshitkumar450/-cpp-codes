 Node* divide(int N, Node *head){
    if(head==NULL or head->next==NULL)
        return head;
    // denotes the head of odd list
    Node*odd=NULL;
    // denotes the head od even list
    Node*even=NULL;
    // for iterating over even list
    Node*e=NULL;
    // for iterating over odd list
    Node*o=NULL;
    // for iterating over main list
    Node*temp=head;

    while(temp!=NULL){
        if(temp->data%2==0){
            // if first new even node is coming attach to the even and point e also
            if(even==NULL){
                even=temp;
                e=temp;
                temp=temp->next;
            } else {
                // if there are already some even nodes in even list
                e->next=temp;
                e=e->next;
                temp=temp->next;
            }
        } else{
            // if first new odd node is coming attach to the odd and point e also
            if(odd==NULL){
                odd=temp;
                o=temp;
                temp=temp->next;
            } else{
                // if there are already some odd nodes in odd list
                 o->next=temp;
                o=o->next;
                temp=temp->next;
            }
        }
    }
    // after while loop e will be at end of the even list
    // if e is there attach e to odd
    if(e) 
        e->next=odd;
    if(o)
    // o will be at last of odd list
    // put NULL at last od odd list
        o->next=NULL;
        // even will point to the head of oddeven list
    if(even) return even;
    else return odd;
}