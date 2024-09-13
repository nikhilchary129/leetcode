class Solution {
public:
    int minBitFlips(int s, int g) {
        int ans = 0;
        while (s || g) {
            ans += (s % 2 != g % 2);
            s /= 2, g /= 2;
        }
        return ans;
    }
};