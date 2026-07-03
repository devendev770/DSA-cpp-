class Solution {
public:
    vector<vector<int>> ans;
    vector<int> instore;

    void tt(vector<int>& candidates, int target, int index) {

        if (target == 0) {
            ans.push_back(instore);
            return;
        }

        if (target < 0)
            return;

        for (int i = index; i < candidates.size(); i++) {
            instore.push_back(candidates[i]);

            
            tt(candidates, target - candidates[i], i);

            
            instore.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        tt(candidates, target, 0);
        return ans;
    }
};