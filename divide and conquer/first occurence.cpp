int first(int arr[], int n , int x) {
    int s=0;
    int e=n-1;
    int ans=-1;
    
    while(s<=e){
        int mid=(s+e)/2;
        // if we found an element
        // then store its index and search in left side also to get the first occurence of the elements
        if(arr[mid]==x){
            ans=mid;
            e=mid-1;
        } else if(arr[mid]<x){
            s=mid+1;
        } else{
            e=mid-1;
        }
    }
    return ans;
}
