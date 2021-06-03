#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[],int n){
    unordered_set<int> st;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        // if the sum is zero or we have find an element which is already in set.
        //  which means from the current index till the last index of that element the sum if 0
        if(sum==0 || st.find(sum)!=st.end()){
            return true;
        } else {
            // if sum is not present ,then push it 
            st.insert(sum);
        }
    }
     return false;
}

int main() {
 int arr[] = { -3, 2, 3, 1, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    if (subArrayExists(arr, n))
        cout << "subarray with 0 sum";
    else
        cout << "No Sub Array ";
    return 0;
}