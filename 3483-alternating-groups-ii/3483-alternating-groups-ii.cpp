class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& col, int k) {
       int n=col.size();
       int ans=0;
       int al=1;
       for(int i=1;i<n+k-1;i++){
            if(col[(i-1)%n]!=col[ (i%n)])al++;
            else al=1;
            if(al>=k)ans++;
       }
       return ans;
    }
};