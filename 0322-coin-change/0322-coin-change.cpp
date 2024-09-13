class Solution {
public:
    vector<vector<int>> dp;

    int rec(vector<int>& coins, int index, int amount) {
        if (amount == 0) return 0;
        if (amount < 0 || index >= coins.size()) return INT_MAX - 1;

        if (dp[amount][index] != -1) return dp[amount][index];

        int notTake = rec(coins, index + 1, amount);
        
        int take = INT_MAX - 1;
        if (coins[index] <= amount) {
            take = 1 + rec(coins, index, amount - coins[index]);
        }

        return dp[amount][index] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount + 1, vector<int>(coins.size(), -1));
        sort(coins.begin(), coins.end());

        int result = rec(coins, 0, amount);
        return result == INT_MAX - 1 ? -1 : result;
    }
};
