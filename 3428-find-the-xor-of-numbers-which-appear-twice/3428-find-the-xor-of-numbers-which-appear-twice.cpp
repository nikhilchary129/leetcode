class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        map<int,int>maper;
        for(auto x: nums)maper[x]++;
        int ans=0;
        for(auto [x,y]: maper){
            if(y==2) if(ans==0)ans=x;
                     else ans^=x;
        }
        return ans;
    }
};