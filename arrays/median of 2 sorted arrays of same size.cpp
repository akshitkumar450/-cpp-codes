#include <iostream>
using namespace std;

// O(N)
int getMedian(int ar1[],int ar2[],int n1){
    int m1=-1;
    int m2=-1;
    int cnt;
    int i=0,j=0;
    for(cnt=0;cnt<=n1;cnt++){
        if(i==n1){
            m1=m2;
            m1=ar2[0];
            break;
        } else if(j==n1){
            m1=m2;
            m2=ar1[0];
            break;
        }
        if(ar1[i]<=ar2[j]){
            m1=m2;
            m2=ar1[i];
            i++;
        } else if(ar1[i]>ar2[j]){
            m1=m2;
            m2=ar2[j];
            j++;
        }
    }
    return (m1+m2)/2;
}

// O(LOG N)
int median(int arr[],int n){
    if(n%2==0){
        return (arr[n/2]+arr[n/2-1])/2;
    else return arr[n/2];
    }
}

int getMedian2(int ar1[],int ar2[],int n){
    if(n<=0){
        return -1;
    }
     if(n==1){
         return (ar1[0]+ar2[0])/2;
     }
     if(n==2) return (max(ar1[0],ar2[0])+min(ar1[1],ar2[1]))/2;
     
    int m1=median(ar1,n);
    int m2=median(ar2,n);
    if(m1==m2) return m1;
    if (m1 < m2)
    {
        if (n % 2 == 0)
            return getMedian(ar1 + n / 2 - 1,
                             ar2, n - n / 2 + 1);
        return getMedian(ar1 + n / 2,
                         ar2, n - n / 2);
    }
 
    /* if m1 > m2 then median must
       exist in ar1[....m1] and
                ar2[m2...] */
    if (n % 2 == 0)
        return getMedian(ar2 + n / 2 - 1,
                         ar1, n - n / 2 + 1);
    return getMedian(ar2 + n / 2,
                     ar1, n - n / 2);
}

int main() {
	int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};
 
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    cout<<getMedian(ar1, ar2, n1);
	return 0;
}