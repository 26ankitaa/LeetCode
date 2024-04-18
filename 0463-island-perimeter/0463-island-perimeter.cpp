class Solution {
public:
    bool isSafe(int x, int y, vector<vector<int>>& grid){
        return (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size());
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int perimeter = 0;
        int x[] = {-1, 1, 0, 0};
        int y[] = {0, 0, -1, 1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    for(int k = 0; k < 4; k++){
                        int newX = i + x[k];
                        int newY = j + y[k];
                        if(isSafe(newX, newY, grid) && grid[newX][newY] == 0){
                            perimeter += 1;
                        }
                        if(!isSafe(newX, newY, grid)){
                            perimeter += 1;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};