#include<bits/stdc++.h>
#include<cstring>
using namespace std;

bool subsequence(string & s1,string &s2){
   int i=0,j=0;
    if(s1.length()<s2.length()) return false;
    while(i<s1.length() && j<s2.length()) {
        if(s1[i]==s2[j]){
            i++;
            j++;
        } else {
            i++;
        }
    }
    
    if(j==s2.length()) 
        return true; ;
     
    return false;
}

// O(m+n)
int main() {
    string s1="geeksforgeeks";
    string s2="grges";
    if(subsequence(s1,s2)){
        cout<<"subsequence";
    } else{
        cout<<"not a subsequence";
    }
	return 0;
}