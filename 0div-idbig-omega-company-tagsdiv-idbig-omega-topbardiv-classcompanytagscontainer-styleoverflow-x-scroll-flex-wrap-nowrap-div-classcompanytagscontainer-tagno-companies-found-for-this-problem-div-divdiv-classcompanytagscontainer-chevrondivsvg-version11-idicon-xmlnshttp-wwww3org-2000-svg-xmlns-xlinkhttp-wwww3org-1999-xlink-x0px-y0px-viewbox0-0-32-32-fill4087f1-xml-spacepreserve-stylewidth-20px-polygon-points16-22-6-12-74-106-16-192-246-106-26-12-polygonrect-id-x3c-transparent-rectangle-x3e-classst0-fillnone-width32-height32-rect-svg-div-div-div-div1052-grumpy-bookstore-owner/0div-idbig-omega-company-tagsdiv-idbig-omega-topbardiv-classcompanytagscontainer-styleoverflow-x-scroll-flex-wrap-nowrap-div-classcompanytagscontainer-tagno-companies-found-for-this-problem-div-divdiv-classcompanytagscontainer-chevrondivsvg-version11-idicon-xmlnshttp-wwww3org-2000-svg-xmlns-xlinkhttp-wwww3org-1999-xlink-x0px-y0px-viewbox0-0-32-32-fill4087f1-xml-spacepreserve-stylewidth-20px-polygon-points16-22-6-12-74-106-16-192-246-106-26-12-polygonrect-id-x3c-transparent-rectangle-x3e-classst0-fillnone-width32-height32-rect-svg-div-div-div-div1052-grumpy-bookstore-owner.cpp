class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int ans=0;
        
        for(int i=0;i<grumpy.size();i++)
            if(grumpy[i]==0)
                ans+=customers[i];
        
        int sum=ans;
        //cout<<ans;
        
        for(int i=0;i<customers.size();i++)
        {
            int temp=sum,copy_i=i;
            for(int j=0;j<minutes;j++)
            {
                if(copy_i>=customers.size() || grumpy[copy_i]==0)
                {
                    copy_i++;
                    continue;
                }
                temp+=customers[copy_i];
                copy_i++;
            }
            
            ans=max(ans,temp);
        }
        
        return ans;
        
        
    }
};