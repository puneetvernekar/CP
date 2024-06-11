class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        map<int,int>m;
        vector<int>ans;
        
        for(int x:arr1)
            m[x]++;
        
        for(int x:arr2)
        {
            for(int i=0;i<m[x];i++)
                ans.push_back(x);
                
            m[x]=0;
        }
        
        for(auto x:m)
        {
            if(x.second!=0)
            {
                for(int i=0;i<x.second;i++)
                {
                    ans.push_back(x.first);
                    m[x.first]--;
                }
            }
        }
        
        return ans;
    }
};