#include <iostream>
using namespace std;

// The idea is to process the array and shift all negative values to the end in O(n) time.
//  After all negative values are shifted to the end, we can easily rearrange array in alternating positive & negative items.
//  We basically swap next positive element at even position from next negative element in this step.

void rearrange(int arr[],int n) {
    int i=0;
    int j=n-1;
    // move all negative elements to end and positive elements to start
    while(i<=j) {
        if(arr[i]> 0 && arr[j] <0){{
            i++;
            j--;
        }
        
        } else if(arr[i] > 0 && arr[j]>0) {
            i++;
        } else if(arr[i]<0 &&arr[j]<0  ){
            j--;
        } else {
            swap(arr[i],arr[j]); 
                i++;
                j--;
        }
    }
    // after this while loops end i will point to the first negative element 
    // if i==0 measns is in starting and all elements are negative and if i==n means all elements are positve
    // no needs for swapping in these cases 

    if(i==0 || i==n) {
        	for(int i=0;i<n;i++) {
	         cout<<arr[i]<<" ";
    	}
    } 
    // after moving elements i will be at starting position where negative elements start
    else {
          int k=0;
    while(k<n && i<n) {
        swap(arr[k],arr[i]) ;
        i++;
        k+=2;
    }
    }
  
}

int main() {
 int arr[] = {2, 3, -4, -1, 6, -9};
	int n =sizeof(arr)/sizeof(int);
	rearrange(arr,n);
	for(int i=0;i<n;i++) {
	    cout<<arr[i]<<" ";
	}
	return 0;
}