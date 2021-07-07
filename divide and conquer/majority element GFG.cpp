    int majorityElement(int a[], int size)
    {
        
        unordered_map<int,int>mp;
        // store the occurences
        for(int i=0;i<size;i++){
            mp[a[i]]++;
        }
        
        int count=-1;
        int val;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second > (size/2)){
                count=1;
                 val=it->first;
                return val;
            }
        }
      if(count==-1){
          return -1;
      }
        
    }