
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int>a(n),b(n);
        vector<pair<int,int>>c(n);
        for(auto i=0;i<n;++i)
        {
            b[i]=intervals[i][1];
            a[i]=intervals[i][0];
            c[i]=make_pair(b[i],a[i]);
        }
        sort(c.begin(),c.end());

        int r;
        r=INT_MIN;
        int ct=0;
        for(auto i=0;i<n;++i)
        {
          if(c[i].second>= r)
          {
            ct++;
            r=c[i].first;
          }

        }
        return n-ct;
    }
};