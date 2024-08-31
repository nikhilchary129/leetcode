class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        if(n<=2){
            return s.length();
        }

        unordered_map<char,int>maper;
        for(int i=0;i<n;i++){
            maper[s[i]]++;
        }

        int ans=0;
        for(auto it:maper){
            if(it.second%2){
                ans=ans+1;
            }else{
                ans=ans+2;
            }
        }
      

        return ans;
    }
};