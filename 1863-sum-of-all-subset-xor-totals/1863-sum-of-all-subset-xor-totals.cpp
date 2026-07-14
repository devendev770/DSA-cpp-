class Solution {
public:

    int solve(vector<int>& nums, int index, int xorValue)
    {
        if(index == nums.size())
            return xorValue;

        int include = solve(nums, index + 1, xorValue ^ nums[index]);

        
        int exclude = solve(nums, index + 1, xorValue);

        return include + exclude;
    }

    int subsetXORSum(vector<int>& nums)
    {
        return solve(nums, 0, 0);
    }
};