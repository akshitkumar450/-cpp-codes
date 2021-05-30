#include <iostream>
using namespace std;

void mergeArrays(int arr1[],int arr2[],int n1,int n2,int arr3[]) {
    int i=0;int j=0;int k=0;
    while(i<n1 && j <n2) {
        if(arr1[i]<arr2[j]) {
            arr3[k]=arr1[i];
            i++;
            k++;
        } else if(arr1[i]>arr2[j]) {
            arr3[k]=arr2[j];
            j++;
            k++;
        }
    } 
    while(i<n1) {
        arr3[k]=arr1[i];
        k++;
        i++;
    }
    while(j<n2) {
        arr3[k]=arr2[j];
        k++;
        j++;
    }
}

int main() {
	int arr1[] = {0,1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
 
    int arr2[] = {2, 4, 6, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
 
    int arr3[n1+n2];
    mergeArrays(arr1, arr2, n1, n2, arr3);
        cout << "Array after merging" <<endl;
    for (int i=0; i < n1+n2; i++)
        cout << arr3[i] << " ";
	return 0;
}