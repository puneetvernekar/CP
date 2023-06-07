class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        int n=columnTitle.size();
        for(int i=0;i<n;i++)
        {
            int c=columnTitle[i]-65+1;
            ans=(ans*26)+c;
        }
        return ans;
    }
};