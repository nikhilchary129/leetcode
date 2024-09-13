class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
    
        int miner = nums[0];
        
        int maxer = nums[0];
       
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            int temp = miner;           
            miner = min({nums[i], miner * nums[i], maxer * nums[i]});   
            maxer = max({nums[i], temp * nums[i], maxer * nums[i]});
            ans = max({ans, miner,maxer});
           // swap(miner,maxer);
        }
        return ans;
    }
};