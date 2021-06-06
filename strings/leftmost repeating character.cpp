#include<bits/stdc++.h>
#include<cstring>
using namespace std;

// O(n^2)
int leftmostRepeating(string &s1){
    // consider every character
    for(int i=0;i<s1.length();i++){
        for(int j=i+1;j<s1.length();j++){
            if(s1[i]==s1[j])
            return i;
        }
    }
    return -1;
}

// O(n)
int leftmostRepeating2(string &s1){
    char count[256]={0};
    // creating a frequency array 
    for(int i=0;i<s1.length();i++){
        count[s1[i]]++;
    }
    // return the first character index with frequency >1
    for(int i=0;i<s1.length();i++){
        if(count[s1[i]]>1) return i;
    }
    return -1;
}

int leftmostRepeating3(string &s1){
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
             res=min(res,fi);  // res storing the first occuerence of the character
         }
    }
    return(res==INT_MAX)?-1:res; // if all the characters are distinct then the res will be INTMAX only
}

// most optimal 
int leftmostRepeating4(string &s1){
    bool visited[256]={0}; // a visited array
    fill(visited,visited+256,false); //initially all false means not visited
    int res=-1;
    for(int i=s1.length()-1;i>=0;i--){
        if(!visited[s1[i]]){ // if an element is not visited we mark it as visited
            visited[s1[i]]=true;
        } else {  // if it already visited we store the index of it and since we are traversing from right the left most character will be encountered at last
            res=i;
        }
    }
    return res;
}

int main() {
    string s1="geeksforgeeks";
       cout<<leftmostRepeating(s1);
   
}