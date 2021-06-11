#include <iostream>
using namespace std;

char keypadCodes[][10]={"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void keypad(char in[],char out[],int i,int j){
    // if we have reached end 
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    // extract the first digit 
    int digit=in[i]-'0';
    // loop over all digits of input
    for(int k=0;keypadCodes[digit][k]!='\0';k++){
        // add to output
        out[j]=keypadCodes[digit][k];
        // recursive call
        keypad(in,out,i+1,j+1);
    }
    return;
}


int main() {
    char in[100];
    char out[100];
    cin>>in;
    keypad(in,out,0,0);
	return 0;
}