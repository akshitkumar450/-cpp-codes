#include <iostream>
using namespace std;

char words[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void printSpellings(int n){
    if(n==0){
        return;
    }
    printSpellings(n/10); // to reduce the number
    // print after calling 
    int digit=n%10; // to get the last digit
    cout<<words[digit]<<" ";
    return;
}

int main() {
	int n;
	cin>>n;
	printSpellings(n);
	return 0;
}