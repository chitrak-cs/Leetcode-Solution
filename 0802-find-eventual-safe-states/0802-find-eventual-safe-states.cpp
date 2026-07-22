class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adj(n);
        vector<int>outdegree(n,0);

        for(int i=0;i<n;i++){
            int u = i;
            outdegree[u] = graph[i].size();
            for(auto v:graph[i]){
                adj[v].push_back(u);
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(outdegree[i] == 0){
                q.push(i);
            }
        }

        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);
            for(auto adjnode:adj[node]){
                outdegree[adjnode]--;
                if(outdegree[adjnode] == 0){
                    q.push(adjnode);
                }
            }
        }


        sort(ans.begin(),ans.end());
        return ans;
    }
};