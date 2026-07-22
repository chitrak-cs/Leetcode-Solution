class Solution {
private:
    int bfs(int curr,vector<vector<int>>& graph){
        int n = graph.size();
        vector<int>visited(n,0);
        int cnt = 1;
        queue<int>q;
        q.push(curr);
        visited[curr] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto adjnode:graph[node]){
                if(visited[adjnode] == 0){
                    visited[adjnode] = 1;
                    q.push(adjnode);
                    cnt++;
                }
            }
        }
        return cnt;
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>>graph(n);

        for(int i=0;i<n;i++){
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r = bombs[i][2];

            for(int j=0;j<n;j++){
                if(i==j) continue;

                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];

                long long xrel = abs(x1-x2);
                long long yrel = abs(y1-y2);

                long long dist = xrel*xrel + yrel*yrel;
                if(dist <= r*r){
                    graph[i].push_back(j);
                }
            }
        }

        int ans = 1;
        for(int i=0;i<n;i++){
            int val = bfs(i,graph);
            ans = max(ans,val);
        }
        return ans;
    }
};