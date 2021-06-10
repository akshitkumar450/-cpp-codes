#include <bits/stdc++.h>
using namespace std;

int maxi(int arr[], int idx, int n){
    // at last there is only one element this is the only max
    if(idx==n-1) return arr[n-1];
    int misa=maxi(arr,idx+1,n);
    return max(misa,arr[idx]);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int p = maxi(arr, 0, n);
    cout << p << endl;
}
