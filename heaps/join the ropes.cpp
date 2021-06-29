long long minCost(long long arr[], long long n) {
    // min heap
        priority_queue<long long int,vector< long long int>,greater<long long int>>pq(arr,arr+n);
        long long int cost=0;
        // heap should have atleast 2 ropes
        while(pq.size()>1){
          long long  int A=pq.top();
            pq.pop();
          long long  int B=pq.top();
            pq.pop();
            long long int newRope=A+B;
            cost=cost+newRope;
            pq.push(newRope);
            
        }
        return cost;
}