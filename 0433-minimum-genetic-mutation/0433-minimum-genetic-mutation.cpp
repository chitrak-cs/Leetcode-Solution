class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene == endGene) return 0;
        unordered_set<string>st(bank.begin(),bank.end());
        if(st.find(endGene) == st.end()){
            // not found
            return -1;
        }

        vector<char>dl={'A','T','G','C'};
        queue<pair<string,int>>q;
        q.push({startGene,0});


        while(!q.empty()){
            string node = q.front().first;
            int step =q.front().second;
            q.pop();

            if(node == endGene) return step;
            
            for(int pos=0;pos<8;pos++){
                char original = node[pos];
                for(int i=0;i<4;i++){
                    node[pos] = dl[i];

                    if(st.find(node) != st.end()){
                        q.push({node,step+1});
                        st.erase(node);
                    }
                }
                node[pos] = original;
            }
        }

        return -1;
    }
};