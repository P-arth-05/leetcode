#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Edge case: No zigzag pattern is possible or necessary
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Create an array of strings for each row. 
        // We only need as many rows as the string length or numRows, whichever is smaller.
        std::vector<std::string> rows(std::min(numRows, int(s.length())));
        
        int curRow = 0;
        bool goingDown = false;

        // Iterate through each character in the string
        for (char c : s) {
            // Append the character to the current row
            rows[curRow] += c;

            // If we hit the top or bottom row, reverse the direction
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // Move the current row pointer up or down
            curRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows into the final result string
        std::string result;
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};