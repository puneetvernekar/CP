class Solution {
public:
    int countSegments(string s) {
        int c=0;
        if(s.size()==0)
        return 0;
        stringstream temp(s);
        while(temp>>s)
        c++;
        return c;
    }
};