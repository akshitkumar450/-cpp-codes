class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    vector<int>v;
        // max heap
	   // priority_queue<int>pq;
	   // for(int i=0;i<n;i++){
	   //     pq.push(arr[i]);
	   // }
	   // for(int i=0;i<k;i++){
	   //     int t=pq.top();
	   //     pq.pop();
	   //     v.push_back(t);
	   // }

	//    sort the array in descending order
	   sort(arr,arr+n,greater<int>());
	   for(int i=0;i<k;i++){
	        v.push_back(arr[i]);
	   }
	    return v;
	}
};


class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    vector<int>v;
	   // min heap
	    priority_queue<int,vector<int>,greater<int>>pq;
        // first put k elements in pq
	    for(int i=0;i<k;i++){
	        pq.push(arr[i]);
	    }
	    // check from k to n
        // if current element is greater than the top of pq
        // pop the top element from pq and push the new element
	    for(int i=k;i<n;i++){
	        int t=pq.top();
	        if(arr[i]>t){
	            pq.pop();
	            pq.push(arr[i]);
	        }
	    }
	//   after above loop pq will have k largest elements
	   while(!pq.empty()){
	       int t=pq.top();
	        pq.pop();
	       v.push_back(t);
	   }
	   reverse(v.begin(),v.end());
	    return v;
	}
};
