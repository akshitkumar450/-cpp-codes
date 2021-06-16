// We traverse the link list from head to end. For every newly encountered element,
//  we check whether it is in the hash table:
//  if yes, we remove it; otherwise we put it in the hash table.

Node * removeDuplicates( Node *head) {
    if(head==NULL or head->next==NULL){
        return head;
    }
    Node*prev=NULL;
    Node*curr=head;
    unordered_set<int>st;
    while(curr!=NULL){
        // if current data is in set means it was also present before
        // then delete that node
        if(st.find(curr->data)!=st.end()){
            // make the connections between the ptrs
            prev->next=curr->next;
            delete curr;
            curr=prev->next;
            
        } else{
            // if current data is not in set then insert in set
            st.insert(curr->data);
            prev=curr;
            curr=prev->next;
        }
    }
    return head;
}