#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string ans){
    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=ques[0];
    string ros=ques.substr(1);
    
    string charcodes=codes[ch-'0'];
    for(int i=0;i<charcodes.length();i++){
        char option=charcodes[i];
        printKPC(ros,ans+option);
    } 
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}