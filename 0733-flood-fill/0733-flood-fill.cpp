class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int ori= image[sr][sc];
        if(ori==color)
        {
            return image;
        }
        image[sr][sc]=color;
        
        while(!q.empty())
        {
            pair<int,int>ele=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=ele.first+dx[i];
                int y=ele.second+dy[i];
                if(x>=0&&x<n&&y<m&&y>=0&&image[x][y]==ori)
                {
                    q.push({x,y});
                    image[x][y]=color;
                }
            }
        }
        return image;
    }
};