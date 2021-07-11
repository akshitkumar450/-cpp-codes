
#include <bits/stdc++.h>
using namespace std;

// O(n^2)
void reverse(string str)
{   
   int n=str.length();
   int si=0;
   int ei=0;
   while(ei<=n){
       if(ei<n and str[ei]!=' '){
           ei++;
       } else{
           for(int j=ei;j>=si;j--){
             cout<<str[j];
            }
            cout<<" ";
			ei++;
			si=ei;
       }
   }
}

// O(N)
void reverseWords(string str)
{
	stack<char> st;

	// Traverse given string and push all characters
	// to stack until we see a space.
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] != ' ')
			st.push(str[i]);

		// When we see a space, we print contents
		// of stack.
		else {
			while (st.empty() == false) {
				cout << st.top();
				st.pop();
			}
			cout << " ";
		}
	}

	// Since there may not be space after
	// last word.
	while (st.empty() == false) {
		cout << st.top();
		st.pop();
	}
}
int main()
{
	string str = "Geeks for Geeks";
	reverseWords(str);
	return 0;
}


int main()
{
	string str = "Geeks for Geeks";
	reverse(str);
}

