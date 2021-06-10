#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<string> gss(string s){
    // smallest subsequence when length is 0 is 1 which is empty string
    if(s.length()==0){
        vector<string>baseRes; // make the vector add empty string to it
        baseRes.push_back("");  // add empty string
        return baseRes;
    }
    // get the first character from string
    char ch=s[0];
    string ros=s.substr(1); // remove the first character from string
    vector<string>rres=gss(ros); // call for removed string
    
    vector<string>mres; // make vector for storing result
    for(string rstr:rres){
        mres.push_back(""+rstr); // first add "" when  a is not coming
    }
    for(string rstr:rres){
        mres.push_back(ch+rstr);  // add when a is coming
    }
    return mres;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}