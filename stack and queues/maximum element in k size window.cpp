#include <iostream>
#include<deque>
using namespace std;

// O(n^2)
void printKMax(int arr[], int n, int k)
{
    int j, max;
    // there will be n-k windows
    for (int i = 0; i <= n - k; i++)
    {
        max = arr[i];

        for (j = 1; j < k; j++)
        {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
        cout << max << " ";
    }
}

// O(N)
int main() {
    int arr[]={1,2,3,1,4,5,2,3,6};
    int n=9;
    int k=3;
    // we store the index of the element
    deque<int>q(k);
    // process first k (or first window)elements separately
    for(int i=0;i<k;i++){
        while(!q.empty() and arr[i]>arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    // after this the maximum element will be 0 front of queue
    
    for(int i=k;i<n;i++){
        cout<<arr[q.front()]<<" ";
        
        // remove the elements which are not part of the current window  (contraction)
            while(!q.empty() and (q.front()<=i-k)){
                q.pop_front();
            }
        
        // remove the elements which are not useful
            while(!q.empty() and arr[i]>=arr[q.back()]){
                q.pop_back();
            }
        
        // add the new elements (expansion)
        q.push_back(i);
    }
    // print for the last window
    cout<<arr[q.front()]<<" ";

	return 0;
}