#include <bits/stdc++.h>
using namespace std;

string convert(string str[],string &text){
    int n=text.length();
    string output="";
    for(int i=0;i<n;i++){
        // for space insert 0
        if(text[i]==' '){
            output+="0";
        } else {
            // get position from the array
            int pos=text[i]-'A';
            output=output+str[pos];
        }
    }
    return output;
}

int main() {
	  string str[] = {"2","22","222",
                    "3","33","333",
                    "4","44","444",
                    "5","55","555",
                    "6","66(","666",
                    "7","77","777","7777",
                    "8","88","888",
                    "9","99","999","9999"
                   };
    string text="AKSHIT";
   cout<< convert(str,text);
	return 0;
}