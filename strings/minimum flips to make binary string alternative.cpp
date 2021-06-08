#include <bits/stdc++.h>
using namespace std;

int flips(string str){
    int c1=0;
    int c2=0;

    for(int i=0;i<str.length();i++){
        if(i%2!=0 and str[i]=='0') c1++;
        else if(i%2==0 and str[i]=='1') c1++;
        else if(i%2!=0 and str[i]=='1') c2++;
        else if(i%2==0 and str[i]=='0') c2++;
    }
    return min(c1,c2);
}

int main() {
 string str = "1100";
 cout<<flips(str);
	return 0;
}