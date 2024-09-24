class Solution {
public:
    int rec(vector<int>val,int i,int j,vector<vector<int>>&dp){
        if(i+1==j) return 0;
         if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;

        for(int k=i+1;k<j;k++)
        ans=min(val[i]*val[j]*val[k] + rec(val,i,k,dp)+rec(val,k,j,dp), ans);

        return dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& val) {
        vector<vector<int>>dp(val.size(),vector<int>(val.size(),-1));

        return rec(val,0,val.size()-1,dp);
    }
};