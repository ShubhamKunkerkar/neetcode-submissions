class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        vector<unordered_set<int>> a(n);
        vector<unordered_set<int>> b(n);
        vector<unordered_set<int>> c(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int k = static_cast<int>(floor(i/3)*3 + floor(j/3));
                if(b[i].find(board[i][j]) == b[i].end() && board[i][j] != '.'){
                    b[i].insert(board[i][j]);
                }else if(board[i][j] != '.'){
                    return false;
                }
                if(c[j].find(board[i][j]) == c[j].end() && board[i][j] != '.'){
                    c[j].insert(board[i][j]);
                }else if(board[i][j] != '.'){
                    return false;
                }
                if(board[i][j] != '.' && a[k].find(board[i][j]) == a[k].end()){
                    a[k].insert(board[i][j]);
                }else if(board[i][j] != '.'){
                    return false;
                }
            }
                
        }
        return true;
    }
};
