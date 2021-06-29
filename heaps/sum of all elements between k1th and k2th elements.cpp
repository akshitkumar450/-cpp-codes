#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//gfg
int main() {

    int a[] = {20, 8, 22, 4, 12, 10, 14};
    int k1=3,k2=6; int n=7;
    priority_queue <int ,vector<int>, greater<int> > pq;  //min heap
    // push all elements in min heap
    for(int i=1;i<=n;i++)
      pq.push(a[i]);
    // extract first k1 elements
   for(int i=0;i<k1;i++)
      pq.pop();

    // now extract k2-k1-1 elements and sum them all
    int sum=0;
    for(int i=k1+1;i<k2;i++)
    {
        sum=sum+pq.top();
        pq.pop();
    }
    cout<<"sum " <<sum;
}
