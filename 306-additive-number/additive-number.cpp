class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();

        for (int i = 1; i <= n / 2; i++) {

            if (num[0] == '0' && i > 1)
                break;

            for (int j = 1; max(i, j) <= n - i - j; j++) {

                if (num[i] == '0' && j > 1)
                    break;

                long long a = stoll(num.substr(0, i));
                long long b = stoll(num.substr(i, j));

                int pos = i + j;

                while (pos < n) {

                    long long c = a + b;
                    string s = to_string(c);

                    if (num.substr(pos, s.size()) != s)
                        break;

                    pos += s.size();
                    a = b;
                    b = c;
                }

                if (pos == n)
                    return true;
            }
        }

        return false;
    }
};