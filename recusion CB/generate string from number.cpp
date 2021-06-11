#include <iostream>
using namespace std;

void generate_string(char in[],char out[],int i,int j){
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    // for one digit at a time
    int digit=in[i]-'0'; // to convert from char to int
    char ch=digit+'A'-1; // to get the corresponding alphabet with digit
    out[j]=ch;
    generate_string(in,out,i+1,j+1);
    
    // for two digit
    if(in[i+1]!='\0'){
        int secondDigit=in[i+1]-'0';
        int number=digit*10+secondDigit;
        if(number<=26){
            ch=number+'A'-1;
            out[j]=ch;
            generate_string(in,out,i+2,j+1);
        }
    }
    return;
}

int main() {
    char in[100];
    char out[100];
    cin>>in;
    generate_string(in,out,0,0);
	return 0;
}