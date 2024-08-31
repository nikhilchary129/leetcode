class Solution {
public:
    string losingPlayer(int x, int y) {
        int f=0;//alice
        
        while( x>=1&& y>=4){
            x-=1;
            y-=4;
            f=!f;
        }
        if(f)return "Alice";

        return "Bob";
    }
};