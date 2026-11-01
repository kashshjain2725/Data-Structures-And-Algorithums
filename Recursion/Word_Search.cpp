#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool check(int index, int row, int column, vector<vector<char>>& board, const string& word) {
        if (index == word.size()) {
            return true;
        }
        if (row < 0 || row >= board.size() || column < 0 || column >= board[0].size()) {
            return false;
        }
        if (board[row][column] == '#' || board[row][column] != word[index]) {
            return false;
        }

        char temp = board[row][column];
        board[row][column] = '#';

        bool ans = false;
        if (row - 1 >= 0) ans |= check(index + 1, row - 1, column, board, word);
        if (row + 1 < board.size()) ans |= check(index + 1, row + 1, column, board, word);
        if (column - 1 >= 0) ans |= check(index + 1, row, column - 1, board, word);
        if (column + 1 < board[0].size()) ans |= check(index + 1, row, column + 1, board, word);

        board[row][column] = temp;
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (check(0, i, j, board, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                 {'S', 'F', 'C', 'S'},
                                 {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    Solution s;
    bool answer = s.exist(board, word);
    if (answer) {
        cout << "Word Found" << endl;
    } else {
        cout << "Word Not Found" << endl;
    }
    return 0;
}