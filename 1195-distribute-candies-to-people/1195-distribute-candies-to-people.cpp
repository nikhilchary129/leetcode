class Solution {
public:
    vector<int> distributeCandies(int candies, int np) {
        vector<int>ans(np,0);
        int i=1;
        int index=0;
        while(candies){
            index%=np;
            if(i>candies){
                ans[index]+=candies;
                break;
            }
            ans[index]+=i;
            candies -=i;
            i++;
            index++;
        }
        return ans;
        
    }
};