#include <vector>

using namespace std;

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        // Numbers under 100 have fewer than 3 digits, so they can't have a peak or valley
        if (num2 <= 100) {
            return 0;
        }
        if (num1 <= 100) {
            num1 = 100;
        }
        
        int count = 0;
        
        // Loop directly from num1 to num2. No need to store them in an array!
        for (int i = num1; i <= num2; i++) {
            count += checkWavy(i);
        }
        
        return count;
    }

    int checkWavy(int n) {
        vector<int> num;
        
        // Extract digits
        for (; n > 0; n /= 10) {
            num.push_back(n % 10); // FIXED: push_back instead of pushback
        }
        
        int count = 0;
        int size = num.size(); // Safe integer cast to prevent underflow
        
        // Check for local minima and maxima
        for (int i = 1; i < size - 1; i++) {
            if (num[i] < num[i - 1] && num[i] < num[i + 1]) {
                count++;
            }
            else if (num[i] > num[i - 1] && num[i] > num[i + 1]) {
                count++;
            }
        }
        return count;
    }
};