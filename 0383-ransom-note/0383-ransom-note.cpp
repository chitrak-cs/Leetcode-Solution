class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>large;
        unordered_map<char,int>small;

        for(auto r:ransomNote){
            small[r]++;
        }

        for(auto m:magazine){
            large[m]++;
        }

        for(auto it:small){
            char ch = it.first;
            int f = it.second;
            if(large.find(ch) == large.end()) return false;
            int total = large[ch];
            if(f>total) return false;
        }

        return true;
    }
};