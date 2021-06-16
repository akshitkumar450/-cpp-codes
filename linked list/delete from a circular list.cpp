#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

void printlist(Node *head){
    if(head==NULL)return;
    cout<<head->data<<" ";
    for(Node *p=head->next;p!=head;p=p->next)
        cout<<p->data<<" ";
        cout<<endl;
}

void del(Node* head,int key){
    // if no node are there
    if(head==NULL) return;
    // if  single node is there with the key that is the head node
    if(head->data==key and head->next==head){
        delete head;
        head=NULL;
        return;
    }
    // if there are many nodes but data is present in the head node
    Node*last=head;
    if(head->data==key){
        // move till last to make last->next=head->next
        while(last->next!=NULL){
            last=last->next;
        }
        // make connections and delete the head node
        Node* temp=head;
        last->next=head->next;
        delete temp;
        head=last->next;
    }
    
    // traverse till the key is not found or we reach till the end of list
    // we are checking from last->next bcz we first checked with the head data then only we move forward
    while(last->next!=head and last->next->data!=key){
        last=last->next;
    }
    // we will come of this loop if we have found the key  or we have reached end
    if(last->next->data==key){
        Node* del=last->next;
        last->next=last->next->next;
        delete del;
    } else{
        cout<<"no key found"<<endl;
    }
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(5);
	head->next->next=new Node(20);
	head->next->next->next=new Node(15);
	head->next->next->next->next=head;
	printlist(head);
	del(head,100);
	printlist(head);
	
	return 0;
} 
