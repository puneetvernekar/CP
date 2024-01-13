class Solution {
public:
    int last_point;
    map<pair<int,int>,int>mp;
    int minTaps(int n, vector<int>& ranges) {
        last_point=n;
        vector<pair<int,int>>range;
        
        for(int i=0;i<=n;i++)
        {
            int start=max(0,i-ranges[i]);
            int end=min(n,i+ranges[i]);
            
            range.push_back({start,end});
            
        }
        
        sort(range.begin(),range.end());
        
        int res=solve(0,0,range);
        
        return res==1e9 ? -1 : res;
    }
    
    int solve(int i,int max_end,vector<pair<int,int>>&range)
    {
        if(i>=range.size())
        {
            if(max_end>=last_point)
            return 0;
            else
                return 1e9;
        }
        if(mp.find({i,max_end})!=mp.end())
            return mp[{i,max_end}];
        if(range[i].first>max_end)
        return 1e9;
        
        int not_open=solve(i+1,max_end,range);
        int open=1+solve(i+1,max(max_end,range[i].second),range);
        
        return mp[{i,max_end}]=min(not_open,open);
    }
};