#include<bits/stdc++.h>
#include<cstring>
using namespace std;

// O(N) time and space
int main()
{
   string str1="abbbbbbab";
  string rev=str1; // copy string to rev
  reverse(rev.begin(),rev.end()); // reverse the string
  if(str1==rev){ // and check if they are equal or not
      cout<<"pallindrme";
  } else{
      cout<<"not";
  }
 
    return 0;
}

// stings in c++ are mutable 
bool pallindrome(string &str){
    string rev=str;
     reverse(rev.begin(),rev.end());
    return (rev==str);
}

int main()
{
   string str="aaab";
    if(pallindrome(str)){
        cout<<"pallindrome";
    } else cout<<"not";
 
 
    return 0;
}