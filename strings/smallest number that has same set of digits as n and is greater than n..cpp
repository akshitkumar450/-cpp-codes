#include <bits/stdc++.h>
using namespace std;

void nextGreater(string &str){
    int n=str.length();
    int i,j;
    for( i=n-2;i>=0;i--){
        if(str[i]<str[i+1]){
            break;
        }
    }
    
    if(i==0){
        cout<<"not possible";
    }
    
    for( j=n-1;j>=0;j--){
        if(str[j]>str[i])
            break;
    }
    swap(str[i],str[j]);
    reverse(str.begin()+i+1,str.end());
}

int main() {
	string str="4321";
	nextGreater(str);
	for(int i=0;i<str.length();i++){
	    cout<<str[i];
	}
	return 0;
}