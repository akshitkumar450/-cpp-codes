
#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    return (c=='a' || c=='A' || c=='e' ||
            c=='E' || c=='i' || c=='I' ||
            c=='o' || c=='O' || c=='u' ||
            c=='U');
}

// first reverse the string and then remove vowels
string reverseVowels(string str) 
    { 
          int n=str.length();
         reverse(str.begin(),str.end());
           
            string temp;
        	for (int i = 0;i<n; i++){
        		if(!isVowel(str[i])){
        		    temp=temp+str[i];
        		}
        	}
        	str=temp;
        	return str;
        // 	cout<<str;
    
    } 

int main()
{
	string str = "geeksforgeeks";
	cout<<reverseVowels(str);
}

