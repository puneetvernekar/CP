class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.insert(ans.begin()+0, first);
        for(int i=0;i<encoded.size();i++)
        {   /*long t=0;
            bool b=true;
            while(b)
            {
                if(encoded[i]==(first ^ t) )
                {ans.push_back(t);
                first=t;
                b=false;}
                t++;
            }*/
            int a=encoded[i]^ans[i];
            ans.push_back(a);
        }
        return ans;
    }
};