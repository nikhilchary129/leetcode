class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int,unordered_map<int,int> >maper;
        for(auto x: pick){
            maper[x[0]][x[1]]++;
        }
        int ans=0;
        for(auto [x,y]: maper){
            for(auto [z1,z2]:y){
                if(x< z2){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};