class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });

        vector<int> heights;
        for (const auto& envelope : envelopes) {
            heights.push_back(envelope[1]);
        }

        vector<int> ans;

        for (const int height : heights) {
            auto it = lower_bound(ans.begin(), ans.end(), height);

            if (it == ans.end())
                ans.push_back(height);

            else
                *it = height;
        }
        return ans.size();
    }
};