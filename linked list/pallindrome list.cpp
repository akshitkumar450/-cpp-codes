#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node*next;
        
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertAtbegin(Node* &head,int d){
    Node*nn=new Node(d);
    nn->next=head;
    head=nn;
}
void insertAtend(Node*&head,int d){
    if(head==NULL){
        insertAtbegin(head,d);
        return;
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node*nn=new Node(d);
    temp->next=nn;
}

void print(Node* head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

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

bool isPalindrome(Node *head) {
    if(head==NULL or head->next==NULL) return head;
    // first find the mid point of the list
    Node*slow=head;
    Node*fast=head;
    while(fast->next!=NULL and fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    // reverse the node after the midpoint and attach them after slow
    slow->next=reverse(slow->next);
    // move  slow to first ptr of reverse list
    slow=slow->next;
    
    // temp to head
    Node*temp=head;
    // check both is slow->data == temp->data
    // check only till slow reaches null
    while(slow!=NULL){
        if(slow->data!=temp->data){
            return false;
        }
        slow=slow->next;
        temp=temp->next;
    }
    return true;
}

int main() {
    Node* head=NULL;
    insertAtend(head,1);
    insertAtend(head,11);
    insertAtend(head,20);
    insertAtend(head,2);
    insertAtend(head,3);
    insertAtend(head,31);
    insertAtend(head,3);
    insertAtend(head,15);
    insertAtend(head,3);
    print(head);
    // removeDuplicatesUnsorted(head);
    head=reverse(head);
    print(head);
   

	return 0;
}