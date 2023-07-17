//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char,int>m;
		    string s=A,ans="";
		    queue<char>q;
		    for(int i=0;i<s.size();i++)
		    {
		        m[s[i]]++;
		        if(m[s[i]]==1)
		        q.push(s[i]);
		        while(q.size() && m[q.front()]>1)
		        q.pop();
		        
		        if(q.size()==0)
		        ans+='#';
		        else
		        ans+=q.front();
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends