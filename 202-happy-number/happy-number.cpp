class Solution {
public:
    int happy_function(int n) {
        int res = 0;
        for (; n > 0; n /= 10) res += pow(n % 10, 2); 
        return res;
    }

    bool isHappy(int n) {
        set<int> numbers{4,16,37,58,89,145,42,20};
        while (n != 1) {
            if (numbers.contains(n)) return false;
            n = happy_function(n);
        }
        return true;
    }
};