class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;

        for (char ch : s) {
            if (ch == ' ') {
                words.push_back(word);
                word.clear();
            } else {
                word += ch;
            }
        }
        words.push_back(word);

        if (words.size() != pattern.size())
            return false;

        unordered_map<char, int> mp1;
        unordered_map<string, int> mp2;

        for (int i = 0; i < pattern.size(); i++) {
            if (mp1[pattern[i]] != mp2[words[i]])
                return false;

            mp1[pattern[i]] = i + 1;
            mp2[words[i]] = i + 1;
        }

        return true;
    }
};