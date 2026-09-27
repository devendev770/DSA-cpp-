class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        unordered_map<int,int> has;
        unordered_map<int,int> tas;
        if(s.size() != t.size()){
            return false;
        }
        for(int i = 0;i<n;i++){
            has[s[i] -'a']++;
            tas[t[i] - 'a']++;
        }
        if(has == tas){
            return true;
        }
        return false;
    }
};