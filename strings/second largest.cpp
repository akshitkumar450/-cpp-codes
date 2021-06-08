#include <iostream>
using namespace std;

int getlargest(int arr[],int n) {
    int largest=0;
    for(int i=1;i<n;i++) {
        if(arr[i]>arr[largest]){
            largest=i;
        }
    }
    return largest;
}

int getSecondLargest(int arr[],int n) {
    int max=getlargest(arr,n);
    // return -1 if all elements are same
    int res=-1;
    for(int i=0;i<n;i++) {
        // to check only for values which is not equal to largest element
        if(arr[i]!=arr[max]) {
            // for first traversal 
            if(res==-1) 
                res=i;
            else if(arr[i]>arr[res]) 
                res=i;
        }
    }
    return res;
}

int main() {
 
 int arr []={50,5,4,30};
 int n=4;
 cout<<getSecondLargest(arr,n);
}
