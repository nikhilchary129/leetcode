class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
    
        int miner = nums[0];
        
        int maxer = nums[0];
       
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            int temp = miner;           
            miner = max({nums[i], miner * nums[i], maxer * nums[i]});   
            maxer = min({nums[i], temp * nums[i], maxer * nums[i]});
            ans = max({ans, miner,maxer});
            swap(miner,maxer);
        }
        return ans;
    }
};