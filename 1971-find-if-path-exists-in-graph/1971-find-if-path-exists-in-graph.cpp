class Solution {
public:
    void dfs(vector<int>adj[],int src,int dest,vector<bool>&vis)
    {
        vis[src]=true;
        for(auto i:adj[src])
        {
            if(vis[i]==false)
            {
                dfs(adj,i,dest,vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<int>adj[n+1];
        for(auto edge:edges)
        {
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n+1,false);
        dfs(adj,src,dest,vis);return vis[dest]==true;
    }
};