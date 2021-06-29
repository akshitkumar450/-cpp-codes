#include <iostream>
#include<algorithm>
using namespace std;

int minSum(int *arr,int n) {
    sort(arr,arr+n);
    int num1=0;
    int num2=0;
    for(int i=0;i<n;i++) {
        // even indexed number for num1
        if(i%2==0) {
            num1=num1*10+arr[i];
        }
        else {
        // odd indexed number for num1
            num2=num2*10+arr[i];
        }
    }
    return num1+num2;
}

int main() {
     int arr[] = {5, 3, 0, 7, 4};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    cout<<"The required sum is  "<<minSum(arr, n)<<endl;  
    return 0; 
}
