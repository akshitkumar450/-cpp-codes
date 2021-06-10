#include<iostream>
using namespace std;

int firstIndex(int arr[], int idx, int x, int n){
    if(idx==n){
        return -1;  // at last  if the element is not present
    }
    // here we are checking while returning
    int firstIdx=firstIndex(arr,idx+1,x,n);
    if(arr[idx]==x){
        return idx;
    } else {
        return firstIdx;
    }
    
}

// better approach
int firstIndex(int arr[], int idx, int x, int n){
    if(idx==n){
        return -1; // at last  if the element is not present
    }
    // first check and then call bcz we have to find the first index
    // no point for checking till the last
    if(arr[idx]==x){
        return idx;
    }
    else {
        int firstIdx=firstIndex(arr,idx+1,x,n);
        return firstIdx;
    }
    
}

int main()
{
    int n;
    cin >> n;
    int d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;
    int p = firstIndex(arr, 0, d, n);
    cout << p << endl;
}