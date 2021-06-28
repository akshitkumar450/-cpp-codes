class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        priority_queue<int>pq;
        vector<int>v;
        for(int i=0;i<n;i++){
            pq.push(a[i]);
        }
        for(int i=0;i<m;i++){
            pq.push(b[i]);
        }
        while(!pq.empty()){
            int tp=pq.top();
            pq.pop();
            v.push_back(tp);
        }
        return v;
    }
};