class Solution {
public:
    string goal;
    vector<vector<int>> dp;

    bool rec(string& s1, string& s2, int i, int j, int k) {
        if (k == goal.size()) return true;

        if (dp[i][j] != -1) return dp[i][j];

        bool ans = false;
        if (i < s1.size() && goal[k] == s1[i]) 
            ans = rec(s1, s2, i + 1, j, k + 1);
        if (j < s2.size() && goal[k] == s2[j]) 
            ans = ans || rec(s1, s2, i, j + 1, k + 1);

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) 
            return false;

        dp.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        goal = s3;

        return rec(s1, s2, 0, 0, 0);
    }
};
