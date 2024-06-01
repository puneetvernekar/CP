class Solution {
public:
    int scoreOfString(string s) {
        
        int ans=0;
        for(int i=0;i<s.size()-1;i++)
        {
            int asc=int(s[i]);
            int nxt_asc=int(s[i+1]);
            
            ans+=abs(asc-nxt_asc);
        }
        return ans;
    }
};