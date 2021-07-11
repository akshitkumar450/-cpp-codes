
#include <bits/stdc++.h>
using namespace std;

// first reverse individual words 
// then reverse string from start to end

string reverseWords(string str) 
    { 
          int n=str.length();
          string temp;
           int si=0;
           int ei=0;
           while(ei<=n){
               if(ei<n and str[ei]!=' '){
                   ei++;
               } else{
                   for(int j=ei;j>=si;j--){
                    //  cout<<str[j];
                    temp=temp+str[j];
                    }
                    // cout<<" ";
                    temp+=' ';
        			ei++;
        			si=ei;
               }
           }
          reverse(temp.begin(),temp.end());
          return temp;
    } 

int main()
{
	string str = "getting good at coding ";
	cout<<reverseWords(str);
}

