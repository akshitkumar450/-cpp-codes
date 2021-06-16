struct Node {
    int data;
    struct Node* next, *prev;
};

int countPairTriplets(node*first,node*second,int value){
    int count=0;
    while(first!=NULL and second!=NULL and first!=second and second->next!=first){
        if((first->data + second->data)==value){
            count++;
            first=first->next;
            second=second->prev;
        } else if((first->data + second->data)<value){
            first=first>next;
        } else{
            second=second->prev;
        }
    }
    return count;
}

int countTriplets(node*head,int x){
    if(head==NULL) 
      return 0;
      
    int cnt=0;
    node*first;
    node*last=head;
    node*current;
    // move last ptr to last of the list
    while(last->next!=NULL){
        last=last->next;
    }
    
    for(current=head;current!=NULL;current=current->next){
        // for each current node
        first=current->next;
        cnt+=countPairTriplets(first,last,x-current->data);
    }
    return cnt
}
