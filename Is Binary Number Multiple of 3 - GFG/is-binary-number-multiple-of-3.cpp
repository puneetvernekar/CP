//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int even=0,odd=0,n=s.size();
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]=='1')
	        {
	            if((i+1)%2==0)
	            even++;
	            else
	            odd++;
	        }
	        /*
	        if(s[i]=='0')
	        continue;
	        num+=pow(2,n-i-1);
	        */
	    }
	    if((odd-even)%3==0)
	    return 1;
	    return 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends