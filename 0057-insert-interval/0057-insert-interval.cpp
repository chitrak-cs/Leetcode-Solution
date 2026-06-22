class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n==0){
            vector<vector<int>> res;
            res.push_back(newInterval);
            return res;
        }
        int ind = 0;
        vector<vector<int>> ans;
        // Left part that doesn't collide with the new interval
        while(ind < n && intervals[ind][1] < newInterval[0]){
            ans.push_back(intervals[ind]);
            ind++;
        }

        while(ind < n && intervals[ind][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0],intervals[ind][0]);
            newInterval[1] = max(newInterval[1],intervals[ind][1]);
            ind++;
        }
        ans.push_back(newInterval);

        // right part that doesn't collide
        while(ind < n){
            ans.push_back(intervals[ind]);
            ind++;
        }
        return ans;

    }
};