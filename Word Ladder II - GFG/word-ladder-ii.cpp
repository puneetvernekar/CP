//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        set<string>s(wordList.begin(),wordList.end());
        queue<vector<string>>q;
        q.push({beginWord});
        vector<vector<string>>ans;
        vector<string>used_level;
        used_level.push_back(beginWord);
        int level=0;
        while(!q.empty())
        {
            vector<string>dummy=q.front();
            q.pop();
            
            if(dummy.size()>level)
            {
                for(auto ele:used_level)
                    s.erase(ele);
                level++;
            }
            string word=dummy.back();
            if(word==endWord)
            {
                ans.push_back(dummy);
            }
            for(int i=0;i<word.size();i++)
            {
                string temp=word;
                for(char ch='a';ch<='z';ch++)
                {
                    temp[i]=ch;
                    if(s.find(temp)!=s.end())
                    {
                        dummy.push_back(temp);
                        q.push(dummy);
                        used_level.push_back(temp);
                        dummy.pop_back();
                    }
                }
            }
        }
        return ans; 
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends