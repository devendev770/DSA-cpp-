class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count = 0;
        
        for (char i : s) {
            if (i == '(') {
                st.push(i);
            } else {
                if (st.empty()) {
                    count++; // Unmatched closing parenthesis
                } else {
                    st.pop(); // Pair matched, remove the opening bracket
                }
            }
        }
        
        // The remaining elements in the stack are unmatched opening parentheses
        return count + st.size();
    }
};