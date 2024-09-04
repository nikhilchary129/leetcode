class Solution {
public:
    string largestMerge(string s1, string s2) {
        string merge="";
        while(s1.size() || s2.size()){
            if(s1.size()==0){
                merge+=s2;
                break;
            }
            if(s2.size()==0){
                 merge+=s1;
                break;
            }
            if(s1[0]>=s2[0]  && s1>s2){
                merge+=s1[0];
                s1.erase(s1.begin());

            }else{
                 merge+=s2[0];
                s2.erase(s2.begin());
            }
        }

        return merge;
    }
};