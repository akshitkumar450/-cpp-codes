#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(NLOGN)
int findLongestConseqSubseq(int arr[],int n ) {
    int cnt=0,ans=0;
    sort(arr,arr+n);
    vector<int>v;
    v.push_back(arr[0]);
    // check for duplicates elements 
    for(int i=1;i<n;i++) {
        if(arr[i]!=arr[i-1]) {
            v.push_back(arr[i]);
        }
    }
    for(int i=0;i<v.size();i++) {
        // check if the current element is == to previous element +1 
        // (+1 bcz we are checking for consecutive elements)
        if(i>0 && v[i]==v[i-1]+1) {
            cnt++;
        } else {
            cnt=1;
        }
        ans=max(ans,cnt);
    }
    return ans;
}

// O(N )
// Algorithm:

//     Create a Priority Queue to store the element
//     Store the first element in a variable
//     Remove it from the Priority Queue
//     Check the difference between this removed first element and the new peek element
//     If the difference is equal to 1 increase count by 1 and repeats step 2 and step 3
//     If the difference is greater than 1 set counter to 1 and repeat step 2 and step 3
//     if the difference is equal to 0 repeat step 2 and 3
//     if counter greater than the previous maximum then store counter to maximum
//     Continue step 4 to 7 until we reach the end of the Priority Queue
//     Return the maximum value

int findLongestConseqSubseq2(int arr[],int n) {
    priority_queue<int,vector<int>,greater<int>>pq; // min priority queue
    for(int i=0;i<n;i++) {
        pq.push(arr[i]);
    }
    int top=pq.top();
    pq.pop();
    int cnt=1,max=1;
    while(!pq.empty()) {
        // it means this is not the consecutive sequence
        if(pq.top()-top >1) {
            cnt=1;
            top=pq.top();
            pq.pop();
            // both elements are same
        } else  if(pq.top()==top) {
           top=pq.top();
           pq.pop();
        // differnece is 1 between nos.  
        } else  {
            cnt++;
            top=pq.top();
            pq.pop();
        }
        if(max<cnt) {
            max=cnt;
        }
    }
    return max;
}

int main() {
	
	int arr[] = {1, 9, 3, 10, 4, 20, 2};
    int n = sizeof arr / sizeof arr[0];
    cout << "Length of the Longest contiguous subsequence "
            "is "
         << findLongestConseqSubseq(arr, n);
	return 0;
}