class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int c) {
        if(c==1)return nums;
        vector<int>ans;
        int n=nums.size();
        int i=1;int k=1;
        while(i<n){
            if(nums[i]-1==nums[i-1])k+=1;
            else k=1;

            if(i>=c-1){
                ans.push_back((k>=c)?nums[i]: -1);
            }
            ++i;
        }
        return ans;
    }
};