class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            int countr[9] = {0,0,0,0,0,0,0,0,0};
            int countc[9] = {0,0,0,0,0,0,0,0,0};
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    countr[board[i][j] - '1']++;
                }
            }
            for (int j = 0; j < 9; j++){
                if (board[j][i] != '.'){
                    countc[board[j][i] - '1']++;
                }
            }
            for (int k = 0; k < 9; k++){
                if (countr[k]>1 || countc[k]>1) return false;
            }
        }
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {

                int countg[9] = {0};

                for (int i = boxRow; i < boxRow + 3; i++) {
                    for (int j = boxCol; j < boxCol + 3; j++) {

                        if (board[i][j] != '.') {
                            countg[board[i][j] - '1']++;
                        }
                    }
                }

                for (int k = 0; k < 9; k++) {
                    if (countg[k] > 1)
                        return false;
                }
            }
        }
        
        return true;
    }
};