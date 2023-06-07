class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double ydif=((coordinates[1][1]-coordinates[0][1])*1.0);
        double xdif=((coordinates[1][0]-coordinates[0][0])*1.0);
        for(int i=2;i<coordinates.size();i++)
        {
            double new_ydif=((coordinates[i][1]-coordinates[0][1])*1.0);
            double new_xdif=((coordinates[i][0]-coordinates[0][0])*1.0);
            if(ydif*new_xdif!=new_ydif*xdif)
            return false;
        }
        return true;
    }
};