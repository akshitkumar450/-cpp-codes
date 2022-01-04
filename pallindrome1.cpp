// CPP implementation to check
// if an array is PalinArray or not
#include<bits/stdc++.h>
using namespace std;

	// Function to check if palindrome or not
	bool isPalindrome(int N)
	{
		string str = "" + N;
		int j = str.length()-1;
		int i=0;
		while(i<j){
		    if(str[i]==str[j]){
		        i++;
		        j--;
		    } else{
		        return false;
		    }
		}
		return true;
	}

	// Function to check
	// if an array is PalinArray or not
	bool isPalinArray(int arr[] , int n)
	{
		// Traversing each element of the array
		// and check if it is palindrome or not
		for (int i = 0; i < n; i++) {
			bool ans = isPalindrome(arr[i]);
			if (ans == false)
				return false;
		}
		return true;
	}

	// Driver code
	int main()
	{
		int arr[] = {111, 121, 222, 333, 444} ;

		// length of array
		int n = sizeof(arr)/sizeof(arr[0]);

		bool res = isPalinArray(arr, n);
		if (res == true)
			cout<<"Array is a PalinArray";
		else
			cout<<"Array is not a PalinArray";
	}
