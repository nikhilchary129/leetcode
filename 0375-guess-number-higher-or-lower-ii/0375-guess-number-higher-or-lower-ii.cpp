class Solution {
public:
    long rec(int s,int e,vector<vector<long>>& dp){
        if(s>=e)return 0;
        if(dp[s][e]!= -1)return dp[s][e];
        long ans=INT_MAX;
        for(int i=s;i<=e;i++)ans=min(ans,i+max(rec(s,i-1,dp),rec(i+1,e,dp)));
        return dp[s][e]=ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<long>>dp(n+1,vector<long>(n+1,-1));
        return (int)rec(1,n,dp);

    }
};