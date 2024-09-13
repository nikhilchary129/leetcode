class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>factor={2,3,5};
        priority_queue<long ,vector<long> ,greater<long> >heaper;
        unordered_set<long>visited;
        heaper.push(1);
        visited.insert(1);
        long curr;
        for(int i=0;i<n;i++){
            curr=heaper.top();
            heaper.pop();
            for(auto x: factor){
                long temp=curr*x;
                if(visited.find(temp)==visited.end()){
                    heaper.push(temp);
                    visited.insert(temp);
                }
            }
        }
        return (int)curr;
    }
};