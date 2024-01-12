class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = target;
        int n = nums.size();
        if (n == 0)
            return 0;
        int ans = INT_MAX;
        vector<int> sums(n + 1, 0); //size = n+1 for easier calculations
        //sums[0]=0 : Meaning that it is the sum of first 0 elements
        //sums[1]=A[0] : Sum of first 1 elements
        //ans so on...
        for (int i = 1; i <= n; i++)
            sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 1; i <= n; i++) {
            int to_find = s + sums[i - 1];
            auto part = sums.begin() + i - 1;
            auto bound = lower_bound(sums.begin(), sums.end(), to_find);
            if (bound != sums.end()) {
                auto begin = bound - part;
                int test = static_cast<int>(begin);
                ans = min(ans, test);
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};