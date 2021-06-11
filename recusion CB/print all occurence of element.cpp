#include <iostream>
using namespace std;

// store occurence in the array
int storeOcc(int arr[],int n,int idx,int key,int out[],int j){
    //if we reached end means we have stored all the occurences then return the size of out array
    if(idx==n){
        return j;
    }
    if(arr[idx]==key){
        // if the element is found then store its index in the out array and increment both i and j
        out[j]=idx;
        return storeOcc(arr,n,idx+1,key,out,j+1);
    } 
    // if the element is not found then increment only i
    return storeOcc(arr,n,idx+1,key,out,j);
}

void allOcc(int arr[],int n,int idx,int key){
    if(idx==n){
        return;
    }
    if(arr[idx]==key){
        cout<<idx<<" ";
    } 
    allOcc(arr,n,idx+1,key);
}

int main() {
	int arr[]={1,2,3,7,2,3,7};
	int n=7;
	int key=7;
// 	allOcc(arr,n,0,key);
    int out[100];
	int cnt=storeOcc(arr,n,0,key,out,0);
	for(int k=0;k<cnt;k++){
	    cout<<out[k]<<" ";	
	    
	}
	
	return 0;
}