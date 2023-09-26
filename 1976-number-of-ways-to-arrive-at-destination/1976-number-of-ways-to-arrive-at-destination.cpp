class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>adj[n];
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>dist(n,1e15),way(n,0);
        dist[0]=0,way[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        int mod=(int)(1e9+7);
        while(!pq.empty())
        {
            long long node=pq.top().second,dis=pq.top().first;
            pq.pop();
            for(auto it:adj[node])
            {
                long long adj_node=it.first,adj_dis=it.second;
                if(dis+adj_dis<dist[adj_node])
                {
                    dist[adj_node]=(dis+adj_dis);
                    pq.push({dis+adj_dis,adj_node});
                    way[adj_node]=way[node];
                }
                else if(dis+adj_dis==dist[adj_node])
                {
                    way[adj_node]=(way[adj_node]+way[node])%mod;
                }
            }
            
        }
        return way[n-1]%mod;
    }
};