#include <iostream>
#include<queue>
using namespace std;

    // Insert arr[i] in the priority queue
    // As the top element in priority queue is largest so pop it and store it as x. Now the top element in the priority queue will be the second largest element in subarray arr[0…i] pop it and store as y. Now the top element is third largest element in subarray arr[0…i] so pop it and store it as z.
    // Print x*y*z
    // Reinsert x, y, z.

void  largest_triplet(int a[],int n)
{
    priority_queue<int>pq;
    
    for(int i=0;i<n;i++)
    {
        pq.push(a[i]);
        if(pq.size()<3) 
           cout<<"-1"<<" ";
        else
            {

            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            int z=pq.top();
            pq.pop();

            int  product=x*y*z;
            cout<<product<<" ";
            pq.push(x);
            pq.push(y);
            pq.push(z);

            }
    }
    return ;
    
}
int main() {

int a[]={1,2,3,4,5};
int n=5;
largest_triplet(a,n);




}
