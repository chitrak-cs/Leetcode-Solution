class Solution {

private:
    void bfs(int node,vector<int>& visited, vector<vector<int>>& graph){
        visited[node] = 1;
        queue<int>q;
        q.push(node);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int adjnode:graph[curr]){
                if(visited[adjnode] == 0){
                    visited[adjnode] = 1;
                    q.push(adjnode);
                }
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>>graph(n);
        for(auto c:connections){
            int u = c[0];
            int v = c[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int>visited(n,0);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                bfs(i,visited,graph);
                cnt++;
            }
        }

        // if the number of edges is less and n-1 then it will not be possible
        int edges = connections.size();
        if(edges < n-1) return -1;
        // number of edges required is the number of disconnected componenets-1
        return cnt-1;
    }
};