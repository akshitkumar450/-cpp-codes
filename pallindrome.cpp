// C++ Program to check whether the
// Array is palindrome or not

#include <iostream>
using namespace std;

bool palindrome(int arr[],int n){
    int i=0;
    int j=n-1;
    while(i<j){
        if(arr[i]==arr[j]){
            i++;
            j--;
        } else {
            return false;
        }
    }
    return true;
}

int main()
{
	int arr[] = { 1, 2,  2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

if(	palindrome(arr, n)) cout<<"palindrome";
else cout<<"no";
	return 0;
}
