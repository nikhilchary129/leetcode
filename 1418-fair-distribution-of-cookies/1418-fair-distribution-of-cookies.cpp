class Solution {
public:
    
    int f(vector<int>& cookies,int k,int i,vector<int> &kvector){
        if(i==cookies.size()){
            int ans=0;
            for(int j=0;j<k;j++){
                ans=max(ans,kvector[j]);
            }
            return ans;
        }

        int curr=INT_MAX;
        for(int j=0;j<k;j++){
            kvector[j]+=cookies[i];
            curr=min(curr,f(cookies,k,i+1,kvector));
            kvector[j]-=cookies[i];
        }
        return curr;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> kvector(k,0);
        
        return f(cookies,k,0,kvector);
    }
};