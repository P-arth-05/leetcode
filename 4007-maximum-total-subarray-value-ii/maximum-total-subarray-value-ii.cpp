class SparseTable {
    vector<vector<int>> maxTable;
    vector<vector<int>> minTable;
    vector<int> logTable;
public:
    SparseTable(const vector<int>& arr) {
        int n = arr.size();
        
        // Precompute logarithms for O(1) queries
        logTable.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            logTable[i] = logTable[i / 2] + 1;
        }
        
        int maxLog = logTable[n] + 1;
        maxTable.assign(n, vector<int>(maxLog));
        minTable.assign(n, vector<int>(maxLog));
        
        // Base case: intervals of length 1
        for (int i = 0; i < n; i++) {
            maxTable[i][0] = arr[i];
            minTable[i][0] = arr[i];
        }
        
        // Build the table for intervals of length 2^j
        for (int j = 1; j < maxLog; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                maxTable[i][j] = max(maxTable[i][j - 1], maxTable[i + (1 << (j - 1))][j - 1]);
                minTable[i][j] = min(minTable[i][j - 1], minTable[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    
    long long queryDiff(int l, int r) {
        int j = logTable[r - l + 1];
        int maxVal = max(maxTable[l][j], maxTable[r - (1 << j) + 1][j]);
        int minVal = min(minTable[l][j], minTable[r - (1 << j) + 1][j]);
        return (long long)maxVal - minVal;
    }
};

struct Element {
    long long val;
    int l;
    int r;
    
    // Max Heap requires overloading the < operator
    bool operator<(const Element& other) const {
        return val < other.val; 
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Build the O(1) range query table
        SparseTable st(nums);
        priority_queue<Element> pq;
        
        // Push the most optimal subarray (stretching to the end) for each starting index
        for (int l = 0; l < n; l++) {
            pq.push({st.queryDiff(l, n - 1), l, n - 1});
        }
        
        long long total = 0;
        
        // Extract the K best subarrays
        for (int i = 0; i < k; i++) {
            Element top = pq.top();
            pq.pop();
            
            total += top.val;
            
            // If the subarray can still be shrunk, calculate its new value and push it back
            if (top.r > top.l) {
                pq.push({st.queryDiff(top.l, top.r - 1), top.l, top.r - 1});
            }
        }
        
        return total;
    }
};