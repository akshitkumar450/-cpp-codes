vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<int>st; // store the index
        vector<long long> temp(n);
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[i]>arr[st.top()]){
                int val=st.top(); //store the index
                st.pop();
                
                temp[val]=arr[i];
            }
            st.push(i);
        }
         while(!st.empty()){
                temp[st.top()]=-1;
                st.pop();
        }
    // for(int i=0;i<n;i++){
    //     cout<<temp[i]<<" ";
    // }
    // cout<<endl;
        
        return temp;
    }