class Solution {
public:
set<vector<int>> ans;
    void rec(int curr,int target,int index,vector<int>vec,vector<int>candidates){
        if(index>candidates.size()-1)return;
        if(curr>target)return;
        if(curr==target){
            ans.insert(vec);
            return;
        }
         rec(curr,target,index+1,vec,candidates); 
         vec.push_back(candidates[index]);

        rec(curr+candidates[index],target,index,vec,candidates);
        rec(curr+candidates[index],target,index+1,vec,candidates);
             
        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>vec;
            rec(0,target,0,vec,candidates);
            vector<vector<int>>temp(ans.begin(),ans.end());
            return temp;
    }
};