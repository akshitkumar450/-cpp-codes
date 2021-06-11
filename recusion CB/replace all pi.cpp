#include <iostream>
using namespace std;

void replacePi(char str[],int i){
    if(str[i]=='\0' or str[i+1]=='\0'){
        return;
    } 
    // look for pi and replace with 3.14
    if(str[i]=='p' and str[i+1]=='i'){
        int j=i+2;// to move characters and replace
        
        // take j to end of array
        while(str[j]!='\0'){
            j++;
        }
        // shift from right to left
        while(j>=i+2){
            str[j+2]=str[j];
            j--;
        }
        // replace the characters and recursive case
        str[i]='3';
        str[i+1]='.';
        str[i+2]='1';
        str[i+3]='4';
        // after replacing next iteration will be from 4 positions ahead where i was 
        replacePi(str,i+4);
    } 
    //  if pi not found move forward
    else{
        replacePi(str,i+1);
    }
    return;
}

int main() {
    char str[1000];
    cin>>str;
    replacePi(str,0);
    cout<<str<<endl;
    
	
	return 0;
}