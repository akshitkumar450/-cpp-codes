// C++ program to find a pair with given sum x.
#include<bits/stdc++.h>
using namespace std;

// structure of node of doubly linked list
struct Node
{
	int data;
	struct Node *next, *prev;
};

// Function to find pair whose sum equal to given value x.
void pairSum(Node*head,int x){
    // similar to two pointer approach in arrays to find pair sum un sorted arrays
        // make two ptrs
        // first we at start
        Node*first=head;
        // second will be at end of the list
        // move second ptr to end of list
        Node*second=head;
        while(second->next!=NULL){
            second=second->next;
        }

        // to keep a track if we found a single pair
        bool found=false;

        while(second->next!=first and first!=second){
             if((first->data+second->data)<x){
                 first=first->next;
            } else if((first->data+second->data) > x){
                second=second->prev;
            } else {
                found=true;
                cout<<first->data <<" "<<second->data<<endl;
                 first=first->next;
                 second=second->prev;
            }
        }
        if(found==false)
        cout<<"no pair found";
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node **head, int data)
{
	struct Node *temp = new Node;
	temp->data = data;
	temp->next = temp->prev = NULL;
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

// Driver program
int main()
{
	struct Node *head = NULL;
	insert(&head, 9);
	insert(&head, 8);
	insert(&head, 6);
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 2);
	insert(&head, 1);
	int x = 7;

	pairSum(head, x);

	return 0;
}
