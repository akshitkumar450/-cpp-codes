#include <bits/stdc++.h>
using namespace std;

#define MAX 100
// O(32 * r * log(c)).
int binaryMedian(int m[][MAX],int r,int c){
    int min=INT_MAX,max=INT_MIN;
    // find the min and maximum element of the matrix
    for(int i=0;i<r;i++){
       if(m[i][0]<min){
           min=m[i][0]; //min element will be in first col
       }
       if(m[i][c-1]>max){
           max=m[i][c-1]; // max element will be in last col
       }
    }
    
    // it is the median when the matrix is stored in array
    int desired=(r*c+1)/2;
    while(min<max){
        int mid=min+(max-min)/2;
        int place=0;
        for(int i=0;i<r;i++){ // to get the numbers which are less than or equal to the mid
            place+=upper_bound(m[i],m[i]+c,mid)-m[i];
        }
          
        if(place<desired){
                min=mid+1;
        else
            max=mid;
    }
    return min;
}

int main() {
	  int r = 3, c = 3;
    int m[][MAX]= { {1,3,5}, {2,6,9}, {3,6,9} };
     cout << "Median is " << binaryMedian(m, r, c) << endl;
	return 0;
}