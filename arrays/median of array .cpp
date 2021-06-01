	int find_median(vector<int> v)
		{
		    // Code here.
		    int n=v.size();
		    sort(v.begin(),v.end());
		    if(n%2!=0) {
		        return v[n/2];
		    } else if(n%2==0) {
		        int a=v[n/2];
		        int b=v[(n/2)-1];
		        return (a+b)/2;
		    }
		}
};