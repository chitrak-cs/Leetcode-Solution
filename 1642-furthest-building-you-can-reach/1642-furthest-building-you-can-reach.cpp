class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        // min heap priority queue
        priority_queue<int,vector<int>,greater<int>>pq;

        vector<int>diff(n-1);
        for(int i=0;i<n-1;i++){
            diff[i] = heights[i] - heights[i+1];
        }

        for(int i=0;i<n-1;i++){
            if(diff[i] >= 0) continue;
            int val = abs(diff[i]);
            pq.push(val);
            if(pq.size() > ladders){
                int removed = pq.top();
                pq.pop();
                if(removed > bricks) return i;
                bricks -= removed;
            }
        }

        return n-1;
    }
};