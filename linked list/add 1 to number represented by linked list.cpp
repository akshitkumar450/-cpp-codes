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

void print(node* head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* reverse(node*head){
    if(head==NULL or head->next==NULL) return head;
    
    node*prev=NULL;
    node*curr=head;
    while(curr!=NULL){
        node *nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}

node* addone(node*head){
    // reverse the given list
    head=reverse(head);
    // store head for reversing again and it will point to the new list with sum
    node* newhead=head;
    // for traversing
    node*temp=head;
    while(temp!=NULL){
        // if 9 is in the last of a number then make that 1 and add 0 to begining of sum list(newhead)
        if(temp->data==9 and temp->next==NULL){
            temp->data=1;
            node* zero=new node(0);
            // make 0 head
            zero->next=newhead;
            newhead=zero;
            temp=temp->next;
            // if current number is 9 then make it 0 and move forward
        } else if(temp->data==9){
            temp->data=0;
            temp=temp->next;
            // if current data is other than 9 then just add 1 to it and break
        } else{
            temp->data=temp->data+1;
            temp=temp->next;
            break;
        }
    }
    // reverse the list again
    head=reverse(newhead);
    return head;
}

int main() {
    node* head=NULL;
    insertAtend(head,9);
    insertAtend(head,9);
    insertAtend(head,9);
    print(head);
    head=addone(head);
    print(head);

	return 0;
}