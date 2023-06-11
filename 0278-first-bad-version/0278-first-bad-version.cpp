// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long f=1;
        long l=n;
        long ans;
        while(f<=l)
        {long m=(f+l)/2;
        if(isBadVersion(m))
        {l=m-1;
        ans=m;
        }
        else
        f=m+1;
        }
        return ans;

    }
};