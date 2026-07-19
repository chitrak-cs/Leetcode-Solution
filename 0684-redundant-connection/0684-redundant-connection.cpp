class Solution {
private:
    bool dfs(int node, int target, vector<vector<int>>& adj, vector<int>& vis) {
        if (node == target)
            return true;

        vis[node] = 1;

        for (int next : adj[node]) {
            if (!vis[next]) {
                if (dfs(next, target, adj, vis))
                    return true;
            }
        }

        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            vector<int> vis(n + 1, 0);

            // If u can already reach v, adding this edge creates a cycle
            if (dfs(u, v, adj, vis))
                return edge;

            // Otherwise, add the edge
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};