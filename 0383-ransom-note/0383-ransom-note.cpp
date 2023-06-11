class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> ma;
        int cou;
        int n=magazine.size();
        for(int i=0;i<n;i++)
        ma[magazine[i]]++;
        for(char c:ransomNote)
        {
            if(ma.find(c)==ma.end() || ma[c]==0)
            return false;
            ma[c]--;
        }
        return true;
    }
};