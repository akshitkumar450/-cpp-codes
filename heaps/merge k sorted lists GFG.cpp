class compare{
    public:
    bool operator()(Node*a,Node*b){
        return a->data>b->data;
    }
};

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
            // make queue of Node* min heap
           priority_queue<Node*,vector<Node*>,compare>pq;
           
        //    push the first node of every list
           for(int i=0;i<K;i++){
               if(arr[i]!=NULL){
                   pq.push(arr[i]);
               }
           }
        //    if pq is empty means there was no list given or k=0
           if(pq.empty()) {
               return NULL;
           }
        //    create a dummy node for storing head of list
           Node*dummy=new Node(-1);
        //    for traversing the list
           Node*prev=dummy;
           while(!pq.empty()){
            //    take out the top element pop it
               Node*cur=pq.top();
               pq.pop();
            //    attach popped element to the next of prev
               prev->next=cur;
            // move prev ahead;
               prev=prev->next;

                // push the element from where the element was take out(if exists)
               if(cur->next){
                    pq.push(cur->next);    
               }
           }
           return dummy->next;
    }
};

// leetcode

class compare{
    public:
    bool operator()(ListNode*a,ListNode*b){
        return a->val>b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        
             // Your code here
           priority_queue<ListNode*,vector<ListNode*>,compare>pq;
           
           for(int i=0;i<arr.size();i++){
               if(arr[i]!=NULL){
                   pq.push(arr[i]);
               }
           }
           
           if(pq.empty()) {
               return NULL;
           }
           
           ListNode*dummy=new ListNode(-1);
           ListNode*prev=dummy;
           while(!pq.empty()){
               ListNode*cur=pq.top();
               pq.pop();
               
               prev->next=cur;
               prev=prev->next;
               if(cur->next){
               pq.push(cur->next);
                   
               }
               
           }
           return dummy->next;
        
    }
};