class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int left=1;
        int n=nums.size();
        int right=nums.size()-2;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]  ) return mid;
            else if( nums[mid]<nums[mid-1]) right=mid-1;
            else left=mid+1;
        }

        int ans= -1;
        if(nums[0]>nums[1]) ans=0;
        if(nums[n-2]<nums[n-1]) ans=n-1;

        return ans;
    }
};