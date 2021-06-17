#include <iostream>
using namespace std;

bool isSorted(int arr[],int n){
    if(n==0 or n==1) return true;
    
    // check if the first array is sorted then only call for next 
    if(arr[0]<arr[1] and isSorted(arr+1,n-1)){
        return true;
    } else {
        return false;
    }
}

bool isSorted(int si, int arr[], int n) {
	//BASE CASE
	if (si == n - 1 or n == 0) {
		return true;
	}

	//RECURSIVE CASE
	bool isSubproblemSorted = isSorted(si + 1, arr, n);

	if (arr[si] <= arr[si + 1] and isSubproblemSorted) {
		return true;
	} else {
		return false;
	}

	//RECURSIVE CASE
	// if (arr[si] > arr[si + 1]) {
	// 	return false;

	// } else {
	// 	// check for the rest of the array
	// 	bool isSubproblemSorted = isSorted(si + 1, arr, n);
	// 	// if (isSubproblemSorted) {
	// 	// 	return true;
	// 	// } else {
	// 	// 	return false;
	// 	// }
	// 	return isSubproblemSorted;
	// }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(isSorted(arr,n)){
        cout<<"sorted";
    } else{
        cout<<"not sorted";
    }
	return 0;
}