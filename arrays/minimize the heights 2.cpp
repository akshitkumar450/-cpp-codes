#include <bits/stdc++.h>
using namespace std;

int minHeight(int arr[],int n,int k){
    sort(arr,arr+n);
    int small=arr[0]+k;
    int large=arr[n-1]-k;
    int ans=arr[n-1]-arr[0];
    int mi,ma;
    for(int i=1;i<=n-1;i++){
        if(arr[i]>=k){
        mi=min(small,arr[i]-k);
        ma=max(large,arr[i-1]+k);
        ans=min(ans,ma-mi);
        }
        else {
            continue;
        }
    }
    return ans;
}

int main() {
	 int arr[] = {1, 5, 8, 10};
	 int n=sizeof(arr)/sizeof(int);
	 int k;
	 cin>>k;
	 cout<<minHeight(arr,n,k);
	return 0;
}