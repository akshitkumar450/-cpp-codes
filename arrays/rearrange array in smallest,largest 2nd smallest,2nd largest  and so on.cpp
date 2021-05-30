#include <iostream>
#include <algorithm>

using namespace std;
 
void rearrangeArray(int arr[],int n) {
    int k=0;
    int temp[n];
    sort(arr,arr+n);
    for(int i=0,j=n-1;i<n/2 || j>=n/2;i++,j--) {
        temp[k]=arr[i];
        k++;
         temp[k]=arr[j];
        k++;
    }
  
     for (int i = 0; i < n; i++) 
        arr[i] = temp[i];
}

int main() {
      int arr[] = { 5, 8, 1, 4, 2, 9, 3, 7, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrangeArray(arr, n);
        for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
}
