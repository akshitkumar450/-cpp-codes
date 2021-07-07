class Solution {
public:
    int majorityElement(vector<int>& a) {
        int size=a.size();
        unordered_map<int,int>mp;
        // store the occurences
        for(int i=0;i<size;i++){
            mp[a[i]]++;
        }

        int val;
        // check if there is a element with occurence of >n/2
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second > (size/2)){
               val=it->first;
                break;
            }
        }
        return val;
      
    }
};

// moore voting algo
class Solution {
public:
    int majorityElement(vector<int>& a) {
         // your code here
       int count=0;
      int element=0;
        int size=a.size();
      for(int i=0;i<size;i++){
          if(count==0){
              element=a[i];
          } if(element==a[i]){
              count++;
          } else {
              count--;
          }
      }
      return element;
      
    }
};