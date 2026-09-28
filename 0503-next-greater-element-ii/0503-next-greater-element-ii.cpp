class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < (2 * n) - 1; i++) {
            int t = i % n;
            while (!st.empty() && nums[t] > nums[st.top()]) {
                ans[st.top()] = nums[t]; // Stack ke top index par current
                                         // greater element set karo
                st.pop();
            }
            st.push(t); // Number ki jagah index push karo
        }
        return ans;
    }
};