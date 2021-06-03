#include <bits/stdc++.h>
using namespace std;
// O(n^2)
int countPairs(int arr[],int n,int sum){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==sum){
                cnt++;
            }
        }
    }
    return cnt;
}

// O(N)
int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        int twice_cnt=0;
        for(int i=0;i<n;i++){
            twice_cnt=twice_cnt+mp[k-arr[i]];
            
            if(k-arr[i]==arr[i])
                twice_cnt--;
        }
        return twice_cnt/2;
}


int main() {
	 int arr[] = {1, 5, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 6;
    cout<<countPairs(arr,n,sum);
    cout<<getPairsCount(arr,n,sum);
	return 0;
}