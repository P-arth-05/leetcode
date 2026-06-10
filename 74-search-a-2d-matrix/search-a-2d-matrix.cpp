class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0, down = m-1, left = 0, right = n-1;
        while(up <= down){
            int mid = up + (down - up)/2;
            if (matrix[mid][n-1] < target) up = mid + 1;
            else if (matrix[mid][0] > target) down = mid - 1;
            else break;
        }
        if (up>down) return false;
        int row = up + (down - up)/2;
        while (left <= right) {
            int midCol = left + (right - left) / 2;
            
            if (matrix[row][midCol] == target) {
                return true;
            } else if (matrix[row][midCol] < target) {
                left = midCol + 1;
            } else {
                right = midCol - 1;
            }
        }
        return false;
    }
};