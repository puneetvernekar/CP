//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long find(int pos,int index,vector<int>&temp,vector<vector<long>>&dp,int indication,unordered_map<int,int>&m1,unordered_map<int,int>&m2)
    {
        if(index==temp.size())
        return 0;
        if(dp[index][indication]!=-1)
        return dp[index][indication];   
        long one=0,two=0;
        int left=m1[temp[index]];
        int right=m2[temp[index]];
        one=abs(pos-left)+abs(left-right)+find(right,index+1,temp,dp,1,m1,m2);
        if(index==temp.size()-1)
        one+=abs(right);
        two=abs(pos-right)+abs(left-right)+find(left,index+1,temp,dp,0,m1,m2);
        if(index==temp.size()-1)
        two+=abs(left);
        return dp[index][indication]=min(one,two);
    }
  
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        // code here
        unordered_map<int,int>m1,m2;
        int maxi=*max_element(types.begin(),types.end());
        vector<int>ele(maxi+1,0);
        for(int i=0;i<n;i++)
        ele[types[i]]=1;
        vector<int>temp;
        for(int i=0;i<=maxi;i++)
        {
            if(ele[i]==1)
            temp.push_back(i);
        }
        for(int i=0;i<n;i++)   
        {
            ele[types[i]]=1;
            if(m1.find(types[i])==m1.end())
            {
                m1[types[i]]=locations[i];
                m2[types[i]]=locations[i];
            }
            else
            {
                m1[types[i]]=min(m1[types[i]],locations[i]);
                m2[types[i]]=max(m2[types[i]],locations[i]);
            }
        }
        vector<vector<long>>dp(temp.size(),vector<long>(2,-1));
        return find(0,0,temp,dp,0,m1,m2); 
        
        
        /*int cur=0,time=0;
        while(true)
        {
            int min_type=*min_element(types.begin(),types.end());
            int ind_type=find(types.begin(),types.end(),min_type)-types.begin();
            time+=abs(locations[ind_type]-cur);
            cur=locations[ind_type];
            if(types.size()==1)
            break;
            types.erase(types.begin()+ind_type);
            locations.erase(locations.begin()+ind_type);
        }
        return time+abs(cur);*/
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends