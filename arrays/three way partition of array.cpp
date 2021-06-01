#include <bits/stdc++.h>
using namespace std;

void threeWayPartition(int arr[],int n,int low,int high){
    int start=0;
    int end=n-1;
    for(int i=0;i<=end; ){
        // if current elemnt is less than the lower limit 
        // swap the cur elemnt with starting value of array and incerment both
        if(arr[i]<low){
            swap(arr[i],arr[start]);
            i++;
            start++;
            // if the current value is more than the higher limit
            // swap the current element with end value and decrement only end
        } else if(arr[i]>high){
            swap(arr[i],arr[end]);
            end--;
        }  else {
            i++;
        }
    }
}

int main() {
 int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87,
                98, 3, 1, 32};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    threeWayPartition(arr, n, 10, 20);
    cout << "Modified array \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
	return 0;
}