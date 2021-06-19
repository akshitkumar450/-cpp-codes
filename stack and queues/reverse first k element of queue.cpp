queue<int> modifyQueue(queue<int> q, int k){
    stack<int>st;
    queue<int>q1;
    for(int i=0;i<k;i++){
        int val=q.front();
            q.pop();
        st.push(val);
    }
    while(!q.empty()){
      int val=q.front();
            q.pop();
        q1.push(val);
    }
    while(!st.empty()){
        int val=st.top();
        st.pop();
        q.push(val);
    }
    
    while(!q1.empty()){
        int val=q1.front();
        q1.pop();
        q.push(val);
    }
    return q;
}