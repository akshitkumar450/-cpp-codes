#include <bits/stdc++.h>
using namespace std;

bool rotation(string &s1,string &s2){
    if(s1.length()!=s2.length()) return false;
    string temp=s1+s1;
    return (temp.find(s2)!=string::npos);
}

int main() {
  string str1 = "AACD", str2 = "DAAA";
 if(rotation(str1,str2)){
     cout<<"is rotated";
 } else {
     cout<<"not rotated";
 }
    
	return 0;
}