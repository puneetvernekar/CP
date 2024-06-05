class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<string>ans;
        //int max_count;
        
        for(char c='a';c<='z';c++)
        {
            int max_count=INT_MAX;
            
            for(int i=0;i<words.size();i++)
            {
                int char_count=0;
                for(char ch:words[i])
                {
                    if(ch==c)
                        char_count++;
                }
                max_count=min(max_count,char_count);
            }
            
            string temp(1,c);
            for(int i=0;i<max_count;i++)
                ans.push_back(temp);
        }
        return ans;
        
    }
};