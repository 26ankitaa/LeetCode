class Solution {
public:
int minFallingPathSum(vector<vector<int>>& grid) {
    int fm = 0, sm = 0, pos = -1;
    for (auto i = 0; i < grid.size(); ++i) {
        auto fm2 = INT_MAX, sm2 = INT_MAX, pos2 = -1;
        for (auto j = 0; j < grid[i].size(); ++j) {
            auto mn = j != pos ? fm : sm;
            if (grid[i][j] + mn < fm2) {
                sm2 = fm2;
                fm2 = grid[i][j] + mn;
                pos2 = j;
            } else sm2 = min(sm2, grid[i][j] + mn);
        }
        fm = fm2, sm = sm2, pos = pos2;
    }
    return fm;
    }
};