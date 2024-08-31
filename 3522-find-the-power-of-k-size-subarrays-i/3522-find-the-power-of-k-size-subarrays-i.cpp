class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
           vector<int> ans;
        int n = nums.size();

        for (int i = 0; i <= n - k; ++i) {
            bool flag = true;
            for (int j = i + 1; j < i + k; ++j) {
                if (nums[j] != nums[j - 1] + 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans.push_back(*max_element(nums.begin() + i, nums.begin() + i + k));
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};