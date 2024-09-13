class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0, n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int s = intervals[0][0], e = intervals[0][1];
        for(int i=1; i<n; i++){
            if(intervals[i][0] < e){
                count++;
                e = min(e, intervals[i][1]);
            }
            else{
                e = intervals[i][1];
                s = intervals[i][0];
            }
        }

        return count;
    }
};