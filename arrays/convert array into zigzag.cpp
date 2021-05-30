#include <iostream>
using namespace std;

void zigzag(int arr1[],int n1) {
bool flag=true;
for(int i=0;i<n1-1;i++){
    if(flag){ // expected <
        if(arr1[i]>arr1[i+1]) {
            swap(arr1[i],arr1[i+1]);
        }
    } 
    else { // expected >
        if(arr1[i]<arr1[i+1]){
            swap(arr1[i],arr1[i+1]);
        }
    }
    flag=! flag;
}
}

int main() {
	int arr1[] = {4, 3, 7, 8, 6, 2, 1};;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
  zigzag(arr1,n1);
    for(int i=0;i<n1;i++) {
        cout<<arr1[i]<<" ";
    }
    
	return 0;
}