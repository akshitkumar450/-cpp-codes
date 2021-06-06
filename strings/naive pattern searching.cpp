#include<bits/stdc++.h>
#include<cstring>
using namespace std;

// O((n-m+1)*m)
void naiveSearch(string &text,string &pat){
    int n=text.length();
    int m=pat.length();

    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(pat[j]!=text[i+j]){
                break;
            }
        }
        // if j has reached end of pattern means we have seached all characters of pattern
        if(j==m){
            cout<<i<<" ";
        }
    }
}



int main() {
    string text="abcdabc";
    string pat="abc";
   naiveSearch(text,pat);
    
   
}