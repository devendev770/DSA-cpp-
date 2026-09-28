class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int t = temperatures.size();
        stack<int> st;
        vector<int> ans(t,0);
        for(int i = 0;i<t;i++){
            int count = 0;
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                count++;
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};