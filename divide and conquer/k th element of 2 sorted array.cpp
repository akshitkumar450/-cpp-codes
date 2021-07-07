class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int key)
    {   
        // merge 2 arrays without space method
        int temp[n+m];
        int i=0;
        int j=0;
        int k=n-1;
        while(i<n and j<m) {
            if(arr1[i]<arr2[j]){
             i++;
            } else {
                swap(arr2[j],arr1[k]);
                    j++;
                    k--;
                
            }
        }
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
        // copy the element from both array to single array
    int l=0;
    for(int i=0;i<n;i++){
        temp[l]=arr1[i];
        l++;
    }
    for(int i=0;i<m;i++){
        temp[l]=arr2[i];
        l++;
    }
    // for(int i=0;i<l;i++){
    //     cout<<temp[i]<<" ";
    // }
        return temp[key-1];
    }
};