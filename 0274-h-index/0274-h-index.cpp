class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int>count(1001);
        // this counts the number of papers that have index number of citations
        for(int i=0;i<n;i++){
            int cnt = citations[i];
            count[cnt]++;
        }

        vector<int>suffix(1001);
        suffix[1000] = count[1000];
        for(int i=999;i>=0;i--){
            suffix[i] = suffix[i+1] + count[i];
        }

        int h = 0;
        for(int i=1000;i>=0;i--){
            if(i<=suffix[i]){
                h = i;
                break;
            }
        }

        return h;
    }
};