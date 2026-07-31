class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mpp;
        int n = word.size();
        int click = 0;

        for(auto letter:word){
            mpp[letter]++;
        }

        vector<int>freq;
        for(auto it:mpp){
            int f = it.second;
            freq.push_back(f);
        }

        sort(freq.begin(),freq.end());
        reverse(freq.begin(),freq.end());

        for(int i=0;i<freq.size();i++){
            if(i<=7){
                click += freq[i];
            }
            else if(i <= 15){
                click += 2 * freq[i];
            }
            else if(i <= 23){
                click += 3*freq[i];
            }
            else{
                click += 4*freq[i];
            }
        }

        return click;
    }
};