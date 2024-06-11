class Solution {
public:
    void solve(vector<vector<char>>& board) {
          int r = board.size(), c = board[0].size();
        vector<vector<bool>>vis(r,vector<bool>(c,0));
        int alt[] = {0,1,0,-1,0};

        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if((i==0 || j==0 || i==r-1||j==c-1) && !vis[i][j] && board[i][j] == 'O'){
                    q.push({i,j});//adding boundary O's
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            auto f = q.front();   q.pop();
            int x = f.first;
            int y = f.second;
            for(int k=0;k<4;k++){
                int nx = x + alt[k];
                int ny = y + alt[k+1];
                if(nx < r && nx >= 0 && ny < c && ny >= 0 && board[nx][ny] == 'O' && !vis[nx][ny]){
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';//now making the zeros except boundary X
            }
        }
    }
};