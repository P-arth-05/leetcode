#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 2; i <= n; i++) {
            string next_result = "";
            int count = 1;
            for (int j = 1; j < result.length(); j++) {
                if (result[j] == result[j - 1]) {
                    count++;
                } else {
                    next_result += to_string(count) + result[j - 1];
                    count = 1;
                }
            }
            next_result += to_string(count) + result.back();
            result = next_result;
        }
        return result;
    }
};