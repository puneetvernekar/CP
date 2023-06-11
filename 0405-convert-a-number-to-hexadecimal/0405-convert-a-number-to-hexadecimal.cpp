class Solution {
public:
    string toHex(int num) {
        if(num==0)
        return to_string(0);
        unsigned int n=num;
        string ans;
        string all="0123456789abcdef";
        while(n)
        {
            int r=n%16;
            ans+=all[r];
            n=n/16;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};