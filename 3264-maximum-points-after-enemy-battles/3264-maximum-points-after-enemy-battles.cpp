class Solution {
public:
    long long maximumPoints(vector<int>& enemy, int k) {
        long long n=enemy.size();
        sort(enemy.begin(),enemy.end());
        int i=0,j=n-1;
        long long ans=0;
        while(i<=j){
            if(enemy[i]>k){
                if(ans==0)return 0;
                while(k<enemy[i]){
                    k+=enemy[j];
                    j--;
                }
            }else{
                long long inc=k/enemy[i];
                k=k%enemy[i];
                ans+=inc;
            }
        }
        return ans;

    }
};