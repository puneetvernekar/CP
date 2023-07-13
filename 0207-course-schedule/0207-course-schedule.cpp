class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>course(numCourses);
        vector<int>deg(numCourses,0);
        queue<int>q;
        for(auto pre:prerequisites)
        {
            course[pre[1]].push_back(pre[0]);
            deg[pre[0]]++;
        }
        for(int cou=0;cou<numCourses;cou++)
        {
            if(deg[cou]==0)
                q.push(cou);
        }
        
        while(!q.empty())
        {
            int cou_num=q.front();
            q.pop();
            for(int nxt_cou:course[cou_num])
            {
                deg[nxt_cou]--; 
                if(deg[nxt_cou]==0)
                    q.push(nxt_cou);
            }
        }
        for(int degree:deg)
        {
            if(degree!=0)
                return false;
        }
        return true;
        
    }
};