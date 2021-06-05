#include <iostream>
using namespace std;

void rotate90Clockwise(int arr[][4],int n,int m){
    
    // reverse each col
    for(int i=0;i<m;i++){
        int startRow=0;
        int endRow=m-1;
        while(startRow<endRow){
            swap(arr[startRow][i],arr[endRow][i]);
            startRow++;
            endRow--;
        }
    }
    
    // take transpose
       for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            if(i<j) //to upper triangle only
            swap(arr[i][j],arr[j][i]);
        }
    }
    
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

int main() {
    // n rows and m cols
    int n,m;
    cin>>n>>m;
	int arr[4][4] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotate90Clockwise(arr,n,m);
	return 0;
}