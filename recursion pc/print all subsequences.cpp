#include <iostream>
#include<cstring>
using namespace std;

void printSS(string ques, string ans){
    // write your code here
    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=ques[0];
    string ros=ques.substr(1);
    // taking the first char
    printSS(ros,ans+ch);
    //not taking the first char
    printSS(ros,ans+"");
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}