class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> temp={1,1,2,2,1};
        vector<int> vec(5,0);
        vector<int> ans(5,0);
        for(char c:text)
        {
            switch(c)
            {
                case 'b':
                vec[0]++;
                break;
                case 'a':
                vec[1]++;
                break;
                case 'l':
                vec[2]++;
                break;
                case 'o':
                vec[3]++;
                break;
                case 'n':
                vec[4]++;
                break;
                default:
                continue;

            }
        }
        for(int i=0;i<5;i++)
        ans[i]=vec[i]/temp[i];
        return *min_element(ans.begin(),ans.end());
    }
};