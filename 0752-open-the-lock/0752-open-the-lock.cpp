class Solution {
private:
    char next(char c){
        if(c >= '0' && c <= '8'){
            return c+1;
        }
        if(c == '9'){
            return '0';
        }
        return c;
    }

    char prev(char c){
        if(c >= '1' && c<= '9'){
            return c-1;
        }
        if(c == '0'){
            return '9';
        }
        return c;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        unordered_set<string>dead(deadends.begin(),deadends.end());

        if(dead.find(start) != dead.end()){
            return -1;
        }

        if(start == target) return 0;

        unordered_set<string>visited;
        queue<string>q;
        q.push(start);
        visited.insert(start);

        int step = 0;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                string node = q.front();
                q.pop();
                if(node == target) return step;

                // calculating the adjecent nodes
                for(int i=0;i<4;i++){
                    string up = node;
                    char ch = up[i];
                    ch = next(ch);
                    up[i] = ch;

                    if(dead.find(up) == dead.end() && visited.find(up) == visited.end()){
                        q.push(up);
                        visited.insert(up);
                    }
                }
                for(int i=0;i<4;i++){
                    string up = node;
                    char ch = up[i];
                    ch = prev(ch);
                    up[i] = ch;

                    if(dead.find(up) == dead.end() && visited.find(up) == visited.end()){
                        q.push(up);
                        visited.insert(up);
                    }
                }
            }
            step++;
        }

        return -1;
    }
};