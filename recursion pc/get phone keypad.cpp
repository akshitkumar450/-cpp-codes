#include <bits/stdc++.h>
using namespace std;

static string codes[]={".;"," abc","def"," ghi","jkl","mno","pqrs","tu","vwx","yz"};
vector<string> kpc(string str){
    //  when no key is pressed then we assume 1 char which is empty string
    if(str.length()==0){
        vector<string>bres;
        bres.push_back(""); // add the empty string and return it
        return bres;
    }
    // extract the first char
    char ch=str[0];
    string ros=str.substr(1); //  remove the first char
    
    vector<string>res=kpc(ros); // store the result 
    vector<string>mres; 
    
    // bcz ch is char ..ch-'0' will give the index of the first char
    string charcodes=codes[ch-'0']; // getting the index of string from codes array
    for(int i=0;i<charcodes.length();i++){
        char code=charcodes[i]; // get the string for the first char
        for(string s:res){
            mres.push_back(code + s); // combile each char of the first string will all the chars in res
        }
    }
}

int main() {
// 	string str="678";
    string str;
    cin>>str;
    vector<string>ans=kpc(str);
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
	return 0;
}
