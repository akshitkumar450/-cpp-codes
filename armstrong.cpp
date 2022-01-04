// s#include<iostream>
// using namespace std;
// int main() 
// {
// 	int n,r;
// 	cin>>n;
// 	while(n>0)
// 	{
// 		r=n%10;
// 		n=n/10;
// 		cout<<r;
// 	}

// 	return 0;
// }



#include <iostream>
#include<cmath>
using namespace std;
bool arm(int n)
{

    int m=n;
    int r,sum=0,cnt=0;
    while(m>0)
    {
        m=m/10;
        cnt++;
    }
    m=n;
    while(m>0)
    {
        r=m%10;
        m=m/10;
        sum=sum+pow(r,cnt);
    }
    if (sum==n)  return true ;
    return false;
}
int main() {
    int n;
    cin>>n;
//   if(arm(n)) cout<<"true";
//   else cout<<"false";
cout<<arm(n);
   
}