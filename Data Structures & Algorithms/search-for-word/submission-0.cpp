class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int Y = board.size(), X = board[0].size();

        // Pruning: character frequency check
        int boardCount[128] = {0}, wordCount[128] = {0};
        for (auto& row : board)
            for (char c : row) boardCount[c]++;
        for (char c : word) wordCount[c]++;
        for (int i = 0; i < 128; i++)
            if (wordCount[i] > boardCount[i]) return false;

        // Search from the rarer end of the word — prunes faster
        if (boardCount[(int)word.back()] < boardCount[(int)word[0]])
            reverse(word.begin(), word.end());

        for (int i = 0; i < Y; i++)
            for (int j = 0; j < X; j++)
                if (board[i][j] == word[0] && backtrack(board, i, j, 0, word))
                    return true;
        return false;
    }

private:
    bool backtrack(vector<vector<char>>& board, int row, int col, int index, const string& word) {
        if (index == word.size()) return true;
        if (row < 0 || row >= (int)board.size() || col < 0 || col >= (int)board[0].size())
            return false;
        if (board[row][col] != word[index]) return false;

        char temp = board[row][col];
        board[row][col] = '#';

        bool found = backtrack(board, row + 1, col, index + 1, word) ||
                     backtrack(board, row - 1, col, index + 1, word) ||
                     backtrack(board, row, col + 1, index + 1, word) ||
                     backtrack(board, row, col - 1, index + 1, word);

        board[row][col] = temp;
        return found;
    }
};