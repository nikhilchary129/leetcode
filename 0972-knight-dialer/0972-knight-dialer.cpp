class Solution {
public:
    unordered_map<int, vector<int>> pos;
    int mod = 1e9 + 7;
    int rec(int n, int i, vector<vector<int>>& dp) {
        if (n == 0)
            return 1;
        if (dp[n][i] != -1)
            return dp[n][i];
        int ans = 0;
        for (auto it : pos[i]) {
            ans =(ans+ rec(n - 1, it, dp)) % mod;
        }
        return dp[n][i] = ans;
    }
    int knightDialer(int n) {
        pos = {
            {1, {8, 6}},
            {2, {7, 9}},
            {3, {4, 8}},
            {4, {9, 3, 0}},
            {6, {1, 7, 0}}, 
            {7, {2, 6}}, 
            {8, {1, 3}},
            {9, {4, 2}},
            {0, {4, 6}},

        };
        if (n == 1)
            return 10;
        int res = 0;
        vector<vector<int>> dp(n, vector<int>(10, -1));

        for (int i = 0; i <= 9; i++) {
            
                res = (res+ rec(n - 1, i, dp)) % mod;
        }

        return res;
    }
};