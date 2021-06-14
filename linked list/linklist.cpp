#include <bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node*next;
        
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertAtbegin(node* &head,int d){
    node*nn=new node(d);
    nn->next=head;
    head=nn;
}

void insertAtend(node*&head,int d){
    if(head==NULL){
        insertAtbegin(head,d);
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node*nn=new node(d);
    temp->next=nn;
}

int length(node*head){
    int len=0;
    node*temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void insertAtk(node*&head,int data,int k){
    if(head==NULL || k==1){
        insertAtbegin(head,data);
        return;
    }
    // if k is greater than the length of linked list
    else if(k>=length(head)){
        insertAtend(head,data);
        return;
    }
    int cnt=1;
    node*temp=head;
    while(cnt<k-1){
        temp=temp->next;
        cnt++;
    }
    node*nn=new node(data);
    nn->next=temp->next;
    temp->next=nn;
}

void deletebegin(node* &head){
    if(head==NULL) return;
    // store the original head to that we can delete it after
    node*temp=head;
    head=head->next;
    delete temp;
}

void deleteAtEnd(node*&head){
    if(head==NULL) return;
    // if it has only one node 
    if(head->next==NULL){
        deletebegin(head);
        return;
    }
    node*temp=head;
    // to stop at second last node
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    //first  store the node be deleted 
    node* tobeDeleted=temp->next;
    temp->next=NULL;
    delete tobeDeleted;
}

void deleteAtk(node*&head,int k){
    if(head==NULL){
        return;
    }
    if(k==1 ){
        deletebegin(head);
        return;
    }
    int cnt=1;
    node*temp=head;
    while(cnt<k-1){
        temp=temp->next;
        cnt++;
    }
    node* tobeDeleted=temp->next;
    temp->next=temp->next->next;
    delete tobeDeleted;
}

void print(node* head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

bool search(node*head,int key){
    node*temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}


node* reverseRecursive(node*head){
    // if no node or a single node
    if(head==NULL or head->next==NULL){
        return head;
    }
    node* newHead=reverseRecursive(head->next);
    // my work
    node*cur=head;
    cur->next->next=cur;
    cur->next=NULL; 
    return newHead;
}

node* reverseIterative(node* head){
    node*prev=NULL;
    node*curr=head;
    while(curr!=NULL){
        node* nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    // previous will become our new head
    return prev;
}


node* kReverse(node*head,int k){
    // if no or a single node 
    if(head==NULL or head->next==NULL){
        return head;
    }
    node* prev=NULL;
    node* curr=head;
        int steps=1;
        // first reverse the first k nodes
                        // if there are no enough nodes in k size
    while(steps<=k and curr!=NULL){
        node *nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
        steps++;
    }
    // after reversing the first k nodes our curr will be at k+1 node
    // prev will point to head of new linked list
    // and the old head will become the last node of first k nodes
    // then we join the head to new head for the subproblem
    // subproblem will start from curr ,bcz after first k reverse cure will be point to subprlm
    head->next=kReverse(curr,k);
    // prev will be our new head after reversing
    return prev;
}

node* kthNodeFromEnd(node*head,int k){
    if(head==NULL or head->next==NULL){
        return head;
    }
    // make two ptrs slow and fast
    node*slow=head;
    node*fast=head;
    int jump=1;
    // first move fast ptr k steps ahead
    while(jump<=k){
        fast=fast->next;
        jump++;
    }
    // then move both ptrs 
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    // slow ptr will be kth node from end
    return slow;
}

node* midpoint(node*head){
    if(head==NULL or head->next==NULL){
        return head;
    }
    node*slow=head;
    node*fast=head;
            // odd length       //even length
    while(fast->next!=NULL and fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node * merge(node*head1,node*head2){
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    
    // new head for the sorted merged linked list
    node* newHead;
    if(head1->data< head2->data){
        newHead=head1;
        newHead->next=merge(head1->next,head2);
    } else{
        newHead=head2;
        newHead->next=merge(head1,head2->next);
    }
    return newHead;
}

node* mergeSort(node*head){
    if(head==NULL or head->next==NULL){
        return head;
    }
    
    // find the midpoint the link list
    node*mid=midpoint(head);
    
    // make two list
    node* first=head;
    node* second=mid->next;
    
    // to separate the two linked list to break the linkage 
    mid->next=NULL;
    
    // recusive sorting
    first=mergeSort(first);
    second=mergeSort(second);
    
    // merge them
    node*merged=merge(first,second);
    return merged;
}

bool hasCycle(node *head) {
        node* slow=head;
        node* fast=head;
        while(fast!=NULL and fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            
            if(fast==slow){
                return true;
            }
        }
        return false;
}

int main() {
    // node* head=NULL;
//     insertAtend(head,78);
//     print(head);
//     insertAtbegin(head,1);
//     insertAtbegin(head,2);
//     insertAtbegin(head,4);
//     insertAtbegin(head,15);
//     insertAtbegin(head,5);
//     print(head);
//      node* newHead=reverseRecursive(head);
//     print(newHead);
//     node *againNewHead=reverseIterative(newHead);
//     print(againNewHead);
    // insertAtend(head,10);
    // insertAtend(head,19);
    // cout<<length(head)<<endl;
    // print(head);
    // insertAtk(head,20,3);
    //  print(head);
    //  deletebegin(head);
    //  print(head);
    //  deleteAtEnd(head);
    //  deleteAtEnd(head);
    //  print(head);
    //  node* mid1=midpoint(head);
    //  cout<<mid1->data<<endl;
    //  if(search(head,78)){
    //      cout<<"present";
    //  } else{
    //      cout<<"not present";
    //  }
    // deleteAtk(head,4);
    //  print(head);
    //   node* mid2=midpoint(head);
    //  cout<<mid2->data<<endl;
    
    
    // ************ MERGE 2 SORTED LIST ***************

//  	node* head1 = NULL;

// 	insertAtend(head1, 1);
// 	insertAtend(head1, 3);
// 	insertAtend(head1, 5);
// 	insertAtend(head1, 8);
// 	insertAtend(head1, 9);

// 	node* head2 = NULL;

// 	insertAtend(head2, 2);
//     insertAtend(head2, 4);
// 	insertAtend(head2, 6);
//     insertAtend(head2, 7);

// 	cout << "First Linked List ******************" << endl;
// 	print(head1);

// 	cout << "Second Linked List ******************" << endl;
// 	print(head2);

// 	node* mergedList = merge(head1, head2);

// 	cout << "Merged Linked List ******************" << endl;
// 	print(mergedList);

//********** K REVERSE **************

// 	node* head = NULL;

// 	insertAtend(head, 1);
// 	insertAtend(head, 2);
// 	insertAtend(head, 3);
// 	insertAtend(head, 4);
// 	insertAtend(head, 5);
// 	insertAtend(head, 6);
// 	insertAtend(head, 7);
//     insertAtend(head, 8);
// 	insertAtend(head, 9);

// 	cout << "Before ***************" << endl;
// 	print(head);

// 	head = kReverse(head, 3);

// 	cout << "After ******************" << endl;
// 	print(head);
// 	insertAtk(head,22,3);
// 	insertAtk(head,300,15);
// 	print(head);
    // node* kthNode=kthNodeFromEnd(head,8);
// 	cout<<kthNode->data<<endl;

// ************ MERGE SORT ***************

	node* head = NULL;

	insertAtend(head, 1);
	insertAtend(head, 6);
	insertAtend(head, 5);
	insertAtend(head, 3);
	insertAtend(head, 4);
	insertAtend(head, 2);

	cout << "Unsorted Linked List *****************" << endl;
	print(head);

	head = mergeSort(head);

	cout << "Sorted Linked List ***************" << endl;
	print(head);
    

	return 0;
}