#include <iostream>
using namespace std;

int findMin(int arr1[],int n1){
    int low=0;
    int high=n1-1;
    // check whether if the array is  fully sorted without rotation
    if(arr1[low]<=arr1[high]){
        return arr1[0];
    }
    while(low<=high){
        int mid=(low+high)/2;
        if(arr1[mid]>arr1[mid+1]){
            return arr1[mid+1];
        } else if(arr1[mid]<arr1[mid-1]) {
            return arr1[mid];
            // discard the sorted part bcz min element will not present in the sorted part
        } else if(arr1[low]<=arr1[mid]) {
            low=mid+1;
        } else if(arr1[mid]<=arr1[high]){
            high=mid-1;
        }
    }
    return -1;
}



int main() {
int arr1[] =  {1, 2, 3, 4, 5, 6, 7};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
   cout<< findMin(arr1,n1);
}
