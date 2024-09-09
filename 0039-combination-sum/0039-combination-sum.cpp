class Solution {
public:
    vector<vector<int>> ans;
    int tar = 0;

    void sub(vector<int>& cad, int i, vector<int>& curr, int sum) {
        if (sum == tar) {
            ans.push_back(curr);
            return;
        }
        if (sum > tar || i == cad.size()) {
            return;
        }
        curr.push_back(cad[i]);
        sub(cad, i, curr, sum + cad[i]);
        curr.pop_back(); 
        sub(cad, i + 1, curr, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& cad, int target) {
        tar = target;
        vector<int> current;
        sub(cad, 0, current, 0);
        return ans;
    }
};
