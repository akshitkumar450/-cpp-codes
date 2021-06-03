#include <bits/stdc++.h>
using namespace std;

// O(n^2);
int maxLen(int arr[],int n){
    int maxlen=0;
    int curSum;
    for(int i=0;i<n;i++){
        curSum=0;
        for(int j=i;j<n;j++){
            curSum+=arr[j];
            if(curSum==0){
                maxlen=max(maxlen,j-i+1);
            }
        }
    }
    return maxlen;
}

int maxLen2(int arr[],int n){
    unordered_map<int,int>mp;
    int maxlen=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];

        if (sum == 0)
            max_len = i + 1;
            // if the sum exists ,check when it was seen last in the hashmap and put in the hashmap
        if(mp.find(sum)!=mp.end()){
            maxlen=max(maxlen,i-mp[sum]);
        } else {
            mp[sum]=i;
        }
    }
    return maxlen;
}

int main() {
	 int arr[] = { 15, -2, 2, -8, 1, 7, 10, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of the longest 0 sum subarray is "
         << maxLen2(arr, n);
	return 0;
}