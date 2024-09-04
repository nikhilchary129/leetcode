class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& xs) {
       
        set<pair<int, int>> seter;
        for (const auto& x : xs) {
            seter.insert({x[0], x[1]});
        }
        
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0; 
        int x = 0, y = 0; 
        int maxer = 0; 
        
        for (int cmd : commands) {
            if (cmd == -1) {
               
                dir = (dir + 1) % 4;
            } else if (cmd == -2) {
                
                dir = (dir + 3) % 4; 
            } else {
              
                for (int step = 0; step < cmd; ++step) {
                    int newX = x + direction[dir][0];
                    int newY = y + direction[dir][1];
                    
                    if (seter.count({newX, newY})) {
                        break;
                    }
                    
                    x = newX;
                    y = newY;
                    
                  maxer = max(maxer, x * x + y * y);
                }
            }
        }
        
        return maxer;
    }
};
