class Solution
{
    public:
        int orangesRotting(vector<vector < int>> &grid){
 int n = grid.size();
        int m = grid[0].size();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        int t = 0;
        while (!q.empty()) {
            int sx = q.front().first.first;
            int sy = q.front().first.second;
            int time = q.front().second;
            q.pop();
            t = max(t, time);
            for (int i = 0; i < 4; i++) {
                int nrow = sx + dx[i];
                int ncol = sy + dy[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, time + 1}); 
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 2) return -1;
            }
        }
        return t;
    }
};