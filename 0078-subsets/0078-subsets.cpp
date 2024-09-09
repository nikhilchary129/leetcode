class Solution {
public:
    vector<vector<int>>ans;


    void sub(vector<int>nums,int i,vector<int>vec){
        if(i==nums.size()){
            ans.push_back(vec);
            return;
        }
        sub(nums,i+1,vec);
         vec.push_back(nums[i]);
         sub(nums,i+1,vec);
         return;

    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>vec;
        sub(nums,0,vec);
        return ans;
    }
};