#include <bits/stdc++.h>
using namespace std;

void printSubstring(string str,int low,int high){
    for(int i=low;i<=high;i++){
        cout<<str[i];
    }
}

int longestPalSubstr(string &str){
    int n=str.length();
 int maxLen=1;
 int low,high;
 int start=0;
 for(int i=1;i<n;i++){
     high=i;
     low=i-1;
    // even substring
     while(low>=0 && high<n && str[low]==str[high]){
         if(high-low+1>maxLen){
             start=low;
             maxLen=high-low+1;
         }
        low--;
        high++;
     }
    
    //  odd string
     high=i+1;
     low=i-1;
    // even substring
     while(low>=0 && high<n && str[low]==str[high]){
         if(high-low+1>maxLen){
             start=low;
             maxLen=high-low+1;
         }
        low--;
        high++;
     }
 }
     printSubstring(str,start,start+maxLen-1);
     return maxLen;
}

int main() {
    string str = "forgeeksskeegfor";
    cout << longestPalSubstr(str);
	return 0;
}