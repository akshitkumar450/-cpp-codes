bool findPair(int arr[], int size, int n){
    // keep one pointer at 0 and second at 2
    int i=0;
    int j=1;
    // sort it
    sort(arr,arr+size);
    while(i<size and j<size){
        // if difference == given number return true
        if(arr[j] - arr[i]==n){
            return 1;
            // if difference in greater than n
            // i++
        } else if(arr[j] - arr[i]>n){
            i++;
        } else{
            j++;
        }
    }
    return 0;
}