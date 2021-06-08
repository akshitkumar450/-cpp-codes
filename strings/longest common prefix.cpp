#include <bits/stdc++.h>
using namespace std;

int getMinLen(string str[],int n){
    int min=str[0].length();
    
    for(int i=1;i<n;i++){
        if(str[i].length()<min){
            min=str[i].length();
        }
    }
    return min;
}

string commonPrefix(string str[],int n){
    int minLen=getMinLen(str,n);
    int current;
    string result="";
    for(int i=0;i<minLen;i++){
        current=str[0][i];
        
        for(int j=1;j<n;j++){
            if(str[j][i]!=current){
                return result;
            }
        }
        result+=current;
    }
    return result;
}

int main() {
string arr[] = {"geeksforgeeks", "geeks",
                    "geek", "geezer"};
	    int n = sizeof (arr) / sizeof (arr[0]);
	   cout<< commonPrefix(arr,n);
	return 0;
}