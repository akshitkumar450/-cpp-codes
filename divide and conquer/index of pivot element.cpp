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
            // if value from mid to high in increasing 
            // then pivot will be in left(start) to mid part
            if(A[mid]<A[hi]){
                hi=mid;
            } else {
                // if value from mid to high in decreasing 
                // pivot will be in mid to right part(end)
                lo=mid+1;
            }
        }
        cout<<hi; // index of the pivot element

}
