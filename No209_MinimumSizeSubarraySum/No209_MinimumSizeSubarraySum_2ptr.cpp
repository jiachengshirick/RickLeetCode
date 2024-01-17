class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int left = 0;
        int Output = INT_MAX;
        for (int i = 0; i < n; i++ ){
            sum += nums[i];
            while(sum >= target){
                Output = min(Output, i + 1 - left);
                sum-=nums[left++];
            }
        }
        return Output == INT_MAX ? 0 : Output;
    }
};