#include <iostream>
using namespace std;
// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#
// O(N^2)
int maxWater(int arr[],int n) {
    int res=0;
    for(int i=1;i<n-1;i++){
        // max on left
        int left=arr[i];
        for(int j=0;j<i;j++) {
            left=max(left,arr[j]);
        }
        // max on right
        int right=arr[i];
        for(int j=i+1;j<n;j++){
            right=max(right,arr[j]);
        }
        res=res+(min(left,right)-arr[i]);
    }
    return res;
}

// O(N) with space of O(N)
int maxWater2(int arr[],int n){
    int water=0;
    int left[n];
    int right[n];
    // fill the left array
    left[0]=arr[0];
    for(int i=1;i<n;i++){
        left[i]=max(left[i-1],arr[i]);
    }
    // fill the right array
    right[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        right[i]=max(right[i+1],arr[i]);
    }
    
    for(int i=0;i<n;i++)
        water+=min(left[i],right[i])-arr[i];
        
        return water;
    
}

int main() {
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    
    // cout << maxWater(arr, n); 
    cout << maxWater2(arr, n); 
	return 0;
}