#include <iostream>
#include <cstring>
using namespace std;

int stringToInt(char str[],int n){
    if(n==0){
        return 0;
    }
    int digit=str[n-1]-'0'; // to extract the last digit
    int small_ans=printSpellings(str,n-1); // to reduce to smaller string
    return small_ans*10+digit;
}

int main() {
	char str[]="1234";
	int n=strlen(str);
    cout<<stringToInt(str,n);
	return 0;
}