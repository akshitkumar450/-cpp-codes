#include <bits/stdc++.h>
using namespace std;

void nbyK(int arr[],int n,int k){
    int cnt;
    for(int i=0;i<n;i++){
        cnt=0;
        for(int j=i;j<n;j++){
            if(arr[i]==arr[j]) 
                cnt++;
            if(cnt>n/k){
                cout<<arr[i]<<" ";
                break;
            }
        }
    }
}

void nbyK2(int arr[],int n,int k){
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    
    for(auto it=mp.begin();it!=mp.end();it++){
        // cout<<it->first<<"-"<<it->second<<endl; 
        if(it->second >n/k) {
            cout<<it->first<<endl;
        } 
    }
}

int main() {
	int arr[]={ 1, 1, 2, 2, 3, 5,
                  4, 2, 2, 3, 1, 1, 1 };
   int n = sizeof(arr) / sizeof(arr[0]);
	int k=4;
	nbyK2(arr,n,k);
	return 0;
}