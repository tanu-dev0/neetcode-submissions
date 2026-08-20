class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // 9 rows ke liye 9 sets
        vector<unordered_set<char>> rows(9);

        // 9 columns ke liye 9 sets
        vector<unordered_set<char>> cols(9);

        // 9 boxes ke liye 9 sets
        vector<unordered_set<char>> boxes(9);

        // Har cell ko ek baar check karenge
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {

                // Empty cell ko ignore karo
                if (board[r][c] == '.')
                    continue;

                char num = board[r][c];

                // Current 3x3 box ka number
                int box = (r / 3) * 3 + (c / 3);

                // Agar number row, column ya box me already hai
                // to Sudoku invalid hai
                if (rows[r].count(num) ||
                    cols[c].count(num) ||
                    boxes[box].count(num)) {
                    return false;
                }

                // Number ko teenon jagah store karo
                rows[r].insert(num);
                cols[c].insert(num);
                boxes[box].insert(num);
            }
        }

        return true;
    }
};
