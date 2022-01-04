#include<iostream>
using namespace std;
int main()
 {
    int N,i;
    cin>>N;
    for(i=2;i<N;i++)
    {
        if(N%i==0)
        {
            cout<<"Not Prime";
            return 0 ;      
          }
    }
    cout<<"Prime";
}

// C++ program to find the prime numbers
// between a given interval

#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	int a, b, i, j, flag;
    cin>>a>>b;
	for (i = a; i <= b; i++) {
		if (i == 1 || i == 0)
			continue;
		// flag variable to tell
		// if i is prime or not
		flag = 1;

		for (j = 2; j <= i / 2; ++j) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}

		// flag = 1 means i is prime
		// and flag = 0 means i is not prime
		if (flag == 1)
			cout << i << " ";
	}

	return 0;
}



#include<iostream>
using namespace std;
int main() 
{
	int i,min,max,F,step;  
	int C;
    cin>>min>>max>>step;
    for(i=min;i<=max;i=i+step)
    {
       C=((5.0)/9)*(i-32);
       cout<<i<<" " <<C<<endl;
    }
}
