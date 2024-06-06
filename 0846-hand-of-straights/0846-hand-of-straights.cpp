class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if(hand.size()%groupSize!=0)
            return false;
        
        map<int,int>m;
        //sort(hand.begin(),hand.end());
        for(int x:hand)
            m[x]++;
        
        vector<int> temp;
        for (auto& pair : m) {
            temp.push_back(pair.first);
        }
        
        sort(temp.begin(), temp.end());

        for (int key : temp) {
            if (m[key] > 0) {
                int startCount = m[key];
                for (int i = key; i < key + groupSize; i++) {
                    if (m[i] < startCount) {
                        return false;
                    }
                    m[i] -= startCount;
                }
            }
        }
        return true;
    }
};