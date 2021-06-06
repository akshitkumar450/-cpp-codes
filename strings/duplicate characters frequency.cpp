#include <bits/stdc++.h>
using namespace std;

void duplicate(string &str){
 map<char,int>mp;
 for(int i=0;i<str.length();i++){
     mp[str[i]]++;
 }
 for(auto it=mp.begin();it!=mp.end();it++){
     if(it->second>1){
         cout<<it->first<<" "<<it->second<<endl;;
     }
 }
}

int main() {
    string str="geeksforgeeks";
    duplicate(str);
    
	return 0;
}