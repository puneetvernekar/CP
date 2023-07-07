class Solution {
public:
    int find(string answerKey,int k,char torf)
    {
        int left=0,ans=0,c=0;
        for(int i=0;i<answerKey.size();i++)
        {
            if(answerKey[i]==torf)
                c++;
            while(c>k)
            {
                if(answerKey[left]==torf)
                    c--;
                left++;
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int tans=find(answerKey,k,'T');
        int fans=find(answerKey,k,'F');
        return max(tans,fans);
    }
};