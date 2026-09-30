class Solution {
public:
    int firstUniqChar(string s) {
        int _s = s.size();
        unordered_map<char,int> h;
        for(auto& i : s){
            h[i]++;
        }
        for(int j =0;j<_s;j++){
            if( h[s[j]] == 1){
                return j;
            }
        }
        return -1;
    }
};