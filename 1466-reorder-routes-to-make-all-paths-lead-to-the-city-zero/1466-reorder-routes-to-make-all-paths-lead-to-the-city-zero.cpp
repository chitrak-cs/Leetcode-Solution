class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);

        // build graph
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back({v, 1}); // original direction
            adj[v].push_back({u, 0}); // reverse direction
        }

        queue<pair<int,int>> q;
        // queue stores {node, direction}
        q.push({0, -1});

        vector<int> visited(n, 0);
        visited[0] = 1;

        int cnt = 0;

        while (!q.empty()) {
            int node = q.front().first;
            int dir = q.front().second;
            q.pop();

            if (dir == 1) cnt++;

            for (auto it : adj[node]) {
                int adjnode = it.first;
                int adjdir = it.second;

                if (visited[adjnode] == 0) {
                    visited[adjnode] = 1;
                    q.push({adjnode, adjdir});
                }
            }
        }

        return cnt;
    }
};