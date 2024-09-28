class Solution {
public:
    int rec(vector<int>& nums, int i, int mod, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return mod == 0 ? 0 : -1e9;
        }
        if (dp[i][mod] != -1) return dp[i][mod];

        int exclude = rec(nums, i + 1, mod, dp);
        int include = nums[i] + rec(nums, i + 1, (mod + nums[i]) % 3, dp);
        
        return dp[i][mod] = max(exclude, include);
    }

    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(3, -1));
        return rec(nums, 0, 0, dp);
    }
};
