#include <bits/stdc++.h>
using namespace std;

void  valid(string &s1,string &s2,string &res){
    int l1=s1.length();
    int l2=s2.length();
    int l3=res.length();
    if((l1+l2)!=l3) cout<<"Nooo";
    
    else{
        int i=0,j=0,k=0;
        while(k<l3){
            if(i<l1 and s1[i]==res[k]){
                i++;
                k++;
            } else if(j<l2 and s2[j]==res[k]){
                j++;
                k++;
            } else {
                break;
            }
        }
        if(i<l1 || j<l2) cout<<"no";
        else cout<<"yes";
    }
}

int main() {
    string s1="XY";
    string s2="123";
    string res="X1Y2";
    valid(s1,s2,res);
	return 0;
}