
class Solution
{
    public:
    //Function to add two numbers represented by linked list.
Node* reverse(Node*head){
    if(head==NULL or head->next==NULL) return head;
    
    Node*prev=NULL;
    Node*curr=head;
    while(curr!=NULL){
        Node *nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}
    struct Node* addTwoLists(struct Node* first, struct Node* second) {
        first=reverse(first);
        second=reverse(second);
        // for storing the sum list
        // create a dummy node to avoid NULL check
        Node*res=new Node(-1);
        // for iterating sum list
        Node*cur=res;
        int carry=0;
        while(first!=NULL or second!=NULL or carry!=0){
            // sum will be initialized to 0 in each iteration
            int sum=0;
            // add first list data
            if(first!=NULL) {
                sum=sum+first->data;
                first=first->next;
            }
            // add second list data
            if(second!=NULL) {
                sum=sum+second->data;
                second=second->next;
            }
            // add carry
            sum=sum+carry;
            // create digit to be added in list
            int lastDigit=sum%10;
            // make carry
            carry=sum/10;
            // make new node 
            Node* temp=new Node(lastDigit);
            // point to new node
            cur->next=temp;
            // move to next
            cur=cur->next;
        }
        res=reverse(res->next);
        return res;
    }
};