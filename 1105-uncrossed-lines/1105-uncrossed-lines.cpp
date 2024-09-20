class Solution {
public:
    int rec(vector<int>a,vector<int>b,int i,int j,vector<vector<int>>&dp){
        if(i==a.size() || j==b.size()) return 0;
        if(dp[i][j]!= -1) return dp[i][j];

        if(a[i]==b[j]){
            dp[i][j]=1+rec(a,b,i+1,j+1,dp);
        }else{
            dp[i][j]=max(rec(a,b,i+1,j,dp),rec(a,b,i,j+1,dp));
        }

        return dp[i][j];

    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,-1));
        return rec(nums1,nums2,0,0,dp);
    }
};