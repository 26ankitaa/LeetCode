class Solution {

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    bool isSafe(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == '0' || vis[row][col])
        {
            return false;
        }

        return true;
    }
    void bfsAlgo(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &vis)
    {
        queue<pair<int,int>> q;
        q.push({row, col});

        while(!q.empty())
        {
            int sRow = q.front().first;
            int sCol = q.front().second;

            q.pop();

            vis[sRow][sCol] = true;

            for(int k = 0; k < 4; k++)
            {
                int newRow = sRow + dr[k];
                int newCol = sCol + dc[k];

                if(isSafe(newRow, newCol, grid, vis))
                {
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = true;
                }
            }
        }

        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    bfsAlgo(i, j, grid, vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};