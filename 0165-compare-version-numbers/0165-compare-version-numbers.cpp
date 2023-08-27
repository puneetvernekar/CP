class Solution {
public:
    int compareVersion(string version1, string version2) {
        string v1=version1,v2=version2,t1="",t2="";
        int n1=v1.size(),n2=v2.size(),i=0,j=0;
        while(i<n1 || j<n2)
        {
            while(i<n1 && v1[i]!='.')
            {
                t1.push_back(v1[i]);
                i++;
            }
            while(j<n2 && v2[j]!='.')
            {
                t2.push_back(v2[j]);
                j++;
            }
            //cout<<t1<<" "<<t2<<endl;
            int ver1=0,ver2=0;
            if(!t1.empty())
                ver1=stoi(t1);
            if(!t2.empty())
                ver2=stoi(t2);
            //cout<<ver1<<" "<<ver2<<endl;
            if(ver1>ver2)
                return 1;
            else if(ver1<ver2)
                return -1;
            i++,j++;
            t1="",t2="";
        }
        return 0;
    }
};