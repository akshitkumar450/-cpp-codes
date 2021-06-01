#include <bits/stdc++.h>
using namespace std;

void minSwaps(int arr[],int n,int k){
    int i=0;
    int j=n-1;
    int cnt=0;
    while(i<j){
        if(arr[i]<k and arr[j]<=k){
            i++;
        } else if(arr[i]>k and arr[j]<=k){
            swap(arr[i],arr[j]);
            j--;
            i++;
            cnt++;
        } else if(arr[i]>k and arr[j]>k){
            j--;
        }
    }
    cout<<cnt;
}


void minSwapsOptimized(int arr[],int n,int k){
    int good=0;
    int bad=0;
    int minSwap=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<=k) 
            good++;
    }
    for(int i=0;i<good;i++){
        if(arr[i]>k)
            bad++;
    }
    int i=0,j=good-1;
    // sliding window technique
    while(j<n){
        minSwap=min(minSwap,bad);
        j++;
        if(j<n and arr[j]>k)
            bad++;
        if(arr[i]>k) bad--;
        i++;
    }
    if(minSwap==INT_MAX) 
        cout<<0;
    else cout<<minSwap;
    
}

int main() {
	int  arr[] ={2, 7, 9, 5, 8, 7, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 5;
	minSwapsOptimized(arr,n,k);
	return 0;
}