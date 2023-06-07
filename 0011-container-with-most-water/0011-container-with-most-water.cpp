class Solution {
public:
    int maxArea(vector<int>& height) {
        int m=0,f=0,e=height.size()-1;
        while(f<e)
        {   int tmp=min(height[f],height[e]);
            m=max(m,tmp*(e-f));
            if(tmp==height[f])
            f++;
            else
            e--;
        }
        return m;   
    }
};