class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<int> a,b;
        int n=piles.size();
        int x=max(piles[0],piles[n-1]);
        for(int i=1;i<n-2;i++)
        {
            x=max(piles[i],piles[n-i-1]);
            if(i%2==1)
            a.push_back(x);
            else
            b.push_back(x);
        }
        if((accumulate(a.begin(), a.end(), 0))>(accumulate(b.begin(), b.end(), 0)))
        return true;
        return false;
    }
};