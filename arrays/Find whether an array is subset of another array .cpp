#include <bits/stdc++.h>
using namespace std;
 

// Method 1 (Simple): 
// Use two loops: The outer loop picks all the elements of arr2[] one by one.
//  The inner loop linearly searches for the element picked by the outer loop.
//  If all elements are found then return 1, else return 0.

// O(NM)
bool isSubset(int arr1[],int m,int arr2[],int n) {
    // outer loop picks element from arr2
    // inner lopp from arr1
    int j;
    for(int i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(arr1[j]==arr2[i]) {
                break;
            } 
        }
        // means element from arr2 is not in arr1
        // arr1 has comes to end 
          if(j==m) {
                return 0;
            }
    }
    return 1;
}

//  O(mLogm + nLogn)
bool isSubset2(int arr1[],int m,int arr2[],int n) { 
    int i=0,j=0;
// i for arr2
//  j for arr1
    sort(arr1,arr1+m);
    sort(arr2,arr2+n);
    while(i<n and j<m) {
            // If the element is smaller than
            // Move aheaad in the first array
        if(arr1[j]<arr2[i]) {
            j++;
              // If both are equal, then move
              // both of them forward
        } else if(arr1[j]==arr2[i]) {
            i++;
            j++;
             // If we donot have a element smaller
             // or equal to the second array then break
        } else if(arr1[j]> arr2[i]) {
            return false;
        }
    }
    return (i<n )?"false":"true";
    
}


string isSubset(int a1[], int a2[], int n, int m) {
    set<int>st;
    for(int i=0;i<n;i++) {
        st.insert(a1[i]);
    }
    for(int j=0;j<m;j++) {
        if(st.find(a2[j])==st.end()) {
            return "No";
        }
    }
    return "Yes";
}

int main() {
    int arr1[] = { 11, 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1 };
 
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    if(isSubset2(arr1,m,arr2,n)) cout<<"isSubset"; 
    else cout<<"not isSubset";
	return 0;
}