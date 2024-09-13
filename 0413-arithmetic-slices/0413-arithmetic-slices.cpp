class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
       vector<int>table(nums.size(),0);

        for (int i = 2, n = nums.size(); i < n; i++)
        {
            int diff1 = nums[i] - nums[i-1];
            int diff2 = nums[i-1] - nums[i-2];

            if (diff1 == diff2)
            {
                table[i] = table[i-1] + 1;
                ans += table[i-1] + 1;
            }
        }

        return ans;
    };
};