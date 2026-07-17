class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        vector<int>degree(n);
        vector<int>ans;

        if(n==0){
            return ans;
        }
        else if(n==1){
            ans.push_back(0);
            return ans;
        }

        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(degree[i] == 1){
                // push the leaf elements into the queue
                q.push(i);
            }
        }

        while(n>2 && !q.empty()){
            int size = q.size();
            n -= size;

            while(size--){
                int node = q.front();
                q.pop();

                for(auto adjnode:graph[node]){
                    degree[adjnode]--;
                    if(degree[adjnode] == 1){
                        q.push(adjnode);
                    }
                }
            }
        }

        while(!q.empty()){
            int el = q.front();
            q.pop();
            ans.push_back(el);
        }

        return ans;
    }
};