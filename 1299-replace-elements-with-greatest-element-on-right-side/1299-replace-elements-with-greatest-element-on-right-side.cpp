class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxo=-1;
        for(int i=arr.size()-1;i>=0;i--)
        {   int t=arr[i];
            arr[i]=maxo;
            maxo=max(maxo,t);
        }
        return arr;
    }
};