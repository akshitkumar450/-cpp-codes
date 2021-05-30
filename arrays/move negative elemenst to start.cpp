#include <iostream>
using namespace std;

void removeNegative(int arr1[],int n1) {
    int cnt=0;
    for(int i=0;i<n1;i++) {
        if(arr1[i]<0){
            swap(arr1[i],arr1[cnt]);
            cnt++;
        }
    }
}

int main() {
	int arr1[] ={ -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    removeNegative(arr1,n1);
    for(int i=0;i<n1;i++) {
        cout<<arr1[i]<<" ";
    }
    
	return 0;
}