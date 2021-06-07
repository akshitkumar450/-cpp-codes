#include <bits/stdc++.h>
using namespace std;

bool iso(string A,string B){
   int n=B.length();
    int m=A.length();
    if(n!=m) return false;
    // to check whether this character is mapped with anyone or not
    char mapping[256];
    memset(mapping,-1,sizeof(mapping));
    // to check whether  this character is marked with any previous character
    bool marked[256]={false};
    
    for(int i=0;i<n;i++){
        // means this character is seen first time
        if(mapping[A[i]]==-1){
           if(marked[B[i]]==true){
               return false;
           } else{
               mapping[A[i]]=B[i];
               marked[B[i]]=true;
           }
        }
        else if(mapping[A[i]]!=B[i]){
            return false;
        }
    }  
  return true;
}

int main() {
	 string A = "aab";
    string B = "xzy";
     if(iso(A, B)){
         cout<<"iso";
     } else cout<<"no";
	return 0;
}