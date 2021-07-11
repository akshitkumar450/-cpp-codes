
#include <bits/stdc++.h>
using namespace std;

bool is_vow(char c)
{
	
	return (c == 'a') || (c == 'e') ||
		(c == 'i') || (c == 'o') ||
		(c == 'u');
}


void removeVowels(string str)
{   
    int n=str.length();
    string temp;
	for (int i = 0;i<n; i++){
		if(!is_vow(str[i])){
		    temp=temp+str[i];
		}
	}
	str=temp;
	cout<<str;
}

int main()
{
	char str[] = "welcome to geeksforgeeks";
	removeVowels(str);
}

