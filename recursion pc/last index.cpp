#include <iostream>
using namespace std;

int lastIndex(int arr[], int idx, int x, int n){
    if(idx==n){
        return -1; // at last if the element is not present return -1;
    }
    int liisa=lastIndex(arr,idx+1,x,n);
    if(liisa==-1){ // -1 means element has not find the smaller array
        if(arr[idx]==x){ // check it with first element
            return idx; // if found return the index
        } else{ 
            return -1; // if not found return  -1
        }
    } else{
        return liisa;  // means if the index is found in the smaller array return the index 
    }
}

int main(){
    int n;
    cin >> n;
    int d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;
    int p = lastIndex(arr, 0, d, n);
    cout << p << endl;
}