long long countTriplets(long long arr[], int n, long long sum)	{
	   long long int left,right;
	    sort(arr,arr+n);
        // similar approach like finding triplets sum
	   long long  int count=0;
	    for(int i=0;i<n-2;i++){
	        left=i+1;
	        right=n-1;
	        while(left<right){
	            if(arr[i]+arr[left]+arr[right]<sum){
	                count+=(right-left);
	               left++;
	            } else if(arr[i]+arr[left]+arr[right]>=sum){ 
                    // if sum is greater then decrement right 
                    // bcz we want smaller number
	                right--;
	            }
	        }
	    }
	    return count;
}