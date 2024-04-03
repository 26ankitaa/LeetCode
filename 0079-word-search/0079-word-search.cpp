class Solution {
    bool rec(vector<vector<char>>& board, int i, int j, int m, int n, string &word, int w){
        // base cases
        if(w == word.length()){
            return true;
        }
        if(i<0 || i>=m || j<0 || j>=n){
            return false;
        }
        if(board[i][j] != word[w]){
            return false;
        }
        else{
            char rem = board[i][j];
            board[i][j] = '0';

            // right
            bool right = rec(board, i, j+1, m, n, word, w+1);
            // down
            bool down = rec(board, i+1, j, m, n, word, w+1);
            // left
            bool left = rec(board, i, j-1, m, n, word, w+1);
            // up
            bool up = rec(board, i-1, j, m, n, word, w+1);

            board[i][j] = rem;
        
            return (right || down || left || up);
        }

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        // storing the indices where word[0] == board[i][j]
        vector<pair<int, int>> indices;
        for(int i=0 ; i<board.size() ; i++){
            for(int j=0 ; j<board[0].size() ; j++){
                if(board[i][j] == word[0]){
                    indices.push_back({i, j});
                }
            }
        }

        // check recursively for all indices present in indices vector
        bool ans = false;
        for(auto i: indices){
            ans = ans || rec(board, i.first, i.second, m, n, word, 0);
        }
        
        return ans;
    }
};