class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        
        // 1. Prefix sum array (1-indexed for easy range sums)
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // 2. Previous Smaller Element (left boundary)
        vector<int> left(n, -1);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        // Clear stack for Next Smaller Element
        while (!st.empty()) st.pop();

        // 3. Next Smaller Element (right boundary)
        vector<int> right(n, n);
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        // 4. Maximum Min-Product calculate karo
        long long maxProduct = 0;
        for (int i = 0; i < n; ++i) {
            int l = left[i] + 1;
            int r = right[i] - 1;
            long long currentSum = prefix[r + 1] - prefix[l];
            long long currentProduct = (long long)nums[i] * currentSum;
            maxProduct = max(maxProduct, currentProduct);
        }

        long long MOD = 1e9 + 7;
        return maxProduct % MOD;
    }
};