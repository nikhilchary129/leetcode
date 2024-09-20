class Solution {
public:
    unordered_set<int> seter;

    int rec(int a, int b, int x, bool conc, int curr, vector<vector<int>>& dp) {
        if (curr < 0 || curr > 6000) return 1e9;
        if (seter.count(curr)) return 1e9;
        if (curr == x) return 0;
        if (dp[curr][conc] != -1) return dp[curr][conc];

        dp[curr][conc] = 1+rec(a, b, x, false, curr + a, dp);
         

        int backward = 1e9;
        if (!conc) {
            backward =1+ rec(a, b, x, true, curr - b, dp);
           dp[curr][conc]=min(dp[curr][conc],backward);
        }

        return dp[curr][conc];
    }

    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        vector<vector<int>> dp(6001, vector<int>(2, -1));
        for (int pos : forbidden) {
            seter.insert(pos);
        }

        int ans = rec(a, b, x, false, 0, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};
