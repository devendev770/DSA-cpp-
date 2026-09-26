class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        int l = 0;
        int r = nums.size()-1;
        for(int i = n-1;i>=0;i--){
            if(abs(nums[l]) < abs(nums[r])){
                arr[i] = nums[r]*nums[r];
                r--;

            }
            else{
                arr[i] = nums[l]*nums[l];
                l++;
            }
        }
        return arr;
    }
};