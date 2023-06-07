class Solution {
public:
        int strStr(string haystack, string needle) {
        int n1=haystack.size();
        int n2=needle.size();
        string s1=haystack;
        string s2=needle;
        for(int i=0;i<n1;i++)
            if(!(s1.compare(i,n2,s2)))
            return i;
        return -1;
    }
    
};