#include <bits/stdc++.h>
using namespace std;


string secMostRepeated(vector<string>&str){
    unordered_map<string,int>mp;
    for(int i=0;i<str.size();i++){
        mp[str[i]]++;
    }
    
    int firstMax=INT_MAX,secMax=INT_MAX;
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second >firstMax){
            secMax=firstMax;
            firstMax=it->second;
        } else if(it->second > secMax and it->second!=firstMax){
            secMax=it->second;
        }
    }
    
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second==secMax){
            return it->first;
        }
    }
    
}

int main() {

vector<string> seq = { "ccc", "aaa", "ccc",
                          "ddd", "aaa", "aaa" };
    cout << secMostRepeated(seq);
	
	return 0;
}