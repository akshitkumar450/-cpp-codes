#include <iostream>
using namespace std;

void maxSumSubarray(int arr[],int n,int cumSum[]){

    int csum=0;
    int msum=0;
    int left=-1;
    int right=-1;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            csum=0;

            csum=cumSum[j]-cumSum[i-1];
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
int cumSum[1000]={0};

    int arr[1000];
    // taken first value manually
    cin>>arr[0];
    cumSum[0]=arr[0];  // cummilative sum  // first value of current sum array should be same as array
    for(int i=1;i<n;i++) {
        cin>>arr[i];
        cumSum[i]=cumSum[i-1]+arr[i]; // calcualting the cummulative sum
    };
    maxSumSubarray(arr,n, cumSum);
}
