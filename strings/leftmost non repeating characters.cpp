#include<bits/stdc++.h>
#include<cstring>
using namespace std;


int leftmostnonRepeating(string &s1){
    char count[256]={0};
    // creating the frequency for the elements
    for(int i=0;i<s1.length();i++){
        count[s1[i]]++;
    }
    for(int i=0;i<s1.length();i++){
        if(count[s1[i]]==1) {
            return i;
        }
    }
    return -1;
}


int leftmostRepeating2(string &s1){
    char firstIndex[256]={0};
    // fill the firstIndex array as -1 in start
    fill(firstIndex,firstIndex+256,-1);
    int res=INT_MAX; 
     for(int i=0;i<s1.length();i++){
        //  use characters as index
         int fi=firstIndex[s1[i]];
         if(fi==-1){  // if the character is seen first seen then update it with index
             firstIndex[s1[i]]=i;
         } else{ 
             firstIndex[s1[i]]=-2; // means it repeating character  and occuring again
         }
    }

    for(int i=0;i<256;i++){
        if(firstIndex[i]>=0){
            res=min(res,firstIndex[i]);
        }
    }
    return(res==INT_MAX)?-1:res; // if all the characters are distinct then the res will be INTMAX only
}


int main() {
    string s1="abcd";
    cout<<leftmostnonRepeating(s1);
   
}