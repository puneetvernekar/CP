class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0,dif;
        vector<int>vec={0};
        for(int i=0;i<gain.size();i++)
        {
            sum+=gain[i];
            vec.push_back(sum);
        }
        return *max_element(vec.begin(),vec.end());
    }
};