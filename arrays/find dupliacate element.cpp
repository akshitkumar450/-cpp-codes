#include <bits/stdc++.h>
using namespace std;

int duplicate(int arr[],int n) {
    sort(arr,arr+n);
    for(int i=1;i<n;i++) {
        if(arr[i]==arr[i-1])
        return arr[i];
    }
    return -1;
}

int duplicate1(int arr[],int n) {
       set<int>s;
    for(int i=0;i<n;i++) {
        // if element is found in the set
        if(s.find(arr[i]!=s.end()) {
            return arr[i];
        } else {
            s.insert(arr[i]);
        }
    }
}

int main() {
 
 int arr []={100,30,1,30,40};
 int n=5;
 cout<<duplicate(arr,n);
}
