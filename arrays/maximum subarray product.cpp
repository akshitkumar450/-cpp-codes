#include <iostream>
using namespace std;

// O(n^2)
int maxSubarrayProduct(int arr[],int n) {
    int result=arr[0];
    for(int i=0;i<n;i++) {
        int mul=arr[i];
        for(int j=i+1;j<=n;j++) {
            result=max(result,mul);
            mul=mul*arr[j];
        }
        result=max(result,mul);
    }
    return result;
}

// O(N)
int maxSubarrayProductOptimized(int arr[],int n) {
    int minVal=arr[0];
    int maxVal=arr[0];
    int maxPdt=arr[0];
    for(int i=1;i<n;i++) {
        // if the ith element is negative swap the max and miv value
        if(arr[i]<0 ){
            swap(maxVal,minVal);
        } 
            maxVal=max(arr[i],arr[i]*maxVal);
            minVal=min(arr[i],arr[i]*minVal);
            maxPdt=max(maxPdt,maxVal);
        
    }
    return maxPdt;
}

int main() {
   int arr[] = { 1, -2, -3, 0, 7, -8, -2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Sub array product is "
         << maxSubarrayProduct(arr, n);
	return 0;
}