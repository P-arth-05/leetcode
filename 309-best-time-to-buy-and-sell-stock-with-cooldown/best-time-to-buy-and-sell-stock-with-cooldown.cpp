class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0];
        int sold = INT_MIN;
        int rest = 0;

        for (int i = 1; i < prices.size(); i++) {
            int newHold = max(hold, rest - prices[i]);
            int newSold = hold + prices[i];
            int newRest = max(rest, sold);

            hold = newHold;
            sold = newSold;
            rest = newRest;
        }

        return max(sold, rest);
    }
};