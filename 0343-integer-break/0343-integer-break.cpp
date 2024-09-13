class Solution {
public:
    int rec(int n,vector<int> &dp){
        if(n==1) return 1;
        if(dp[n]!= -1)return dp[n];
        int maxer=0;
        for(int i=1;i<n;i++)maxer=max(maxer,max(i*(n-i),i*rec(n-i,dp)));
        return dp[n]=maxer;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return rec(n,dp);
    }
};