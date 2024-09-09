class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1,z=nums.size()-1;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            while(j<z){
                int store=nums[i]+nums[j]+nums[z];
                if(store==0){
                    ans.insert({nums[i],nums[j],nums[z]});
                    j++,z--;
                    while (j < z && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    while (j < z && nums[z] == nums[z + 1]) {
                        z--;
                    }
                }else if(store<0){
                    j++;
                }else  z--;
            }
        }
        vector<vector<int>> vec(ans.begin(),ans.end());

        return vec;
    }
};