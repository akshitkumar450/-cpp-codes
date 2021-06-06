#include<bits/stdc++.h>
#include<cstring>
using namespace std;

bool pallindrome(string &str){
  int start=0;
  int end=str.length()-1;
  while(start<end){
      if(str[start]==str[end]){
          start++;
          end--;
      }
        else{
            return false;
        }
  }
  return true;
}

int main()
{
   string str="aaa";
   if(pallindrome(str)){
       cout<<"pallindrom";
   } else{
       cout<<"not";
   }
   
}