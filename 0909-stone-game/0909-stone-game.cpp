class Solution {
public:
    int rec(vector<vector<int>>&dp,vector<int>vec,int s,int l){
        if(l<s)return 0;
        if(dp[s][l]!= -1)return dp[s][l];


        return dp[s][l]=max(vec[s] + rec(dp,vec,s+1,l) ,vec[l] +rec(dp,vec,s,l-1));
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>>dp(piles.size(),vector<int>(piles.size(),-1));
       int maxer= rec(dp,piles,0,piles.size()-1);

        return maxer>(accumulate(piles.begin(),piles.end(),0)/2);
    }
};