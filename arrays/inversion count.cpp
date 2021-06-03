#include <iostream>
using namespace std;

int merge(int arr[],int start,int end){
    int mid=(start+end)/2;
    int i=start;
    int j=mid+1;
    int k=start;
    int temp[1000];
    
    int invcnt=0;
    
    while(i<=mid and j<=end){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;
            k++;
        } else {
            // main line  to count inversions
            invcnt+=mid-i+1;
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
    return invcnt;
}


int mergesort(int arr[],int start,int end){
    if(start>=end){
        return 0;
    }
    int mid=(start+end)/2;
   int x= mergesort(arr,start,mid);
   int y= mergesort(arr,mid+1,end);
   int z= merge(arr,start,end);
   return x+y+z;
}

int main() {
	 int arr[] = { 1, 20, 6, 4, 5 };
	int n = sizeof(arr) / sizeof(int);
    cout<<mergesort(arr,0,n-1);
	
	return 0;
}