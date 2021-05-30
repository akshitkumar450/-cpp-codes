#include <bits/stdc++.h>
using namespace std;

// for storing the start and end intervals 
class interval {
    public:
        int start,end;
};
// sort on the basis of start intevals
bool compare(interval l1,interval l2) {
    return l1.start< l2.start;
}

void merge_overlaps(interval arr[],int n) {
    stack<interval> s;
    if(n<=0) return;
    sort(arr,arr+n,compare);
    s.push(arr[0]);
    for(int i=1;i<n;i++) {
        interval top=s.top();
        // no overlapping ->then push in stack
        // if incoming element start time is more than end time of the end 
        // push it to stack
        if(top.end < arr[i].start) {
            s.push(arr[i]);
        } 
        // overlapping
        //  check if the incoming item end more  than the end of top 
        // change the end of top with incoming end
         else if(top.end < arr[i].end) {
             top.end=arr[i].end;
             s.pop();
             s.push(top);
         }
     }

     while(!s.empty()) {
         interval t=s.top();
        cout << "[" << t.start << "," << t.end << "] "; 
        s.pop(); ;
     }
     return;
}
int main() {
    // interval arr[]={ {6,8},{2,4},{1,9},{4,7} };
    interval arr[]={ {2,4}, {1,3}, {5,7} ,{6,8} };

    int n=sizeof(arr)/sizeof(arr[0]);
    merge_overlaps(arr,n);
}
