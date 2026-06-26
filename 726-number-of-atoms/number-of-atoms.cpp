class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        st.push(map<string, int>());

        int i = 0, n = formula.size();

        while (i < n) {

            if (formula[i] == '(') {
                st.push(map<string, int>());
                i++;
            }

            else if (formula[i] == ')') {
                i++;

                int mult = 0;
                while (i < n && isdigit(formula[i])) {
                    mult = mult * 10 + (formula[i] - '0');
                    i++;
                }
                if (mult == 0) mult = 1;

                map<string, int> top = st.top();
                st.pop();

                for (auto &p : top) {
                    st.top()[p.first] += p.second * mult;
                }
            }

            else {

                string atom;
                atom += formula[i++];

                while (i < n && islower(formula[i])) {
                    atom += formula[i++];
                }

                int cnt = 0;
                while (i < n && isdigit(formula[i])) {
                    cnt = cnt * 10 + (formula[i] - '0');
                    i++;
                }

                if (cnt == 0) cnt = 1;

                st.top()[atom] += cnt;
            }
        }

        string ans;

        for (auto &p : st.top()) {
            ans += p.first;
            if (p.second > 1)
                ans += to_string(p.second);
        }

        return ans;
    }
};