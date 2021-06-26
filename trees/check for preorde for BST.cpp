class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        stack<int>s;
        int root=INT_MIN; 
        // find the next greater and after finding the next greater if we have any smaller element then root return fasle
        for(int i=0;i<N;i++){
            while(!s.empty() and arr[i]>s.top()){
                root=s.top();
                s.pop();
            }
            if(arr[i]<root){
                return 0;
            }
            // if current element is smaller than top
            s.push(arr[i]);
        }
        return 1;
    }
};