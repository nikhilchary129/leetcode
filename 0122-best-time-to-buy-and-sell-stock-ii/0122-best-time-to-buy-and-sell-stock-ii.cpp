class Solution {
private:
    
    int rec(vector<int>& prices,int index,int buy,vector<vector<int>> &dp)
    {
             if(index==prices.size()) return 0;
             int profit=0;

             if(dp[index][buy]!=-1) return dp[index][buy];

             if(buy)
             {
                int sell=-prices[index]+rec(prices,index+1,0,dp);
                int skip=0+rec(prices,index+1,1,dp);
                 profit=max(sell,skip);
             }else
             {
                int sell=+prices[index]+rec(prices,index,1,dp);
                int skip=0+rec(prices,index+1,0,dp);
                profit=max(sell,skip);
             }
             return dp[index][buy]=profit;
    }  

 
public:
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
         vector<vector<int>> dp(n+1,vector<int>(2,-1));
         return rec(prices,0,1,dp);
    }
};