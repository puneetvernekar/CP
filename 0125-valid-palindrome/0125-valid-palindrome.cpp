class Solution {
public:
    bool isPalindrome(string s) {
        string org="";
      transform(s.begin(), s.end(), s.begin(), ::tolower);
      for(int i=s.size()-1;i>=0;i--)
      if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
        org.push_back(s[i]);
      string pal=org;
      reverse(org.begin(),org.end());
      cout<<pal<<"\t"<<org;
      if(org==pal)
      return true;
      else
      return false; 
      return 0; 
    }
};