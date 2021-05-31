#include <iostream>
using namespace std;

void rearrange(int arr[],int n) {
    int i=0;
    int j=n-1;
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
}

int main() {
	int arr[]={1,2,3,-4,1,-4};
	int n =sizeof(arr)/sizeof(int);
	rearrange(arr,n);
	for(int i=0;i<n;i++) {
	    cout<<arr[i]<<" ";
	}
	return 0;
}