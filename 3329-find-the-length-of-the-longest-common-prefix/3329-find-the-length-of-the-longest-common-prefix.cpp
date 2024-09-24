class Solution {
public:
    int longestCommonPrefix( vector<int>& arr1,  vector<int>& arr2) {
         unordered_map<int, int> maper;
        for (auto x : arr1) {
            while (x) {
                maper[x] = 1;
                x = x / 10;
            }
        }
        
        for (auto x : arr2) {
            while (x) {
                if (maper[x] == 1) {
                    maper[x] = 2;
                }
                x = x / 10;
            }
        }
        
        int maxer = 0;
        for (const auto& [x, y] : maper) {
            if (y == 2) {
                 string temp =  to_string(x);
                maxer =  max(maxer, static_cast<int>(temp.size())); 
            }
        }
        
        return maxer;
    }
};
