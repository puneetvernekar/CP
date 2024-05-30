class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        int ans=0,temp=0;
        unordered_map<int,vector<int>>m;
        
        m[0].push_back(-1);
        
        for(int i=0;i<arr.size();i++)
        {
            temp^=arr[i];
            
            if(m.find(temp)!=m.end())
            {
                for(auto x:m[temp])
                    ans+=(i-x)-1;
            }
            m[temp].push_back(i);
        }
        return ans;
    }
};