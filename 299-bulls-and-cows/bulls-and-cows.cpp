class Solution {
public:
    string getHint(string secret, string guess) {

        int bulls = 0, cows = 0;
        vector<int> cnt(10, 0);

        for (int i = 0; i < secret.size(); i++) {

            if (secret[i] == guess[i]) {
                bulls++;
            } else {

                int s = secret[i] - '0';
                int g = guess[i] - '0';

                if (cnt[s] < 0)
                    cows++;

                if (cnt[g] > 0)
                    cows++;

                cnt[s]++;
                cnt[g]--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};