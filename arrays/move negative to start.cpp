#include <iostream>
using namespace std;

// variables like left and right which hold the 0 and N-1 indexes. Just need to check that :

//     Check If the left and right pointer elements are negative then simply increment the left pointer.
//     Otherwise, if the left element is positive and the right element is negative then simply swap the elements, and simultaneously increment and decrement the left and right pointers.
//     Else if the left element is positive and the right element is also positive then simply decrement the right pointer.
//     Repeat the above 3 steps until the left pointer ≤ right pointer.


void moveNegative(int arr1[],int n1) {
    int i=0,j=n1-1;
    while(i<=j) {
        if(arr1[i]<0 && arr1[j]<0) {
            i++;
        } else if(arr1[i]> 0 && arr1[j]<0) {
            int temp=arr1[i];
            arr1[i]=arr1[j];
            arr1[j]=temp;
            i++;
            j--;
        } else if(arr1[i]>0 && arr1[j]>0) {
            j--;
        } else {
            i++;
            j--;
        }
    }
}

int main() {
	int arr1[] ={ -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    // removeNegative(arr1,n1);
    moveNegative(arr1,n1);
    for(int i=0;i<n1;i++) {
        cout<<arr1[i]<<" ";
    }
    
	return 0;
}