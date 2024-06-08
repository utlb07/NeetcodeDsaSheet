class Solution {
public:
    void bfs(int src,vector<int>adj[],vector<bool>&vis)
    {
         queue<int>q;
       
        q.push(src);
        vis[src]=true;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(auto it:adj[curr])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=true;
                  
                }
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
       // vector<int>adj;
         vector<int> adj[n+1];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isConnected[i][j]==1&&i!=j){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int cnt=0;
        vector<bool>vis(n+1,false);
       for(int i=0;i<n;i++)
       {
           if(!vis[i+1])
           {
               bfs(i+1,adj,vis);
               cnt++;
           }
       }
       return cnt;
    }
};