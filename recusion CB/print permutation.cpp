#include <iostream>
using namespace std;

void permutation(char in[100],int i){
    if(in[i]=='\0'){
        cout<<in<<" ";
        return;
    }
    
    for(int j=i;in[j]!='\0';j++){
        swap(in[i],in[j]);
        permutation(in,i+1);
        // backtracking 
        // to restore the array back 
        // bcz array are passed by reference
         swap(in[i],in[j]);
    }
}

int main() {
    char in[100];
    cin>>in;
   permutation(in,0);
	return 0;
}