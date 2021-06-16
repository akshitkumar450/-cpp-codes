struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};


/*  Function which returns the  root of 
    the flattened linked list. */
    
// merge sort recursive
Node* mergelists(Node*a,Node*b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    
    Node* result;
    if(a->data <b->data){
        result=a;
        result->bottom=mergelists(a->bottom,b);
    } else{
        result=b;
        result->bottom=mergelists(a,b->bottom);
    }
    result->next=NULL;
    return result;
  
}

// merge sort iterative
Node* mergelists(Node*a,Node*b){
    // make a dummy node
    Node*temp=new Node(0);
    // this node will be the result of the merged list
    Node* res=temp;
    
    while(a!=NULL and b!=NULL){
        if(a->data < b->data){
            temp->bottom=a;
            a=a->bottom;
            temp=temp->bottom;
        } else {
            temp->bottom=b;
            b=b->bottom;
            temp=temp->bottom;
        }
    }
    if(a!=NULL){
        temp->bottom=a;
        a=a->bottom;
    } else {
        temp->bottom=b;
        b=b->bottom;
    }
    // after merging two list next will be null 
    res->next=NULL;
    // res->bottom bcz we have assign 0 as a dummy data
    return res->bottom;
}

Node *flatten(Node *head)
{
   // Your code here
    if(head==NULL or head->next==NULL){
        return head;
    }
    
    // call for recursion for the next list
    head->next=flatten(head->next);
    
    // merge the list 
    head=mergelists(head,head->next);
    return head;
}

