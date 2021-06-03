#include <iostream>
using namespace std;

void merge(int arr[],int start,int end){
    int mid=(start+end)/2;
    int i=start;
    int j=mid+1;
    int k=start;
    int temp[100];
    
    while(i<=mid and j<=end){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;
            k++;
        } else {
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=end){
        temp[k]=arr[j];
        j++;
        k++;
    }
    
    for(int x=start;x<=end;x++){
        arr[x]=temp[x];
    }
}


void mergesort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int mid=(start+end)/2;
    
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    merge(arr,start,end);
}

int main() {
	int  arr[] ={2, 7, 9, 5, 8, 7, 4,77,51};
	int n = sizeof(arr) / sizeof(int);
	mergesort(arr,0,n-1);
	for(int i=0;i<n;i++){
	    cout<<arr[i]<<",";
	}
	return 0;
}