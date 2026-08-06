class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        // pre[a,b] means have to take b if you want to take a
        // b->a

        vector<vector<int>>adj(num);
        vector<int>indegree(num,0);
        for(auto p:pre){
            int a = p[0];
            int b = p[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int>q;
        for(int i=0;i<num;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);
            for(auto adjnode:adj[node]){
                indegree[adjnode]--;

                if(indegree[adjnode] == 0){
                    q.push(adjnode);
                }
            }
        }

        if(ans.size() == num){
            return ans;
        }
        return {};
    }
};