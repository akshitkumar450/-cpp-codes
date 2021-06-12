#include <iostream>
using namespace std;

int partition(int arr[],int start,int end){

    int i=start-1; 
    int j=start;
    // pivot will be last element
    int pivot=arr[end];
    // go till second last element
    for(;j<=end-1;){
    // while(j<=end-1){   
        // merge smaller part with region -1
        // if the current element is smaller than pivot move to start
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
        // if current element is larger than pivot skip it
        // expand the larger region 
        j++;
    }
    // place the pivot element in the correct position
    swap(arr[i+1],arr[end]);
    // return index of pivot element
    return i+1;
}

void quickSort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    // to get the index of the pivot element
    int p=partition(arr,start,end);
    // smaller  values region
    quickSort(arr,start,p-1);
    // larger values region
    quickSort(arr,p+1,end);
}

int main() {
    int arr[]={5,6,1,2,4,0};
    
    int n=sizeof(arr)/sizeof(int);
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

	return 0;
}
