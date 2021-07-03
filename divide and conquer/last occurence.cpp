int last(int arr[], int n , int x) {
    int s=0;
    int e=n-1;
    int ans=-1;
    
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==x){
            // if we found an element 
            // go the right and search for that element for the last occurence
            ans=mid;
            s=mid+1;
        } else if(arr[mid]<x){
            s=mid+1;
        } else{
            e=mid-1;
        }
    }
    return ans;
}