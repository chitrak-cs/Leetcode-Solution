class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>graph;
        vector<int>ans;
        for(auto edges:adjacentPairs){
            int u = edges[0];
            int v = edges[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // adding the root node and its adjacent node to the answer
        for(auto it:graph){
            int node = it.first;
            vector<int>edgelist = it.second;
            if(edgelist.size() == 1){
                ans.push_back(node);
                int adjnode = edgelist[0];
                ans.push_back(adjnode);
                break;
            }
        }

        int n = graph.size();
        while(ans.size() < n){
            int len = ans.size();
            int last = ans[len-1];
            int secondlast = ans[len-2];

            vector<int>adjlist = graph[last];
            if(adjlist[0] != secondlast){
                ans.push_back(adjlist[0]);
            }
            else ans.push_back(adjlist[1]);
        }

        return ans;
    }
};