#include <bits/stdc++.h>
using namespace std;

// 1) Use two index variables i and j, initial values i = 0, j = 0 
// 2) If arr1[i] is smaller than arr2[j] then print arr1[i] and increment i. 
// 3) If arr1[i] is greater than arr2[j] then print arr2[j] and increment j. 
// 4) If both are same then print any of them and increment both i and j. 
// 5) Print remaining elements of the larger array.

void printUnion(int arr1[],int arr2[],int m,int n) {
    int i=0,j=0;
    while(i<m && j<n) {
        if(arr1[i]<arr2[j]) {
            cout<<arr2[i]<<" ";
            i++;
        } else if(arr1[i]>arr2[j]) {
            cout<<arr2[j]<<" ";
        } else {
            // means both are equal so print any of them and increment both
            cout<<arr2[j]<<" ";
            i++;
            j++;
        }
    }
    // elements left in first array
    while(i<m) {
        cout<<arr1[i]<<" ";
        i++;
    }
    // element left  in second array
    while(j<n) {
        cout<<arr2[j]<<" ";
        j++;
    }
} 

void printIntersection(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else /* if arr1[i] == arr2[j] */
        { // print only when they are equal
            cout << arr2[j] << " ";
            i++;
            j++;
        }
    }
}
int main() {
 int arr1[] = { 1, 2, 4, 5, 6 };
    int arr2[] = { 2, 3, 5, 7 };
 
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
 
    // Function calling
    printUnion(arr1, arr2, m, n);
}