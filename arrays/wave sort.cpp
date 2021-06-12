#include <bits/stdc++.h>
using namespace std;

int main() {
	    int arr[100];
	    int n;
	    cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        for (int i = 0; i < n; i+=2) {
            // check with previous element  only if i>0
            if(i!=0 and arr[i]<arr[i-1]){
                swap(arr[i],arr[i-1]);
            }
            // for next element only i<n-1
            if(i!=n-1 and arr[i]<arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
       
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }

	return 0;
}