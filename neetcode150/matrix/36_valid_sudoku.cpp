#include <array>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    static constexpr int SIZE = 9;
    bool checkRows(vector<vector<char>>& board) {
        for (int row = 0; row < SIZE; ++row) {
            array<bool, SIZE> idx_checked = {};
            for (int col = 0; col < SIZE; ++col) {
                if (board[row][col] == '.') {
                    continue;
                }
                int idx = board[row][col] - '1';
                if (idx_checked[idx]) {
                    return false;
                }
                idx_checked[idx] = true;
            }
        }
        return true;
    }
    bool checkCols(vector<vector<char>>& board) {
        for (int col = 0; col < SIZE; ++col) {
            array<bool, SIZE> idx_checked = {};
            for (int row = 0; row < SIZE; ++row) {
                if (board[row][col] == '.') {
                    continue;
                }
                int idx = board[row][col] - '1';
                if (idx_checked[idx]) {
                    return false;
                }
                idx_checked[idx] = true;
            }
        }
        return true;
    }
    bool checkSubBoxes(vector<vector<char>>& board) {
        for (int box_idx = 0; box_idx < 9; ++box_idx) {
            int box_row = box_idx / 3;
            int box_col = box_idx % 3;
            array<bool, SIZE> idx_checked = {};
            for (int subblock_idx = 0; subblock_idx < 9; ++subblock_idx) {
                int subblock_row = subblock_idx / 3;
                int subblock_col = subblock_idx % 3;
                int row = box_row * 3 + subblock_row;
                int col = box_col * 3 + subblock_col;
                if (board[row][col] == '.') {
                    continue;
                }
                int idx = board[row][col] - '1';
                if (idx_checked[idx]) {
                    return false;
                }
                idx_checked[idx] = true;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkRows(board) && checkCols(board) && checkSubBoxes(board);
    }
};

int main() {
    Solution s;

    vector<vector<char>> board1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    vector<vector<char>> board2 = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << boolalpha
         << s.isValidSudoku(board1)
         << endl
         << s.isValidSudoku(board2)
         << endl;
}

/*
LeetCode 36. Valid Sudoku

- check rows
- check columns
- check grids

Time: O(N*N)
Space: O(N)

Learning Notes:
1. follow naming convention in question
2. constexpr is evaluated at compile time and can be used in array
3. static for value shared across object
4. use {} for local variable initialization
*/