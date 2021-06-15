/* Should return true if linked list is circular, else false */
bool isCircular(Node *head){
    // empty list is circular
    if(head==NULL) 
        return true;

    Node* temp=head;
//   this loop will terminate in both is circular or not
    while(temp->next!=head){
        temp=temp->next;
        // if the list is not circular temp will reach to null
        if(temp==NULL) 
            break;
       
    }
    // if temp reaches end means not circular
     if(temp==NULL) return false;
    //  measn temp>next==head ,measn circular list
        else return true;
  
}