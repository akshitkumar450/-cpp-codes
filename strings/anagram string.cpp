#include<bits/stdc++.h>
#include<cstring>
using namespace std;

// anagram means to check permutaion of string and frequency should also be same

// O(nlogn)
bool anagram(string & s1,string &s2){
    if(s1.length() !=s2.length())    return false;
    // sort the strings and after sorting string will be in same order 
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return (s1==s2);
}

// O(N)
bool anagram2(string & s1,string &s2){
    if(s1.length() !=s2.length())    return false;
    // using characters as index
    char count[256]={0}; // create a count array for storing frequecies of characters
    for(int i=0;i<s1.length();i++){
        count[s1[i]]++; // increment the count of char in s1
        count[s2[i]]--; // decrement the count of char in s1
    }

// if the strings are anagram then all frequency should be zero by now 
    for(int i=1;i<256;i++){
        if(count[i]!=0) return false; // if the two strings are anagram then each element frequency must be same
    }
    return true;

}

int main() {
    string s1="gekse";
    string s2="geeks";
    if(anagram(s1,s2)){
        cout<<"anagram";
    } else{
        cout<<"not a anagram";
    }
	return 0;
}