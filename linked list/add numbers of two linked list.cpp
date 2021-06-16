
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
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
            first=reverse(first);
    second=reverse(second);
    Node*temp;
    // for storing the sum list
    Node*res=NULL;
    // for iterating sum list
    Node*cur=NULL;
    int sum=0;
    int carry=0;
    while(first!=NULL or second!=NULL){
        sum=carry+(first?first->data:0)+(second?second->data:0);
        carry=(sum>=10)?1:0;
        sum=sum%10;
        temp=new Node(sum);
        if(res==NULL){
            res=temp;
            cur=temp;
        } else{
            cur->next=temp;
            cur=temp;
        }
        if(first )first=first->next;
        if(second) second=second->next;
    }
    if(carry>0){
        temp=new Node(carry);
        cur->next=temp;
        cur=temp;
    }
    res=reverse(res);
    return res;
    }
};