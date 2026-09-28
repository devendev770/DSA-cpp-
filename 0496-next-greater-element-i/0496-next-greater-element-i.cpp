class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> hash;
        vector<int> ans;
        for(auto& x: nums2){
            while(!st.empty() && x > st.top()){
                hash[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }
        for(auto& y : nums1){
            if(hash.find(y) != hash.end()){
                ans.push_back(hash[y]);
            }
            else{
                ans.push_back(-1);
            }
            
        }
        return ans;
    }
};