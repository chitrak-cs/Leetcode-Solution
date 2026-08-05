class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        // Build graph
        vector<vector<int>> adj(n);

        for (auto &it : invocations) {
            adj[it[0]].push_back(it[1]);
        }

        // BFS to find all suspicious methods
        vector<int> vis(n, 0);
        queue<int> q;

        q.push(k);
        vis[k] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto next : adj[node]) {
                if (!vis[next]) {
                    vis[next] = 1;
                    q.push(next);
                }
            }
        }

        // Check if any outside method calls a suspicious method
        for (auto &it : invocations) {
            int u = it[0];
            int v = it[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Remove suspicious methods
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};