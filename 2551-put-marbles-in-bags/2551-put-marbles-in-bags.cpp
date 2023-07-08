class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        int n=weights.size();
        vector<int>all_pairs(n-1);
        for(int i=1;i<n;i++)
        {
            all_pairs[i-1]=weights[i-1]+weights[i];
        }
        sort(all_pairs.begin(),all_pairs.end());
        long long max_ans=0,min_ans=0;
        for(int i=0;i<k-1;i++)
        {
            max_ans+=all_pairs[n-i-2];
            min_ans+=all_pairs[i];
        }
        return max_ans-min_ans;
    }
};