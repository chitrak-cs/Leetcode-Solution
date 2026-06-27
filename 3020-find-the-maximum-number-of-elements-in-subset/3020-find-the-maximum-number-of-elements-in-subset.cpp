class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long,int> freq;
        for (int x : nums) freq[x]++;

        unordered_set<long long> present;
        for (auto &it : freq){
            present.insert(it.first);
        }

        int answer = 1;

        for (auto it : freq) {
            long long x = it.first;
            int f = it.second;


            if (x == 1) {
                if(f%2==0) f--;
                answer = max(answer, f);
                continue;
            }


            long long r = sqrt(x);
            if (r * r == x && freq[r] >= 2) continue;

            int cnt = 0;
            long long cur = x;

            while (present.count(cur)) {
                if (freq[cur] >= 2) {
                    cnt += 2;
                } else {
                    cnt += 1;
                    break;
                }

                if (cur > 1e9) break;
                cur = cur * cur;
            }

            if (cnt % 2 == 0) cnt--;
            answer = max(answer, cnt);
        }

        return answer;
    }
};