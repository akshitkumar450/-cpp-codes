#include <bits/stdc++.h>
using namespace std;

int bestTime(int arr[],int n) {
    int maxProfit=0;
   for(int i=0;i<n-1;i++) {
       for(int j=i+1;j<n;j++) {
           int profit=arr[j]-arr[i];
           if(profit>maxProfit){
               maxProfit=profit;
           }
       }
   }
   return maxProfit;
}
// O(n^2)

int bestTime2(int arr[],int n) {
    int maxProfit=0;
    int minPrice=INT_MAX;
    for(int i=0;i<n;i++) {
        minPrice=min(arr[i],minPrice);
        maxProfit=max(maxProfit,arr[i]-minPrice);
    }
    return maxProfit;
}
// o(N)

int main() {
	int arr[]={3,2,1};
	int n=sizeof(arr)/sizeof(int);
	cout<<bestTime2(arr,n);
	return 0;
}