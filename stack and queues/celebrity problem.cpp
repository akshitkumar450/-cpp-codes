#include <bits/stdc++.h> 
using namespace std; 
#define M 4
#define N 4

int findCelebrity(int arr[4][4],int n) { 
	stack<int> s; 
	int celebrity; 
    // push every element(index of 2-d array) to stack
	for (int i = 0; i < n; i++) 
		s.push(i); 
	// there should be atleast 2 elements in stack
	while (s.size() >=2) 
    {
        // always pop top elements
        int A = s.top(); s.pop(); 
        int B = s.top();   s.pop(); 
        // check if A knows B or not
        // if A knows B means that A cant be the celebrity
        if(arr[A][B]==1) {
            s.push(B);
        }
        else  {
            // else A can be celebrity
            s.push(A);
        }
    } 
    // at last there will be a single element  in the stack that can be our potential celebrity
	celebrity = s.top(); 
	s.pop(); 

    // check for all cell except (i,i)
	for (int i = 0; i < n; i++)  {
        if(i!=celebrity) {
            // if no one knows celebrity or if celebrity knows everyone than he is not celebrity
            if(arr[i][celebrity]==0 || arr[celebrity][i]==1) {
                return-1;
            }
        }
    }
    return celebrity;
} 
int main()   { 
	int n = 4; 
   int  MATRIX[M][N] = {{0, 0, 1, 0}, 
					{0, 0, 1, 0}, 
					{0, 0, 0, 0}, 
					{0, 0, 1, 0}}; 

    int id=findCelebrity(MATRIX,n);
	 
	id == -1 ? cout << "No celebrity" : 
			cout << "Celebrity ID " << id; 
	return 0; 
} 
