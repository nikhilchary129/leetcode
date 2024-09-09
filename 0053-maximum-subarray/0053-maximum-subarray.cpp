class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxer=accumulate(nums.begin(),nums.end(),0);
        int curr=0;
        for(auto x: nums){
            curr+=x;
            if(curr>maxer)maxer=curr;
            if(curr<0)curr=0;

        }
        return maxer;
    }
};