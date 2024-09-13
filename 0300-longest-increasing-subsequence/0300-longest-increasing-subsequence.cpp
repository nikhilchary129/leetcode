class Solution {
public:
    int rec(vector<int>& nums, int prev, int index, vector<vector<int>>& dp) {
        if (index >= nums.size()) return 0;

        if (dp[prev + 1][index] != -1) return dp[prev + 1][index];

        int notTake = rec(nums, prev, index + 1, dp);
        int take = 0;

        if (prev == -1 || nums[index] > nums[prev]) {
            take = 1 + rec(nums, index, index + 1, dp);
        }

        return dp[prev + 1][index] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size(), -1));
        return rec(nums, -1, 0, dp);
    }
};
