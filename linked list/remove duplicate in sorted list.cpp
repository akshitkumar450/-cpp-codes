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

void removeDuplicates(node*&head){
    if(head==NULL or head->next==NULL){
        return ;
    }
    
    node* temp=head;
    while(temp->next!=NULL){
        // if data of current and next node are same ,then delete the next node with same data
        if(temp->data==temp->next->data){
            // store next ptr to be deleted
            node* nxt=temp->next;
            temp->next=temp->next->next;
            delete nxt;
        }
        // if not same move ahead
        else{
            temp=temp->next;
        }
    }
}

int main() {
    node* head=NULL;
    insertAtend(head,1);
    insertAtend(head,1);
    insertAtend(head,2);
    insertAtend(head,2);
    insertAtend(head,3);
    insertAtend(head,3);
    insertAtend(head,3);
    insertAtend(head,5);
    insertAtend(head,5);
    insertAtend(head,5);
    insertAtend(head,6);
    insertAtend(head,6);
    insertAtend(head,6);
    insertAtend(head,6);
    print(head);
    removeDuplicates(head);
    print(head);
   

	return 0;
}