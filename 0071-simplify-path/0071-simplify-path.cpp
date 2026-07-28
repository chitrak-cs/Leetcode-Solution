class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;   // acts like stack
        stringstream ss(path);
        string token;

        while(getline(ss, token, '/')){
            if(token == "" || token == "."){
                continue; // ignore
            }
            else if(token == ".."){
                if(!st.empty()) st.pop_back();
            }
            else{
                st.push_back(token);
            }
        }

        string ans = "";
        for(auto &dir : st){
            ans += "/" + dir;
        }

        return ans.empty() ? "/" : ans;
    }
};