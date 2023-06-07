class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> a1(rowIndex+1,1);
        for(int i=1;i<rowIndex;i++)
        {
        for(int j=i;j>0;j--)
        {
            a1[j]=a1[j]+a1[j-1];
        }
        }       
        return a1;
    }
};