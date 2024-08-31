class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int ans=0;
        for(int i=1;i<word.size();i++){
            if(word[i]==word[i-1] || abs( word[i-1]-word[i])== 1 ){
                word[i]=' ';
                ans++;
            }
        }
        return ans;
    }
};