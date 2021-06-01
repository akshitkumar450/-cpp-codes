#include <iostream>
using namespace std;

int findMinOps(int arr[],int n){
    int i=0;
    int j=n-1;
    int ans=0;
    while(i<=j){
        // if both are same move them
        if(arr[i]==arr[j]){
            i++;
            j--;
            // if left is smaller 
            // then move left ahead and merge it with the left element;
        } else if(arr[i]<arr[j]){
            i++;
            arr[i]=arr[i]+arr[i-1];
            ans++;
            // if right is smaller
            // then move right ahead and merge it with right element
        } else if(arr[i]>arr[j]){
            j--;
            arr[j]=arr[j]+arr[j+1];
            ans++;
        }
    }
    return ans;
}

int main() {
	 int arr[] = {1, 4, 5, 9, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Count of minimum operations is "
         <<  findMinOps(arr, n) << endl;
	return 0;
}