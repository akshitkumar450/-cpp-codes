#include <iostream>
using namespace std;

int find(int arr[],int start,int end,int target) {
    if(start >end){
        return -1;
    }
    int mid=(start+end)/2;
    if(arr[mid]==target) {
        return mid;
    } 
     if(arr[start]<=arr[mid]) {
        if(target>=arr[start] && target<=arr[mid]) {
            return find(arr,start,mid-1,target);
        } else{
            return find(arr,mid+1,end,target);
        }
    } 
    if(arr[mid]<=arr[end]) {
        if(target>=arr[mid] && target<=arr[end]){
            return find(arr,mid+1,end,target);
        } else {
            return find(arr,start,mid-1,target);
        }
    }
}

int main() {
     int arr[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    cin>>target;
   cout<< find(arr,0,n-1,target);
}
