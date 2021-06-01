#include <bits/stdc++.h>
using namespace std;

int findMinDiff(int arr[],int n,int m){
    if(m==0 || n==0) return 0;
    sort(arr,arr+n);
    if(m>n){
        return -1;
    }
    int minDiff=INT_MAX;
    for(int i=0;i+m-1<n;i++){
        int diff=arr[i+m-1]-arr[i];
        if(diff<minDiff) {
            minDiff=diff;
        }
    }
    return minDiff;
}

int main() {
 int arr[] = { 12, 4,  7,  9,  2,  23, 25, 41, 30,
                  40, 28, 42, 30, 44, 48, 43, 50 };
    int m = 7; // Number of students
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is "
         << findMinDiff(arr, n, m);
	return 0;
}