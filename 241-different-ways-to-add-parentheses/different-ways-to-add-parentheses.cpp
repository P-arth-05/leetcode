class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;

        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];

            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                for (int l : left) {
                    for (int r : right) {
                        if (c == '+')
                            ans.push_back(l + r);
                        else if (c == '-')
                            ans.push_back(l - r);
                        else
                            ans.push_back(l * r);
                    }
                }
            }
        }

        // Base case: expression is just a number
        if (ans.empty())
            ans.push_back(stoi(expression));

        return ans;
    }
};