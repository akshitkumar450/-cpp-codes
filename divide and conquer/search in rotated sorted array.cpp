#include <iostream>
using namespace std;

int srch(int arr[],int n, int key)
{
    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        //  part between low and mid is sorted 
       else if(arr[s]<=arr[mid]){   
            // if target lies in the sorted part (discard mid to end )
            // search in low to mid
            if(key >=arr[s] &&  key <=arr[mid])
                e=mid-1;
            else
                s=mid+1;
        }
        // if mid to end is sorted
        else if(arr[mid]<=arr[e]){
            // if key lies in sorted part  (discard low to mid)
            // search in mid to end 
            if(key >=arr[mid] && key<=arr[e])
               s=mid+1;
            else
               e=mid-1; 
        }
    }
    return -1;
}
int main() {
  int n;
  cin>>n;
  int arr[100];
  for(int i=0;i<n;i++)
  {
      cin>>arr[i];
  }
  int key;
  cin>>key;
  cout<<srch(arr,n,key);
}
