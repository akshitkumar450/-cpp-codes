
// o(MN)

// count the no of one in each row and store the index of that row with maximum no of one
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	int max=0,cnt,index=-1;
    for(int i=0;i<n;i++){
        cnt=0;
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                cnt++;
            }
            if(cnt>max){
             max=cnt;
                index=i; // saving the index of the row which has the maximum no fof rows
             }
        }
        
    }
    return index;
	}

// O(m+n) and in worst case O(mn)
// as each row is sorted
// so we can count the first column having 1 and after that there will be all one as it is sorted
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        for(int j=0;j<m;j++){ //column traversal
            for(int i=0;i<n;i++){
                if(arr[i][j]==1){
                    return i;
                }
            }
        }
        return -1;
	}

// O(m+n)

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    //decrease till there are one in first row 
     int j=m-1;
     while(j>=0 && arr[0][j]==1)  j--;
    //  after this loop j will point to the index of the first one in the first row
     
    //  check from the index where j was and i and if it has more no of one then store the index of that row
     int row=0;
    //  from second row onwards
     for(int i=1;i<n;i++){
        while(j>=0 && arr[i][j]==1){
            row=i;
            j--;
        }
     }
     return (j==m-1 )?-1:row;
	}
int main()
{
    bool mat[R][C] = { {0, 0, 0, 1},
                    {0, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0}};
 
    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);
 
    return 0;
}