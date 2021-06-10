#include<iostream>
#include<cstring>
using namespace std;

void printPermutations(string str, string asf){
    if(str.length()==0){
        cout<<asf<<endl;
        return;
    }
    
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        string left=str.substr(0,i);
        string right=str.substr(i+1);
        string ros=left+right;
        printPermutations(ros,asf+ch);
    }
}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}
