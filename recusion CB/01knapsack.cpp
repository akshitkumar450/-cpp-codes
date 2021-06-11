#include <iostream>
using namespace std;

int zeroOne(int weights[],int prices[],int n,int c){
// if items are not there or capacity becomes zero
    if(n==0 or c==0){
        return 0;
    }
    
    int ans=0;
    int inc,exc;
    inc=exc=0;
    // including the item
    //include the item when capacity if more than the weight of the item
    if(weights[n-1]<c){ 
        //  pick from the last 
        // price of last item and profit which can be make by rest of the items
                                                    //remaining wt will bag capacity - wt of item picked
        inc=prices[n-1]+zeroOne(weights,prices,n-1,c-weights[n-1]);
    }
    // excluding the item
    // if ww did not pick the last  item 
    exc=zeroOne(weights,prices,n-1,c);

    ans=max(inc,exc);
    return ans;
}

int main() {
	int weights[]={1,2,3,5};
	int prices[]={40,20,30,100};
	int n=4; // items
	int c=7;    // capacity
	cout<<zeroOne(weights,prices,n,c);
	return 0;
}