class Solution {
public:
    
    bool find(int mid,int n,int index,int maxSum)
    {
        long long tot=total(mid);
        long long leftlength=index+1,rightlength=n-index;
        long long leftoffset=0,rightoffset=0;
        if(leftlength<mid)
            leftoffset-=total(mid-leftlength);
        else
            leftoffset=leftlength-mid;
        if(rightlength<mid)
            rightoffset-=total(mid-rightlength);
        else
            rightoffset=rightlength-mid;
        long long ans=tot+leftoffset+tot+rightoffset-mid;
        
        return ans<=maxSum;
    }
    
    long long total(long long mid)
    {
        long long mul=mid*(mid+1)/2;
        return mul;
    }
    long long maxValue(int n, int index, int maxSum) {
        
        long long l=1,r=maxSum;
        while(l<r)
        {
            int mid=l+(r-l+1)/2;
            
            if(find(mid,n,index,maxSum))
                l=mid;
            else
                r=mid-1;
        }
        return l;
        
        
        /*int ini=maxSum/n;
        vector<int>rem;
        rem[0]=ini;
        int count=ini,maxi=ini;
        int i=1;
        while(i<n)
        {
            maxi++;
            while(count)
            {rem[i]=maxi;
            i++;
            count--;}
            count+=2;
        }
        int reminder=maxSum%n;
        int mid=n/2;
        // if(index>=mid-2 || index<=mid+2)
        // return rem[reminder];
        // else if(index==0 || index==n-1)
        // return rem[reminder]
        return rem[reminder];*/
}
};