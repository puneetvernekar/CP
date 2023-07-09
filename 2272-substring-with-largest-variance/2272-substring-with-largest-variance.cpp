class Solution {
public:
    int largestVariance(string s) {
        int ans=0;
        unordered_map<char,int>m;
        for(char c:s)
            m[c]++;
        for(char c1='a';c1<='z';c1++)
        {
            for(char c2='a';c2<='z';c2++)
            {
                if(c1==c2 || m[c1]==0 || m[c2]==0)
                    continue;
                for(int pair=1;pair<=2;pair++)
                {
                    int cnt1=0,cnt2=0;
                    for(char c:s)
                    {
                        cnt1+=c==c1;
                        cnt2+=c==c2;
                        if(cnt1<cnt2)
                            cnt1=0,cnt2=0;
                        if(cnt1>0 && cnt2>0)
                            ans=max(ans,cnt1-cnt2);
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};