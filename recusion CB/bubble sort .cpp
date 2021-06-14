#include <iostream>
using namespace std;

void bubble(int a[],int n)
{
    if(n==1) return;

    //sort 1 element and call the recursion in rest of the elements

    for(int j=0;j<=n-2;j++)
    {
        if(a[j]>a[j+1])
        swap(a[j],a[j+1]);
    }
    bubble(a,n-1);
}


void bubble_optimized(int a[],int j,int n)
{
   if(n==1) return;

   if(j==n-1)  
   return bubble_optimized(a,0,n-1);

   if(a[j]>a[j+1])
   {
       swap(a[j],a[j+1]);
   }
   bubble_optimized(a,j+1,n);
   return;




}
int main() {
 int a[]={7,3,8,2,9};
 int n=5;
// bubble(a,n);
bubble_optimized(a,0,n);
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
}
