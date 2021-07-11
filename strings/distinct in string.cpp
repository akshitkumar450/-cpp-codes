
#include <bits/stdc++.h>
using namespace std;


void distinct(string str)
{   
    int n=str.length();
    int count[256]={0};
    for(int i=0;i<n;i++){
        count[str[i]]++;
    }
    for(int i=0;i<n;i++){
        if(count[str[i]]==1){
            cout<<str[i];
        }
    }
}

int main()
{
	char str[] = "Hello Geeks";
	distinct(str);
}

