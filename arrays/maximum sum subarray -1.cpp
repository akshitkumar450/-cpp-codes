#include <iostream>
using namespace std;

void maxSumSubarray(int arr[],int n){

    int csum=0;
    int msum=0;
    int left=-1;
    int right=-1;

    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            csum=0;
            for(int k=i;k<=j;k++) {
                csum=csum+arr[k]; //sum of all sub array
            }
            // cout<<csum<<endl;
            // update the max sum if csum > maxsum
            if(csum>msum) {
                msum=csum;
                // for printing the subarray with max sum
                left=i;
                right=j;
            }
        }
    }
    cout<<"maximun sum "<<msum<<endl;
    // print the subarrat=y with maxsum
    for(int k=left;k<=right;k++) {
        cout<<arr[k]<<",";
    }
}

int main() {
       int n;
    cin>>n;

    int arr[1000];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    };
    maxSumSubarray(arr,n);
    // for(int i=0;i<n;i++) {
    //     cout<<arr[i]<<" ";
    // }
}
