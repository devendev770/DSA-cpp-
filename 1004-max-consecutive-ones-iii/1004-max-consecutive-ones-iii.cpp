class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0; //initial
        int length = 0;
        int count =0;     //zero
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }
            while(count>k){
                if(nums[left]==0){
                    count--;
                }
                left++;
                

            }
            length = max(i - left+1,length);
        }
        return length;
        
    }
};