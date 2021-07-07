class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // make index of n+1 element 
     int* res=new int [n+1]; 
     static  int temp [2];
        for(int i=0;i<n+1;i++){
            res[i]=0;
        }
        
        // save the occureneces the arr on index of res
        for(int i=0;i<n;i++){
            res[arr[i]]=res[arr[i]]+1;
        }
        
        for(int i=1;i<n+1;i++){
            if(res[i]>1){
                temp[0]=i;
            }else  if(res[i]==0){
                temp[1]=i;
            }
        }
        
        return temp;
    }
};