#include <bits/stdc++.h>
using namespace std;
int main() {
          int A[] = {5, 6, -1, 2, 3, 4};
    int sum = 16;
    int n = sizeof(A) / sizeof(int);
        int lo=0;
        int hi=n-1;
        while(lo<hi) {
            int mid=(lo+hi)/2;
            if(A[mid]<A[hi]){
                hi=mid;
            } else {
                lo=mid+1;
            }
        }
        cout<<hi; // index of the pivot element

}
