class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hash(26,0);
        vector<int> hash2(26,0);
        vector<int> ans;

        if(p.size() > s.size())
            return ans;

        for(auto& i : p){
            hash[i-'a']++;
        }

        int size = p.size();

        for(int j = 0; j < size; j++){
            hash2[s[j]-'a']++;
        }

        for(int k = size; k < s.size(); k++){
            if(hash == hash2){
                ans.push_back(k-size);
            }

            hash2[s[k]-'a']++;
            hash2[s[k-size]-'a']--;
        }

        if(hash == hash2){
            ans.push_back(s.size()-size);
        }

        return ans;
    }
};