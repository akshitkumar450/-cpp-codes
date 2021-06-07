#include <iostream>
using namespace std;

int minOps(string A ,string B){
    int n=B.length();
    int m=A.length();
    if(n!=m) return -1;
    
   int count[256]={0};
    for(int i=0;i<n;i++){
        count[A[i]]++;
    }
    for(int i=0;i<n;i++){
        count[B[i]]--;
    }
    
    for(int i=0;i<n;i++){
       if(count[i]>0)
        return -1;
    }
    
    int res=0;
    for(int i=n-1, j=n-1;i>=0; ){
        while(i>=0 and A[i]!=B[j]){
            i--;
            res++;
        }
        // if match
        if(i>=0 and A[i]==B[j]){
            i--;
            j--;
        }
    }
    return res;
}
int main() {
	 string A = "abd";
    string B = "bad";
     cout << "Minimum number of operations "
            "required is " << minOps(A, B);
	return 0;
}