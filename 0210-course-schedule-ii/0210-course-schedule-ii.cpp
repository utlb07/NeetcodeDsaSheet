class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
          vector<int> indeg(V, 0);
queue<int> q;
vector<int> ans;
        vector<int>adj[V];
for(auto it:prerequisites)
{
    adj[it[1]].push_back(it[0]);
}
for (int u = 0; u < V; u++) {
    for (int it : adj[u]) {
        indeg[it]++;
    }
}

for (int i = 0; i < V; i++) {
    if (indeg[i] == 0) {
        q.push(i);
    }
}

while (!q.empty()) {
    int u = q.front();
    q.pop();
    ans.push_back(u);

    for (int it : adj[u]) {
        indeg[it]--;
        if (indeg[it] == 0) {
            q.push(it);
        }
    }
}
return ans.size()==V?ans:vector<int>();
    }
};