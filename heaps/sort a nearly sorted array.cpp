#include<iostream>
#include<queue>
using namespace std;

//  O(n log k) time and uses O(k) auxiliary space. 

void sortk(int arr[],int n,int k) {
    // min heap
    priority_queue<int ,vector<int> ,greater<int> >pq;
    // push first k+1 elements in min heap
    for(int i=0;i<=k;i++){
        pq.push(arr[i]);
    }
    // for storing the sorted values in the same arr
    int index=0;
    // from k+1 to n 
    // pop the top (min element) store it in arr and push the  new current element
    for(int i=k+1;i<n;i++) {
        arr[index++]=pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    // put the left elements in array
    while(!pq.empty()) {
        arr[index++]=pq.top();
        pq.pop();
    }
}

void print(int arr[],int n) {
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[]={2,6,3,12,56,8};
    int k=3;
    int n=6;
    sortk(arr,n,k);
    print(arr,n);
}
