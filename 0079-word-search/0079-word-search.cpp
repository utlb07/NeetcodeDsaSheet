class Solution
{
    public:
        int n, m;
    bool fun(vector<vector < char>> &board, string w, int i, int j, int id)
    {
        if (w.length()==id)
        {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] !=w[id])
        {
            return false;
        }
        char temp = board[i][j];
        board[i][j] ='$';
        bool ans=fun(board,w,i-1,j,id+1)||fun(board,w,i+1,j,id+1)||fun(board,w,i,j-1,id+1)||fun(board,w,i,j+1,id+1);
        board[i][j] = temp;
        return ans;
    }
    bool exist(vector<vector < char>> &board, string word)
    {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0] && fun(board, word, i, j, 0) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};