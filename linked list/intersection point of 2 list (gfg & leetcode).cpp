// gfg

int intersectPoint(Node* head1, Node* head2) {
        int l1=0,l2=0;
         Node* temp1=head1;
         Node* temp2=head2;
//         length of ll1
        while(temp1!=NULL){
            l1++;
            temp1=temp1->next;
        }
//         length of ll2
        while(temp2!=NULL){
            l2++;
            temp2=temp2->next;
        }
//         cal the diff of the length of two lists
        int diff=abs(l2-l1);
       
    //    reset the pointers temp1 and temp2 to head1,2
        temp1=head1;
        temp2=head2;
        int cnt=0;
        
//       move the longer list  diff steps ahead
        if(l1>l2){
            while(cnt<diff){
                temp1=temp1->next;
                cnt++;
            }
            // for(int i=0;i<diff;i++){
            //     temp1=temp1->next;
            // }
        } 
        else{
             while(cnt<diff){
                temp2=temp2->next;
                cnt++;
            }
            //  for(int i=0;i<diff;i++){
            //     temp2=temp2->next;
            // }
        }
        // move both till they are not equal
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
         return temp1->data;
}



// leetcode

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0,l2=0;
         ListNode* temp1=headA;
         ListNode* temp2=headB;
//         length of ll1
        while(temp1!=NULL){
            l1++;
            temp1=temp1->next;
        }
//         length of ll2
        while(temp2!=NULL){
            l2++;
            temp2=temp2->next;
        }
//         cal the diff of the length of two lists
        int diff=abs(l2-l1);
        int cnt=0;
       
//         move the longer list 
        temp1=headA;
        temp2=headB;
        
        if(l1>l2){
            // while(cnt<=diff){
            //     temp1=temp1->next;
            //     cnt++;
            // }
            for(int i=0;i<diff;i++){
                temp1=temp1->next;
            }
        } 
        else{
            //  while(cnt<=diff){
            //     temp2=temp2->next;
            //     cnt++;
            // }
             for(int i=0;i<diff;i++){
                temp2=temp2->next;
            }
        }
        
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;

    }