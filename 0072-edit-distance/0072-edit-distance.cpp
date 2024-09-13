class Solution {
public:
    vector<vector<int>> dp;

    // int solve(string& word1, string& word2, int i, int j) {
    //     if (i == word1.size()) return word2.size() - j;
    //     if (j == word2.size()) return word1.size() - i;

    //     if (dp[i][j] != -1) return dp[i][j];

    //     if (word1[i] == word2[j]) 
    //         return dp[i][j] = solve(word1, word2, i + 1, j + 1);

    //     int ins = 1 + solve(word1, word2, i, j + 1);
    //     int del = 1 + solve(word1, word2, i + 1, j);
    //     int rep = 1 + solve(word1, word2, i + 1, j + 1);

    //     return dp[i][j] = min({ins, del, rep});
    // }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        dp.resize(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++) dp[i][m] = n - i;
        for (int j = 0; j <= m; j++) dp[n][j] = m - j;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    int ins = 1 + dp[i][j + 1];
                    int del = 1 + dp[i + 1][j];
                    int rep = 1 + dp[i + 1][j + 1];
                    dp[i][j] = min({ins, del, rep});
                }
            }
        }

        return dp[0][0];
    }
};
