vector<int> allIndex(vector<int>& arr, int idx, int data, int count)
{  
// when idx reached end make an array of size count and return it
    if(idx==arr.size()){
       return new int[count]
    }
    
    // count the occurrences of the number while going
    if(arr[idx]==data){
        // while returning fill the array with indexes of the element
        iarr[]= allIndex(arr,idx+1,data,count+1); // if the element is found increment both count and index
        iarr[count]=idx;
        return iarr;
    } else {
       iarr[]= allIndex(arr,idx+1,data,count); // if the element is not found increment only  index
       return iarr;
    }
}