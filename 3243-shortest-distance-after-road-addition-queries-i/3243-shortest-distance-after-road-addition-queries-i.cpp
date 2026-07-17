class Solution {
private:
    int bfs(int V, vector<vector<int>>& adj){
        vector<int>visited(V,0);
        queue<int>q;
        visited[0] = 1;
        q.push(0);

        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front();
                q.pop();

                if(node == V-1) return dist;
                for(auto adjnode:adj[node]){
                    if(visited[adjnode] == 0){
                        visited[adjnode] = 1;
                        q.push(adjnode);
                    }
                }
            }
            dist++;
        }

        return -2;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);
        for(int i=0;i<=n-2;i++){
            int u = i;
            int v = i+1;
            adj[u].push_back(v);
        }

        vector<int>ans;
        for(auto query:queries){
            int u = query[0];
            int v = query[1];

            adj[u].push_back(v);
            int val = bfs(n,adj);
            ans.push_back(val);
        }

        return ans;
    }
};