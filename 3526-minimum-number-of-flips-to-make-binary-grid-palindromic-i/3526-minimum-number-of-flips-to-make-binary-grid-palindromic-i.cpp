
class Solution {
public:
    
    int minFlips(vector<vector<int>>& grid) {
        auto row=grid;
        int ans=0;
        for(auto &x: row){
            int i=0,j=x.size()-1;
            while(i<j){
                if(x[i]!=x[j])ans++;
                j--,i++;
            }
        }
        if(ans==0)return 0;
        int ans2=0;
        //auto col=grid;
        
      //  for(auto x: col){for(auto y:x)cout<<y<<" ";cout<<endl;}
        for(int i=0;i<grid[0].size();i++){
            int l=0,j=grid.size()-1;
            while(l<j){
                if(grid[l][i]!=grid[j][i])ans2++;
                j--,l++;
            }
        }
        return min(ans2,ans);
    }
};